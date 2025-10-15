#include "mdsp/qt/mainwindow.h"
#include "qcustomplot.h"

#include <vector>

namespace {

template <typename T>
void fillColorMapData(QCPColorMap *colorMap, const T *data, size_t width, size_t height)
{
    QCPColorMapData *colorMapData = colorMap->data();
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            const double value = static_cast<double>(data[y * width + x]);
            colorMapData->setCell(static_cast<int>(x), static_cast<int>(y), value);
        }
    }
}

template <typename T>
void plotColorMap(QCustomPlot *plot, QCPColorScale *scale, const T *data, size_t width, size_t height)
{
    if (!plot || !scale || !data || width == 0 || height == 0) {
        return;
    }

    plot->clearGraphs();
    plot->clearPlottables();
    plot->clearItems();

    auto *colorMap = new QCPColorMap(plot->xAxis, plot->yAxis);
    colorMap->setColorScale(scale);
    colorMap->setGradient(QCPColorGradient::gpJet);
    colorMap->setInterpolate(true);
    colorMap->data()->setSize(static_cast<int>(width), static_cast<int>(height));

    const double xMax = width > 1 ? static_cast<double>(width - 1) : 0.0;
    const double yMax = height > 1 ? static_cast<double>(height - 1) : 0.0;
    colorMap->data()->setRange(QCPRange(0.0, xMax), QCPRange(0.0, yMax));

    fillColorMapData(colorMap, data, width, height);

    colorMap->rescaleDataRange(true);
    plot->xAxis->setLabel("X Index");
    plot->yAxis->setLabel("Y Index");
    plot->legend->setVisible(false);
    plot->rescaleAxes();
    plot->replot();
}

template <typename T>
bool flatten2D(const std::vector<std::vector<T>> &data, std::vector<T> &flat, size_t &width, size_t &height)
{
    if (data.empty()) {
        return false;
    }

    height = data.size();
    width = data.front().size();
    if (width == 0) {
        return false;
    }

    flat.clear();
    flat.reserve(width * height);
    for (const auto &row : data) {
        if (row.size() != width) {
            return false;
        }
        flat.insert(flat.end(), row.begin(), row.end());
    }
    return true;
}

template <typename T>
bool validateFlatInput(const std::vector<T> &data, size_t width, size_t height)
{
    return width > 0 && height > 0 && data.size() == width * height;
}

} // namespace

namespace mdsp {
namespace qt {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , customPlot(new QCustomPlot(this))
    , colorScale(new QCPColorScale(customPlot))
    , colorScaleMargins(new QCPMarginGroup(customPlot))
{
    customPlot->plotLayout()->addElement(0, 1, colorScale);
    customPlot->plotLayout()->setColumnStretchFactor(0, 1);
    customPlot->plotLayout()->setColumnStretchFactor(1, 0.1);

    colorScale->setType(QCPAxis::atRight);
    colorScale->axis()->setLabel("Value");
    colorScale->setMarginGroup(QCP::msTop | QCP::msBottom, colorScaleMargins);
    customPlot->axisRect()->setMarginGroup(QCP::msTop | QCP::msBottom, colorScaleMargins);
    customPlot->axisRect()->setupFullAxesBox(true);

    setCentralWidget(customPlot);
    resize(800, 600);
    //line_plot(data);
}

MainWindow::~MainWindow() {}

// Complex double vector
void MainWindow::line_plot(const std::vector<std::complex<double>>& data) {
    customPlot->clearGraphs();
    QVector<double> x(data.size()), real(data.size()), imag(data.size());

    for (size_t i = 0; i < data.size(); ++i) {
        x[i] = i;
        real[i] = data[i].real();
        imag[i] = data[i].imag();
    }

    customPlot->addGraph(); // real
    customPlot->graph(0)->setData(x, real);
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setName("Real");

    customPlot->addGraph(); // imag
    customPlot->graph(1)->setData(x, imag);
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setName("Imag");

    customPlot->legend->setVisible(true);
    customPlot->xAxis->setLabel("Index");
    customPlot->yAxis->setLabel("Value");
    customPlot->rescaleAxes();
    customPlot->replot();
}

// Complex float vector
void MainWindow::line_plot(const std::vector<std::complex<float>>& data) {
    customPlot->clearGraphs();
    QVector<double> x(data.size()), real(data.size()), imag(data.size());

    for (size_t i = 0; i < data.size(); ++i) {
        x[i] = i;
        real[i] = data[i].real();
        imag[i] = data[i].imag();
    }

    customPlot->addGraph(); // real
    customPlot->graph(0)->setData(x, real);
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setName("Real");

    customPlot->addGraph(); // imag
    customPlot->graph(1)->setData(x, imag);
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setName("Imag");

    customPlot->legend->setVisible(true);
    customPlot->xAxis->setLabel("Index");
    customPlot->yAxis->setLabel("Value");
    customPlot->rescaleAxes();
    customPlot->replot();
}

// Double vector - single line
void MainWindow::line_plot(const std::vector<double>& data) {
    customPlot->clearGraphs();
    QVector<double> x(data.size()), y(data.size());

    for (size_t i = 0; i < data.size(); ++i) {
        x[i] = i;
        y[i] = data[i];
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->setPen(QPen(Qt::darkGreen));
    customPlot->graph(0)->setName("Data");

    customPlot->legend->setVisible(true);
    customPlot->xAxis->setLabel("Index");
    customPlot->yAxis->setLabel("Value");
    customPlot->rescaleAxes();
    customPlot->replot();
}

// Float vector - single line
void MainWindow::line_plot(const std::vector<float>& data) {
    customPlot->clearGraphs();
    QVector<double> x(data.size()), y(data.size());

    for (size_t i = 0; i < data.size(); ++i) {
        x[i] = i;
        y[i] = data[i];
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->setPen(QPen(Qt::darkMagenta));
    customPlot->graph(0)->setName("Data");

    customPlot->legend->setVisible(true);
    customPlot->xAxis->setLabel("Index");
    customPlot->yAxis->setLabel("Value");
    customPlot->rescaleAxes();
    customPlot->replot();
}

// Complex double pointer
void MainWindow::line_plot(const std::complex<double>* data, size_t size) {
    customPlot->clearGraphs();
    QVector<double> x(size), real(size), imag(size);

    for (size_t i = 0; i < size; ++i) {
        x[i] = i;
        real[i] = data[i].real();
        imag[i] = data[i].imag();
    }

    customPlot->addGraph(); // real
    customPlot->graph(0)->setData(x, real);
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setName("Real");

    customPlot->addGraph(); // imag
    customPlot->graph(1)->setData(x, imag);
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setName("Imag");

    customPlot->legend->setVisible(true);
    customPlot->xAxis->setLabel("Index");
    customPlot->yAxis->setLabel("Value");
    customPlot->rescaleAxes();
    customPlot->replot();
}

// Complex float pointer
void MainWindow::line_plot(const std::complex<float>* data, size_t size) {
    customPlot->clearGraphs();
    QVector<double> x(size), real(size), imag(size);

    for (size_t i = 0; i < size; ++i) {
        x[i] = i;
        real[i] = data[i].real();
        imag[i] = data[i].imag();
    }

    customPlot->addGraph(); // real
    customPlot->graph(0)->setData(x, real);
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setName("Real");

    customPlot->addGraph(); // imag
    customPlot->graph(1)->setData(x, imag);
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setName("Imag");

    customPlot->legend->setVisible(true);
    customPlot->xAxis->setLabel("Index");
    customPlot->yAxis->setLabel("Value");
    customPlot->rescaleAxes();
    customPlot->replot();
}

// Double pointer - single line
void MainWindow::line_plot(const double* data, size_t size) {
    customPlot->clearGraphs();
    QVector<double> x(size), y(size);

    for (size_t i = 0; i < size; ++i) {
        x[i] = i;
        y[i] = data[i];
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->setPen(QPen(Qt::darkGreen));
    customPlot->graph(0)->setName("Data");

    customPlot->legend->setVisible(true);
    customPlot->xAxis->setLabel("Index");
    customPlot->yAxis->setLabel("Value");
    customPlot->rescaleAxes();
    customPlot->replot();
}

// Float pointer - single line
void MainWindow::line_plot(const float* data, size_t size) {
    customPlot->clearGraphs();
    QVector<double> x(size), y(size);

    for (size_t i = 0; i < size; ++i) {
        x[i] = i;
        y[i] = data[i];
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->setPen(QPen(Qt::darkMagenta));
    customPlot->graph(0)->setName("Data");

    customPlot->legend->setVisible(true);
    customPlot->xAxis->setLabel("Index");
    customPlot->yAxis->setLabel("Value");
    customPlot->rescaleAxes();
    customPlot->replot();
}

void MainWindow::colormap_plot(const std::vector<std::vector<double>>& data) {
    std::vector<double> flattened;
    size_t width = 0, height = 0;
    if (!flatten2D(data, flattened, width, height)) {
        return;
    }
    colormap_plot(flattened, width, height);
}

void MainWindow::colormap_plot(const std::vector<std::vector<float>>& data) {
    std::vector<float> flattened;
    size_t width = 0, height = 0;
    if (!flatten2D(data, flattened, width, height)) {
        return;
    }
    colormap_plot(flattened, width, height);
}

void MainWindow::colormap_plot(const std::vector<double>& data, size_t width, size_t height) {
    if (!validateFlatInput(data, width, height)) {
        return;
    }
    colormap_plot(data.data(), width, height);
}

void MainWindow::colormap_plot(const std::vector<float>& data, size_t width, size_t height) {
    if (!validateFlatInput(data, width, height)) {
        return;
    }
    colormap_plot(data.data(), width, height);
}

void MainWindow::colormap_plot(const double* data, size_t width, size_t height) {
    plotColorMap(customPlot, colorScale, data, width, height);
}

void MainWindow::colormap_plot(const float* data, size_t width, size_t height) {
    plotColorMap(customPlot, colorScale, data, width, height);
}

} // namespace qt
} // namespace mdsp

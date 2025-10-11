#include "mdsp/qt/mainwindow.h"
#include "qcustomplot.h"

namespace mdsp {
namespace qt {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    customPlot = new QCustomPlot(this);
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

} // namespace qt
} // namespace mdsp

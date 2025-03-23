#include "mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(const std::vector<std::complex<double>>& data, QWidget *parent)
    : QMainWindow(parent)
{
    customPlot = new QCustomPlot(this);
    setCentralWidget(customPlot);
    resize(800, 600);
    setupPlot(data);
}

MainWindow::~MainWindow() {}

void MainWindow::setupPlot(const std::vector<std::complex<double>>& data) {
    QVector<double> x(data.size()), real(data.size()), imag(data.size());

    for (int i = 0; i < data.size(); ++i) {
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <complex>

class QCustomPlot;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const std::vector<std::complex<double>>& data, QWidget *parent = nullptr);
    ~MainWindow();

private:
    QCustomPlot* customPlot;
    void setupPlot(const std::vector<std::complex<double>>& data);
};

#endif // MAINWINDOW_H

#ifndef MDSP_QT_MAINWINDOW_H
#define MDSP_QT_MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <complex>

class QCustomPlot;

namespace mdsp {
namespace qt {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    QCustomPlot* customPlot;
    
    // Vector-based line_plot methods
    void line_plot(const std::vector<std::complex<double>>& data);
    void line_plot(const std::vector<std::complex<float>>& data);
    void line_plot(const std::vector<double>& data);
    void line_plot(const std::vector<float>& data);
    
    // Pointer-based line_plot methods with size
    void line_plot(const std::complex<double>* data, size_t size);
    void line_plot(const std::complex<float>* data, size_t size);
    void line_plot(const double* data, size_t size);
    void line_plot(const float* data, size_t size);

private:

};

} // namespace qt
} // namespace mdsp

#endif // MDSP_QT_MAINWINDOW_H

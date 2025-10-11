#include "mdsp/qt/plot_qt.h"
#include "mdsp/qt/mainwindow.h"

#include <QApplication>

namespace mdsp {
namespace qt {

// Vector-based implementations
void line_plot(const std::vector<std::complex<double>>& data) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow();
    window->line_plot(data);
    window->show();

    app.exec();
}

void line_plot(const std::vector<std::complex<float>>& data) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow();
    window->line_plot(data);
    window->show();

    app.exec();
}

void line_plot(const std::vector<double>& data) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow();
    window->line_plot(data);
    window->show();

    app.exec();
}

void line_plot(const std::vector<float>& data) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow();
    window->line_plot(data);
    window->show();

    app.exec();
}

// Pointer-based implementations
void line_plot(const std::complex<double>* data, size_t size) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow();
    window->line_plot(data, size);
    window->show();

    app.exec();
}

void line_plot(const std::complex<float>* data, size_t size) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow();
    window->line_plot(data, size);
    window->show();

    app.exec();
}

void line_plot(const double* data, size_t size) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow();
    window->line_plot(data, size);
    window->show();

    app.exec();
}

void line_plot(const float* data, size_t size) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow();
    window->line_plot(data, size);
    window->show();

    app.exec();
}

} // namespace qt
} // namespace mdsp
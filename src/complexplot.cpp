#include "complexplot.h"
#include "mainwindow.h"

#include <QApplication>

namespace ComplexPlotLib {

void plotComplexData(const std::vector<std::complex<double>>& data) {
    int argc = 0;
    char* argv[] = { nullptr };
    QApplication app(argc, argv);

    MainWindow* window = new MainWindow(data);
    window->show();

    app.exec();
}

}

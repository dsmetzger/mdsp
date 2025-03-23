#include "complexplotlib.h"
#include <complex>
#include <vector>

int main() {
    std::vector<std::complex<double>> data;
    for (int i = 0; i < 100; ++i) {
        data.emplace_back(std::cos(i * 0.1), std::sin(i * 0.1));
    }

    ComplexPlotLib::plotComplexData(data);
    return 0;
}

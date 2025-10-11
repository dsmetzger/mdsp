#include "mdsp/qt/plot_qt.h"
#include <complex>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "=== MDSP Qt Line Plot Demo ===" << std::endl;
    std::cout << "Demonstrating all 8 line_plot function variants" << std::endl;
    std::cout << "Each plot will display for a few seconds, then close automatically." << std::endl;
    std::cout << std::endl;

    const size_t size = 50;

    // 1. Vector<complex<double>>
    std::cout << "1. Plotting std::vector<std::complex<double>>..." << std::endl;
    std::vector<std::complex<double>> complex_double_vec;
    for (size_t i = 0; i < size; ++i) {
        complex_double_vec.emplace_back(std::cos(i * 0.2), std::sin(i * 0.15));
    }
    mdsp::qt::line_plot(complex_double_vec);

    // 2. Vector<complex<float>>
    std::cout << "2. Plotting std::vector<std::complex<float>>..." << std::endl;
    std::vector<std::complex<float>> complex_float_vec;
    for (size_t i = 0; i < size; ++i) {
        complex_float_vec.emplace_back(std::cos(i * 0.3f), std::sin(i * 0.25f));
    }
    mdsp::qt::line_plot(complex_float_vec);

    // 3. Vector<double>
    std::cout << "3. Plotting std::vector<double>..." << std::endl;
    std::vector<double> double_vec;
    for (size_t i = 0; i < size; ++i) {
        double_vec.push_back(std::cos(i * 0.2));
    }
    mdsp::qt::line_plot(double_vec);

    // 4. Vector<float>
    std::cout << "4. Plotting std::vector<float>..." << std::endl;
    std::vector<float> float_vec;
    for (size_t i = 0; i < size; ++i) {
        float_vec.push_back(std::cos(i * 0.2));
    }
    mdsp::qt::line_plot(float_vec);

    // 5. Pointer to complex<double>
    std::cout << "5. Plotting complex<double> pointer..." << std::endl;
    std::complex<double>* complex_double_ptr = new std::complex<double>[size];
    for (size_t i = 0; i < size; ++i) {
        complex_double_ptr[i] = std::complex<double>(
            std::sin(i * 0.25) , std::cos(i * 0.25)
        );
    }
    mdsp::qt::line_plot(complex_double_ptr, size);
    delete[] complex_double_ptr;

    // 6. Pointer to complex<float>
    std::cout << "6. Plotting complex<float> pointer..." << std::endl;
    std::complex<float>* complex_float_ptr = new std::complex<float>[size];
    for (size_t i = 0; i < size; ++i) {
        complex_float_ptr[i] = std::complex<float>(
            std::sin(i * 0.28f), std::cos(i * 0.28f)
        );
    }
    mdsp::qt::line_plot(complex_float_ptr, size);
    delete[] complex_float_ptr;

    // 7. Pointer to double
    std::cout << "7. Plotting double pointer..." << std::endl;
    double* double_ptr = new double[size];
    for (size_t i = 0; i < size; ++i) {
        double_ptr[i] = std::cos(i * 0.28f);
    }
    mdsp::qt::line_plot(double_ptr, size);
    delete[] double_ptr;

    // 8. Pointer to float
    std::cout << "8. Plotting float pointer..." << std::endl;
    float* float_ptr = new float[size];
    for (size_t i = 0; i < size; ++i) {
        float_ptr[i] = std::cos(i * 0.28f);
    }
    mdsp::qt::line_plot(float_ptr, size);
    delete[] float_ptr;

    std::cout << "Demo completed!" << std::endl;
    return 0;
}
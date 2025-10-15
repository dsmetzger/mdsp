#include "mdsp/qt/plot_qt.h"
#include <complex>
#include <vector>
#include <cmath>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "=== MDSP Qt Line Plot Demo ===" << std::endl;
    std::cout << "Demonstrating all 8 line_plot function variants" << std::endl;
    std::cout << "Each plot will display for a few seconds, then close automatically." << std::endl;
    std::cout << std::endl;

    const size_t size = 512;

    // 1. Vector<complex<float>>
    std::cout << "2. Plotting std::vector<std::complex<float>>..." << std::endl;
    std::vector<std::complex<float>> complex_float_vec;
    for (size_t i = 0; i < size; ++i) {
        complex_float_vec.emplace_back(std::cos(i * 0.3f), std::sin(i * 0.25f));
    }
    mdsp::qt::line_plot(complex_float_vec);

    // Colormap example
    std::cout << "3. Plotting colormap from std::vector<float>..." << std::endl;
    const size_t width = 64;
    const size_t height = 64;
    std::vector<float> heatmap(width * height);
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            const float cx = static_cast<float>(x) / static_cast<float>(width);
            const float cy = static_cast<float>(y) / static_cast<float>(height);
            heatmap[y * width + x] = std::sin(8.0f * static_cast<float>(M_PI) * cx) * std::cos(8.0f * static_cast<float>(M_PI) * cy);
        }
    }
    mdsp::qt::colormap_plot(heatmap, width, height);

    std::cout << "Demo completed!" << std::endl;
    return 0;
}

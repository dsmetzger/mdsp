#ifndef MDSP_QT_PLOT_QT_H
#define MDSP_QT_PLOT_QT_H

#include <cstddef>
#include <complex>
#include <vector>

#ifdef _WIN32
  #ifdef MDSP_PLOT_QT_LIB_LIBRARY
    #define MDSP_PLOT_QT_LIB_EXPORT __declspec(dllexport)
  #else
    #define MDSP_PLOT_QT_LIB_EXPORT __declspec(dllimport)
  #endif
#else
  #define MDSP_PLOT_QT_LIB_EXPORT
#endif

namespace mdsp {
namespace qt {

// Vector-based line_plot functions
MDSP_PLOT_QT_LIB_EXPORT void line_plot(const std::vector<std::complex<double>>& data);
MDSP_PLOT_QT_LIB_EXPORT void line_plot(const std::vector<std::complex<float>>& data);
MDSP_PLOT_QT_LIB_EXPORT void line_plot(const std::vector<double>& data);
MDSP_PLOT_QT_LIB_EXPORT void line_plot(const std::vector<float>& data);

// Pointer-based line_plot functions with size
MDSP_PLOT_QT_LIB_EXPORT void line_plot(const std::complex<double>* data, size_t size);
MDSP_PLOT_QT_LIB_EXPORT void line_plot(const std::complex<float>* data, size_t size);
MDSP_PLOT_QT_LIB_EXPORT void line_plot(const double* data, size_t size);
MDSP_PLOT_QT_LIB_EXPORT void line_plot(const float* data, size_t size);

// Colormap plotting helpers
MDSP_PLOT_QT_LIB_EXPORT void colormap_plot(const std::vector<std::vector<double>>& data);
MDSP_PLOT_QT_LIB_EXPORT void colormap_plot(const std::vector<std::vector<float>>& data);
MDSP_PLOT_QT_LIB_EXPORT void colormap_plot(const std::vector<double>& data, size_t width, size_t height);
MDSP_PLOT_QT_LIB_EXPORT void colormap_plot(const std::vector<float>& data, size_t width, size_t height);
MDSP_PLOT_QT_LIB_EXPORT void colormap_plot(const double* data, size_t width, size_t height);
MDSP_PLOT_QT_LIB_EXPORT void colormap_plot(const float* data, size_t width, size_t height);

} // namespace qt
} // namespace mdsp

#endif // MDSP_QT_PLOT_QT_H

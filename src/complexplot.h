#ifndef COMPLEXPLOTLIB_H
#define COMPLEXPLOTLIB_H

#include <complex>
#include <vector>

#ifdef _WIN32
  #ifdef COMPLEXPLOTLIB_LIBRARY
    #define COMPLEXPLOTLIB_EXPORT __declspec(dllexport)
  #else
    #define COMPLEXPLOTLIB_EXPORT __declspec(dllimport)
  #endif
#else
  #define COMPLEXPLOTLIB_EXPORT
#endif

namespace ComplexPlotLib {

COMPLEXPLOTLIB_EXPORT void plotComplexData(const std::vector<std::complex<double>>& data);

}

#endif // COMPLEXPLOTLIB_H

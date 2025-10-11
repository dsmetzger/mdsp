# Intro

Basic digital signal plotting libary in c++.

Basic digital signal processing functions.


# License

## Dual Licensing Notice

This project has a **dual licensing structure**:

### Core Library (MIT License)
The core mdsp_plot_lib code (excluding QCustomPlot) is licensed under the **MIT License**.
- Copyright (c) 2025 Dylan Metzger
- Free for commercial and non-commercial use
- See `LICENSE` file for full MIT license text

### QCustomPlot Dependency (GPL v3)
This project currently includes **QCustomPlot** (in `extern/qcustomplot/`) which is licensed under **GPL v3**.

**⚠️ IMPORTANT**: When using this library with QCustomPlot included, the entire work becomes subject to **GPL v3** licensing terms.

### Commercial Use Options

1. **GPL v3 Compliance**: Use the library as-is under GPL v3 terms
2. **MIT License**: Remove QCustomPlot dependency and replace with MIT-compatible plotting library

The intention is to eventually replace QCustomPlot with an MIT-compatible alternative for full commercial freedom.

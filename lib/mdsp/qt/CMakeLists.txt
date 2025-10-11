# Qt-specific plotting library
cmake_minimum_required(VERSION 3.16)

# Find Qt packages
find_package(Qt5 REQUIRED COMPONENTS Core Widgets PrintSupport)

# Enable Qt MOC, UIC, and RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Define Qt library source files
set(QT_SOURCES
    plot_qt.cpp
    mainwindow.cpp
    ${PROJECT_SOURCE_DIR}/extern/qcustomplot/qcustomplot.cpp
)

# Define Qt library header files
set(QT_HEADERS
    ${PROJECT_SOURCE_DIR}/inc/mdsp/qt/plot_qt.h
    ${PROJECT_SOURCE_DIR}/inc/mdsp/qt/mainwindow.h
    ${PROJECT_SOURCE_DIR}/extern/qcustomplot/qcustomplot.h
)

# Create Qt-specific shared library
add_library(mdsp_plot_qt_lib SHARED ${QT_SOURCES} ${QT_HEADERS})

# Add compile definitions
target_compile_definitions(mdsp_plot_qt_lib PRIVATE MDSP_PLOT_QT_LIB_LIBRARY)

# Link Qt libraries
target_link_libraries(mdsp_plot_qt_lib
    Qt5::Core
    Qt5::Widgets
    Qt5::PrintSupport
)

# Set include directories
target_include_directories(mdsp_plot_qt_lib PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/extern/qcustomplot>
    $<INSTALL_INTERFACE:include>
)

# Set library properties
set_target_properties(mdsp_plot_qt_lib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# Installation rules
install(TARGETS mdsp_plot_qt_lib
    EXPORT mdsp_plot_qt_lib_targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(FILES ${QT_HEADERS}
    DESTINATION include/mdsp/qt
)
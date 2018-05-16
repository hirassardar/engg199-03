
# Specify the minimum version of CMake that can be used
cmake_minimum_required(VERSION 2.8)

# Name the project
PROJECT(assignment)

# Say where the libraries are located
set(VTK_DIR "C:/libs/vtk/bin/")
set(ITK_DIR "C:/libs/itk/bin/")
set(CMAKE_PREFIX_PATH "C:/libs/qt/5.7/msvc2015_64/")
set(OpenCV_DIR "C:/libs/opencv/")

# Find and include VTK
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

# Find and include ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

# Find and include Qt
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED QUIET)

# Find and include OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Collect and include all of our source files (.h and .cxx files)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
file(GLOB QT_WRAP *.h)
file(GLOB CXX_FILES *.cxx)

# We are creating an executable project, and including the source files into it
add_executable(assignment ${CXX_FILES} ${QT_WRAP})

# Tell Qt which modules to use (there are others, like Test and Sql for example)
qt5_use_modules(assignment Core Gui Widgets winextras)

# Set the startup project in Visual Studio to be our project (rather than the extra stuff CMake builds)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT assignment)

# Tell the project which libraries to link (Qt does this automatically)
target_link_libraries(assignment ${VTK_LIBRARIES})
target_link_libraries(assignment ${ITK_LIBRARIES})
target_link_libraries(assignment ${OpenCV_LIBS})

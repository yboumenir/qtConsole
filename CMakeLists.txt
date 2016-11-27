project(qt_keyboard)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fexceptions -fnon-call-exceptions ")
# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Find the QtWidgets library
find_package(Qt5Core)
find_package(Qt5Gui)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/console_reader.h
        ${CMAKE_CURRENT_SOURCE_DIR}/console_reader.cpp)
add_library(keys ${SRC})
qt5_use_modules(keys Core)

add_executable(main main.cpp ${SRC})
target_link_libraries(main keys)


cmake_minimum_required(VERSION 3.1.0)
set(PROJECT FutureWatcher)

project(${PROJECT})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Concurrent REQUIRED)

add_executable(${PROJECT} FutureWatcherProgressDialog.cpp form.cpp form.ui)

target_link_libraries(${PROJECT} Qt5::Widgets Qt5::Concurrent)

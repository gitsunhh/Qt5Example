cmake_minimum_required(VERSION 3.1.0)
set(PROJECT log)

project(${PROJECT})

set(CMAKE_AUTOMOC ON) # for meta object compiler

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

add_executable(${PROJECT} main.cpp LogManager.cpp)

target_link_libraries(${PROJECT} Qt5::Widgets Qt5::Core)

#Release版本默认不包含这些信息：文件名、函数名、行数
#target_compile_definitions(${PROJECT} PRIVATE QT_MESSAGELOGCONTEXT)

#定义以下的宏，可以屏蔽相应的日志输出
#target_compile_definitions(${PROJECT} PRIVATE QT_NO_WARNING_OUTPUT)
#target_compile_definitions(${PROJECT} PRIVATE QT_NO_DEBUG_OUTPUT)
#target_compile_definitions(${PROJECT} PRIVATE QT_NO_INFO_OUTPUT)
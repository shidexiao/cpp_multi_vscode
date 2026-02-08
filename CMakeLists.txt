# 指定CMake最低版本
cmake_minimum_required(VERSION 3.10)
# 项目名称
project(cpp_multi_file)
# 指定C++标准版本（C++11兼容所有编译器）
set(CMAKE_CXX_STANDARD 11)
# 让编译器能找到头文件（指定include目录）
include_directories(include)
# 收集所有源文件（也可以手动列：src/main.cpp src/calculator.cpp）
file(GLOB SOURCES "src/*.cpp")
# 生成可执行文件（目标名：app，源文件：SOURCES）
add_executable(app ${SOURCES})
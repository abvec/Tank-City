cmake_minimum_required(VERSION 3.24.1)

project(TankCity)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_executable(${PROJECT_NAME} src/vector.cpp src/plane.cpp src/main.cpp)

cmake_minimum_required(VERSION 3.24.1)

project(TankCity)

set(EXECUTABLE_OUTPUT_PATH "bin")

add_executable(
    ${PROJECT_NAME}
    src/vector.cpp
    src/plane.cpp
    src/main.cpp
)

INCLUDE_DIRECTORIES(../include)

TARGET_LINK_LIBRARIES(TankCity ../SDL2 ../SDL2main opengl32)

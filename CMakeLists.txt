cmake_minimum_required(VERSION 3.14)

project(Dispresim)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

file(GLOB SRC src/*.cpp)

add_executable(Dispresim ${SRC})

target_link_libraries(Dispresim PUBLIC glfw GLAD)
target_include_directories(Dispresim PUBLIC glfw GLAD)
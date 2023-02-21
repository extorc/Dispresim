cmake_minimum_required(VERSION 3.14)

project(Dispresim)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_executable(Dispresim src/main.c)

target_link_libraries(Dispresim PUBLIC glfw GLAD)
target_include_directories(Dispresim PUBLIC glfw GLAD)
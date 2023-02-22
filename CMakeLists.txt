cmake_minimum_required(VERSION 3.14)

project(Dispresim)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/glm)
file(GLOB SRC src/*.cpp)

add_executable(Dispresim ${SRC})

target_link_libraries(Dispresim PUBLIC glfw GLAD glm)
target_include_directories(Dispresim PUBLIC glfw GLAD glm)
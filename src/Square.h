#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Square{
  public:
  unsigned int vao;
  Square(float* positions);
};
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Square{
  public:
  unsigned int vao;
  Square();
  void render();
  float positions[8] = {
    0.0f, 0.5f,
    0.5f, 0.0f,
    0.5f, 0.5f,
    0.0f, 0.0f
  };
  unsigned int indices[6] = {
    0, 1, 2, 0, 1, 3
  }; 
};
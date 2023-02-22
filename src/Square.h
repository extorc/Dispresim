#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Color.h"

class Square{
  public:
  unsigned int vao;
  Color col;
  float positions[8] = {
    0.0f, 5.0f,
    5.0f, 0.0f,
    5.0f, 5.0f,
    0.0f, 0.0f
  };
  unsigned int indices[6] = {
    0, 1, 2, 0, 1, 3
  }; 

  glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(0,0,0));
  Square();
  void render();
};
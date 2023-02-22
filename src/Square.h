#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Color.h"
#include "glm/gtc/matrix_access.hpp"

struct Square{
  unsigned int vao;
  Color col;
  glm::mat4 transform;
  glm::vec2 velocity;
  glm::vec2 acceleration;
};

Square loadSquare();
glm::vec2 getPosition(Square square);
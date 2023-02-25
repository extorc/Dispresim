#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Color.h"
#include "glm/gtc/matrix_access.hpp"
#include <stdlib.h>

float rand_FloatRange(float a, float b);

struct Square{
  unsigned int vao;
  Color col;
  glm::mat4 transform;
  glm::vec2 velocity;
  int infectionLifetime = 0;
  bool immune = false;
  int immunityLifetime = 0;
};

Square loadSquare();
glm::vec2 getPosition(Square square);
void collideWithWall(Square& square);
float getDistance(Square square, Square square2);
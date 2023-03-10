#include "Square.h"

float rand_FloatRange(float a, float b){
  float r = ((b - a) * ((float)rand() / RAND_MAX)) + a;
  return r;
}

Square loadSquare(){
  float positions[8] = {
    0.0f, 5.0f,
    5.0f, 0.0f,
    5.0f, 5.0f,
    0.0f, 0.0f
  };
  unsigned int indices[6] = {
    0, 1, 2, 0, 1, 3
  }; 
  unsigned int vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glEnableVertexAttribArray(0);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
  
  unsigned int ibo;
  glGenBuffers(1, &ibo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
  
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2*sizeof(float), 0);

  return Square{vao, Color{0.5f, 0.5f, 0.5f, 1.0f}, glm::translate(glm::mat4(1.0f), glm::vec3(0,0,0)), glm::vec2(0)};
}

glm::vec2 getPosition(Square square){
  return glm::vec2(glm::row(square.transform, 0)[3],glm::row(square.transform, 1)[3]);
}

float getDistance(Square square, Square square2){
  return glm::length(getPosition(square)-getPosition(square2));
}

void collideWithWall(Square& square){
  glm::vec2 position = getPosition(square);
  if(position.x > 320){
    square.velocity = glm::vec2(-square.velocity.x, square.velocity.y);
  }else if(position.x < -320){
    square.velocity = glm::vec2(-square.velocity.x, square.velocity.y);
  }else if(position.y > 180){
    square.velocity = glm::vec2(square.velocity.x, -square.velocity.y);
  }else if(position.y < -180){
    square.velocity = glm::vec2(square.velocity.x, -square.velocity.y);
  }
}
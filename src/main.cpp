#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc.h>
#include "OpenglAPI.h"
#include "Square.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

int main(void){
  OpenglAPI openglAPI;
  openglAPI.initializeGL(); 

  Square square = loadSquare(); 
  square.velocity = glm::vec2(rand_FloatRange(0.01f, 0.1f), rand_FloatRange(0.01f, 0.1f));
  Square square2 = loadSquare(); 
  square2.velocity = glm::vec2(rand_FloatRange(0.01f, 0.1f), rand_FloatRange(0.01f, 0.1f));
  unsigned int program = openglAPI.bindShader();
  SetColor(program, square.col);

  while(!glfwWindowShouldClose(openglAPI.window)){
    glClear(GL_COLOR_BUFFER_BIT);
    collideWithWall(square); 
    openglAPI.render(square); 
    collideWithWall(square2); 
    openglAPI.render(square2);
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
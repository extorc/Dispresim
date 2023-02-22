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
  square.velocity = glm::vec2(0.05f, 0.05f);
  
  unsigned int program = openglAPI.bindShader();
  SetColor(program, square.col);

  while(!glfwWindowShouldClose(openglAPI.window)){
    collideWithWall(square); 
    openglAPI.render(square); 
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
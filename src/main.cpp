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

  unsigned int program = openglAPI.bindShader();
  glUseProgram(program);

  SetColor(program, square.col);

  while(!glfwWindowShouldClose(openglAPI.window)){
    square.transform = glm::translate(square.transform, glm::vec3(.01f, 0, 0));
    openglAPI.render(square); 
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
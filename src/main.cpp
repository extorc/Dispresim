#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc.h>
#include "OpenglAPI.h"
#include "Square.h"

int main(void){
  OpenglAPI openglAPI;
  openglAPI.initializeGL(); 

  Square square;  
  
  unsigned int program = OpenglAPI::bindShader();
  glUseProgram(program);

  glUniform4f(glGetUniformLocation(program, "uColor"), 1.0f, 1.0f, 0.0f, 1.0f);

  while(!glfwWindowShouldClose(openglAPI.window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glUniform4f(glGetUniformLocation(program, "color"),1.0f, 1.0f, 0.0f, 1.0f);
    square.render(); 
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
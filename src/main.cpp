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

  Square square;  
  square.col = {1.0f, 1.0f, 0.7f, 1.0f};

  unsigned int program = OpenglAPI::bindShader();
  glUseProgram(program);

  SetColor(program, square.col);
  glm::mat4 proj = glm::ortho(-16.0f, 16.0f, 9.0f, -9.0f,-1.0f, 1.0f);
  glUniformMatrix4fv(glGetUniformLocation(program, "uProj"),1, GL_FALSE, &proj[0][0]);

  while(!glfwWindowShouldClose(openglAPI.window)){
    glClear(GL_COLOR_BUFFER_BIT);
    square.render(); 
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
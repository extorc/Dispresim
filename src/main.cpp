#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc.h>
#include "OpenglAPI.h"
#include "Square.h"

int main(void){
  OpenglAPI openglAPI;
  openglAPI.initializeGL(); 

  float positions[] = {
    0.0f, 0.5f,
    0.5f, 0.0f,
    0.5f, 0.5f,
    0.0f, 0.0f
  };
  unsigned int indices[] = {
    0, 1, 2, 0, 1, 3
  }; 
  
  Square square(positions, indices);  
  
  unsigned int program = OpenglAPI::bindShader();
  glUseProgram(program);

  while(!glfwWindowShouldClose(openglAPI.window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(square.vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
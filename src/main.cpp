#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc.h>
#include "OpenglAPI.h"
#include "shaders.h"
#include "Square.h"

int main(void){
  OpenglAPI openglAPI;
  openglAPI.initializeGL(); 

  float positions[6] = {
    0.0f, 0.5f,
    0.5f, 0.0f,
    0.5f, 0.5f   
  };
  float positions2[6] = {
    0.0f, 0.0f,
    0.5f, 0.0f,
    0.0f, 0.5f   
  };
  
  Square square(positions);  
  Square square2(positions2);
  unsigned int program = glCreateProgram();

  unsigned int vs = OpenglAPI::createShader(GL_VERTEX_SHADER, vSource);
  unsigned int fs = OpenglAPI::createShader(GL_FRAGMENT_SHADER, fSource);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  glUseProgram(program);
  while(!glfwWindowShouldClose(openglAPI.window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(square.vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(square2.vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
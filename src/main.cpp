#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc.h>
#include "OpenglAPI.h"
#include "shaders.h"

int main(void){
  OpenglAPI openglAPI;
  openglAPI.initializeGL(); 

  float positions[6] = {
    0.0f, 0.5f,
    0.5f, 0.0f,
    0.5f, 0.5f   
  };

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2*sizeof(float), 0);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

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
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
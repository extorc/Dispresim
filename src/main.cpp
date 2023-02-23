#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc.h>
#include "OpenglAPI.h"
#include "Square.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "vector"

int main(void){
  OpenglAPI openglAPI;
  openglAPI.initializeGL(); 

  std::vector<Square> list;
  for(int i = 0; i < 100; i++){
    list.push_back(loadSquare()); 
    list.at(i).velocity = glm::vec2(rand_FloatRange(0.01f, 0.1f), rand_FloatRange(0.01f, 0.1f));
  }

  unsigned int program = openglAPI.bindShader();
  SetColor(program, list.at(0).col);

  while(!glfwWindowShouldClose(openglAPI.window)){
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = 0; i < 100; i++){
      collideWithWall(list.at(i));
      openglAPI.render(list.at(i));
    }
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
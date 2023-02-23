#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc.h>
#include "OpenglAPI.h"
#include "Square.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "vector"

int main(int argc, char* argv[]){
  OpenglAPI openglAPI;
  openglAPI.initializeGL(); 

  std::vector<Square> list;
  for(int i = 0; i < 100; i++){
    list.push_back(loadSquare());
    list.at(i).transform = glm::translate(list.at(i).transform, glm::vec3(rand_FloatRange(-320, 320), rand_FloatRange(-180, 180), 0)); 
    list.at(i).velocity = glm::vec2(rand_FloatRange(-0.2f, 0.2f), rand_FloatRange(-0.2f, 0.2f));
  }

  unsigned int program = openglAPI.bindShader();
  SetColor(program, list.at(0).col);

  while(!glfwWindowShouldClose(openglAPI.window)){
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = 0; i < 100; i++){
      collideWithWall(list.at(i));
      openglAPI.render(list.at(i));
    }
    std::cout<<"F"<<std::endl;
    for(int i = 0; i < 100; i++){
      for(int j = 0; j < 100; j++){
        if(j != i){
          float d = getDistance(list.at(j), list.at(i));
          if(d < 5){
            std::cout<<d<<std::endl;
          }
        }
      }
    }
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "OpenglAPI.h"
#include "Square.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "vector"

#define IsRed(t) (true?t.col.r == 1:false)
#define Grey Color{0.5f, 0.5f, 0.5f, 1.0f}
int infectionCount = 1;

void healPerson(std::vector<Square>& list, int i, int infectionLifetime){
  if(list.at(i).infectionLifetime > infectionLifetime){ 
    list.at(i).col = Grey;
    list.at(i).infectionLifetime = 0;
    infectionCount --;
    list.at(i).immune = true;
    list.at(i).col = Color{0,1,0,1};
  }
}

void infectPerson(std::vector<Square>& list, int i, int j){
  if(!IsRed(list.at(j)) && !list.at(j).immune){
    float d = getDistance(list.at(j), list.at(i));
    if(d < 5){
      list.at(j).col = Color{1, 0, 0, 1};
      infectionCount ++;
    }
  }
}

int main(int argc, char* argv[]){
  OpenglAPI openglAPI;
  openglAPI.initializeGL(); 

  std::vector<Square> list;
  for(int i = 0; i < 200; i++){
    list.push_back(loadSquare());
    if(i == 10){
      list.at(i).col = Color{1, 0, 0, 1};                                      //Infect one person
    }
    list.at(i).transform = glm::translate(list.at(i).transform, glm::vec3(rand_FloatRange(-320, 320), rand_FloatRange(-180, 180), 0)); 
    list.at(i).velocity = glm::vec2(rand_FloatRange(-0.2f, 0.2f), rand_FloatRange(-0.2f, 0.2f));
  }

  unsigned int program = openglAPI.bindShader();

  while(!glfwWindowShouldClose(openglAPI.window)){
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = 0; i < 200; i++){
      collideWithWall(list.at(i));
      openglAPI.render(list.at(i));
    }
    for(int i = 0; i < 200; i++){
      if(IsRed(list.at(i))){                                                   //Iterate on all infected persons
        list.at(i).infectionLifetime++;
        healPerson(list, i, 1500);                                             //Heal if infected for more than x cycles
        for(int j = 0; j < 200; j++){                                          //Iterate collision with every non infected person
          infectPerson(list, i, j);
        }
      }
      if(list.at(i).immune){
        list.at(i).immunityLifetime++;
      }
      if(list.at(i).immunityLifetime > 700){
        list.at(i).immunityLifetime = 0;
        list.at(i).immune = false;
        list.at(i).col = Grey;
      }
    }
    std::cout<<infectionCount<<std::endl;
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(openglAPI.window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

#include "OpenglAPI.h"

unsigned int OpenglAPI::createShader(unsigned int type, const char* src){
  unsigned int shader = glCreateShader(type);
  glShaderSource(shader, 1,&src, NULL);
  glCompileShader(shader);
  return shader;
}

void OpenglAPI::initializeGL(){
  

  if(!glfwInit()){
    std::cout<<"Failed to initialize GLFW"<<std::endl;
  }

  window = glfwCreateWindow(640, 640, "Dispresim", NULL, NULL);
  if(!window){
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout<<"Failed to initialize GLAD"<<std::endl;
  }
}
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

  window = glfwCreateWindow(640, 360, "Dispresim", NULL, NULL);
  if(!window){
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout<<"Failed to initialize GLAD"<<std::endl;
  }
}

unsigned int OpenglAPI::bindShader(){
  program = glCreateProgram();

  unsigned int vs = OpenglAPI::createShader(GL_VERTEX_SHADER, vSource);
  unsigned int fs = OpenglAPI::createShader(GL_FRAGMENT_SHADER, fSource);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  glUseProgram(program);
  return program;
}

void OpenglAPI::render(Square& square){
  square.transform = glm::translate(square.transform,glm::vec3(square.velocity, 0.0f));
  glm::mat4 result = proj * square.transform;
  glUniformMatrix4fv(glGetUniformLocation(program, "uProj"),1, GL_FALSE, &result[0][0]);
  glClear(GL_COLOR_BUFFER_BIT);
  glBindVertexArray(square.vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}
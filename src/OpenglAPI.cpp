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
  const char* vSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec4 position;\n"
    "uniform mat4 uProj;\n"
    "void main(){\n"
    "gl_Position = uProj * position;\n"
    "}\n";
  const char* fSource = 
    "#version 330 core\n"
    "layout (location = 0) out vec4 color;\n"
    "uniform vec4 uColor;\n"
    "void main(){\n"
    "color = uColor;\n"
    "}\n";
  unsigned int program = glCreateProgram();

  unsigned int vs = OpenglAPI::createShader(GL_VERTEX_SHADER, vSource);
  unsigned int fs = OpenglAPI::createShader(GL_FRAGMENT_SHADER, fSource);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;
}
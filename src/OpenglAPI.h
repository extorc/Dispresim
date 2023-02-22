#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <malloc.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Square.h"

class OpenglAPI{
  public:
    GLFWwindow* window;
    glm::mat4 proj = glm::ortho(-320.0f, 320.0f, 180.0f, -180.0f,-1.0f, 1.0f);

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
    
    unsigned int program;
    
    static unsigned int createShader(unsigned int type, const char* src);
    void initializeGL();
    unsigned int bindShader();
    void render(Square& square);
};
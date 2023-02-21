#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <malloc.h>

class OpenglAPI{
  public:
    GLFWwindow* window;
    static unsigned int createShader(unsigned int type, const char* src);
    void initializeGL();
};
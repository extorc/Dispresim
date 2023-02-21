#include <stdio.h>
#include <glad/glad.h>
#include <glfw/glfw3.h>

int main(void){
  GLFWwindow* window;

  if(!glfwInit()){
    return -1;
  }

  window = glfwCreateWindow(640, 640, "Dispresim", NULL, NULL);
  if(!window){
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    // std::cout << "Failed to initialize OpenGL context" << std::endl;
    return -1;
  }

  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
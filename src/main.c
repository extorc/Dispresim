#include <stdio.h>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <malloc.h>

unsigned int createShader(unsigned int type, const char* src){
  unsigned int shader = glCreateShader(type);
  glShaderSource(shader, 1,&src, NULL);
  glCompileShader(shader);

  return shader;
}

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
    return -1;
  }

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
  const char* vSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec4 position;\n"
    "void main(){\n"
    "gl_Position = position;\n"
    "}\n";
  const char* fSource = 
    "#version 330 core\n"
    "layout (location = 0) out vec4 color;\n"
    "void main(){\n"
    "color = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

  unsigned int vs = createShader(GL_VERTEX_SHADER, vSource);
  unsigned int fs = createShader(GL_FRAGMENT_SHADER, fSource);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  glUseProgram(program);
  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glClearColor(0.7f, 0.7f, 0.8f, 1.0f);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
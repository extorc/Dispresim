#include <glad/glad.h>

struct Color{
  float r;
  float g;
  float b;
  float a;
};

void SetColor(unsigned int program, Color col);
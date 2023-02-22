#include "Color.h"

void SetColor(unsigned int program, Color col){
  glUniform4f(glGetUniformLocation(program, "uColor"), col.r, col.g, col.b, col.a);
}
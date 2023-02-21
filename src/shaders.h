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
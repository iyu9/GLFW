GLuint shader_program;

void ReadShaderFileCompile(GLuint Shader, const char *File)
{
  FILE *fp;
  char *buf;
  GLsizei size, len;
  GLint compiled;

  fp = fopen(File, "rb");
  if (fp == NULL)
  {
    printf("ファイルを開くことができません %s\n", File);
  }

  fseek(fp, 0, SEEK_END);
  size = ftell(fp);

  buf = (GLchar *)malloc(size);
  if (buf == NULL)
  {
    printf("メモリが確保できませんでした \n");
  }

  fseek(fp, 0, SEEK_SET);
  fread(buf, 1, size, fp);
  glShaderSource(Shader, 1, (const GLchar **)&buf, &size);
  free(buf);
  fclose(fp);

  glCompileShader(Shader);
  glGetShaderiv(Shader, GL_COMPILE_STATUS, &compiled);

  if (compiled == GL_FALSE)
  {
    printf("コンパイルできませんでした: %s \n ", File);
    glGetProgramiv(Shader, GL_INFO_LOG_LENGTH, &size);
    if (size > 0)
    {
      buf = (char *)malloc(size);
      glGetShaderInfoLog(Shader, size, &len, buf);
      printf("%s", buf);
      free(buf);
    }
  }
}

void Link(GLuint prog)
{
  GLsizei size, len;
  GLint linked;
  char *infoLog;

  glLinkProgram(prog);
  glGetProgramiv(prog, GL_LINK_STATUS, &linked);

  if (linked == GL_FALSE)
  {
    printf("リンクできませんでした!! \n");
    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &size);
    if (size > 0)
    {
      infoLog = (char *)malloc(size);
      glGetProgramInfoLog(prog, size, &len, infoLog);
      printf("%s", infoLog);
      free(infoLog);
    }
  }
}

void CompileAndLinkShader()
{
/*
  //glewの初期化
  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    printf("Error: %s\n", glewGetErrorString(err));
  }
*/
  // GPU,OpenGL情報
  printf("VENDOR= %s \n", glGetString(GL_VENDOR));
  printf("GPU= %s \n", glGetString(GL_RENDERER));
  printf("OpenGL= %s \n", glGetString(GL_VERSION));
  printf("GLSL= %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));

  GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
  ReadShaderFileCompile(vshader, "vshader.txt");

  GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
  ReadShaderFileCompile(fshader, "fshader.txt");

  shader_program = glCreateProgram();
  glAttachShader(shader_program, vshader);
  glAttachShader(shader_program, fshader);

  glDeleteShader(vshader);
  glDeleteShader(fshader);

  Link(shader_program);
}

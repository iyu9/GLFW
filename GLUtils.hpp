#ifndef __GLUTILS_HPP__
#define __GLUTILS_HPP__

namespace GLUtils
{
#define TEST_TEX_HEIGHT 64
#define TEST_TEX_WIDTH  64

  GLubyte image[TEST_TEX_HEIGHT][TEST_TEX_WIDTH][4];

  static void CheckRenderTexture()
  {
    for (int i = 0; i < TEST_TEX_HEIGHT; i++)
    {
      for (int j = 0; j < TEST_TEX_WIDTH; j++)
      {
        int color = ((i & 0x01) == 0) ^ ((j & 0x01) == 0);
        image[i][j][0] = color * 255;
        image[i][j][1] = color * 255;
        image[i][j][2] = color * 255;
        image[i][j][3] = 255;
      }
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEST_TEX_WIDTH, TEST_TEX_HEIGHT,
      0, GL_RGBA, GL_UNSIGNED_BYTE, image);
  }

  static void DrawTexture(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
  {
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(x, y, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(x, y + h, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y + h, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(x + w, y, 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
  }

  static void DrawRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
  {
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + w, y);
    glVertex2d(x + w, y + h);
    glVertex2d(x, y + h);
    glEnd();
  }

  static void DrawLine(GLfloat start_x, GLfloat start_y, GLfloat end_x, GLfloat end_y, GLint width)
  {
    glLineWidth(width);

    glBegin(GL_LINES);
    glVertex2d(start_x, start_y);
    glVertex2d(end_x, end_y);
    glEnd();
  }

  static void DrawPoint(GLfloat x, GLfloat y, GLint width)
  {
    glLineWidth(width);

    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
  }

  static void DrawShader(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
  {
    //glUseProgram(shader_program);
    DrawRect(x, y, w, h);
    //glUseProgram(0);
  }

  //for Custom Classes
  static void DrawTexture(GLVec2 pos, GLVec2 size)
  {
    DrawTexture(pos.x, pos.y, size.x, size.y);
  }

  static void DrawRect(GLVec2 pos, GLVec2 size)
  {
    DrawRect(pos.x, pos.y, size.x, size.y);
  }

  static void DrawLine(GLVec2 start_pos, GLVec2 end_pos, GLint width)
  {
    DrawLine(start_pos.x, start_pos.y, end_pos.x, end_pos.y, width);
  }

  static void DrawPoint(GLVec2 pos, GLint width)
  {
    DrawPoint(pos.x, pos.y, width);
  }

  static void DrawShader(GLVec2 pos, GLVec2 size)
  {
    DrawShader(pos.x, pos.y, size.x, size.y);
  }
};
#endif


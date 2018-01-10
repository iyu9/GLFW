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

    glPushMatrix();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEST_TEX_WIDTH, TEST_TEX_HEIGHT,
      0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    glPopMatrix();
  }

  static void DrawTexture(GLdouble x, GLdouble y, GLdouble w, GLdouble h)
  {
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0); glVertex3d(x, y, 0.0);
    glTexCoord2d(0.0, 1.0); glVertex3d(x, y + h, 0.0);
    glTexCoord2d(1.0, 1.0); glVertex3d(x + w, y + h, 0.0);
    glTexCoord2d(1.0, 0.0); glVertex3d(x + w, y, 0.0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  }

  static void DrawRect(GLdouble x, GLdouble y, GLdouble w, GLdouble h)
  {
    glPushMatrix();

    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x + w, y);
    glVertex2d(x + w, y + h);
    glVertex2d(x, y + h);
    glEnd();

    glPopMatrix();
  }

  static void DrawLine(GLdouble start_x, GLdouble start_y, GLdouble end_x, GLdouble end_y, GLdouble width)
  {
    glLineWidth((GLfloat)width);

    glBegin(GL_LINES);
    glVertex2d(start_x, start_y);
    glVertex2d(end_x, end_y);
    glEnd();
  }

  static void DrawPoint(GLdouble x, GLdouble y, GLdouble width)
  {
    glLineWidth((GLfloat)width);

    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
  }

  static void DrawCube(GLdouble x, GLdouble y, GLdouble z, GLdouble w, GLdouble h, GLdouble u)
  {
    GLVec3 vertices[8] = 
    {
      {x, y, z},
      {x + w, y, z},
      {x + w, y + h, z},
      {x, y + h, z},

      {x, y, z + u},
      {x + w, y, z + u},
      {x + w, y + h, z + u},
      {x, y + h, z + u},
    };

    glPushMatrix();

    glBegin(GL_TRIANGLES);

    //forward
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
    glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);
    glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
    glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
    glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);

    //rightside
    glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);
    glVertex3d(vertices[5].x, vertices[5].y, vertices[5].z);
    glVertex3d(vertices[7].x, vertices[7].y, vertices[7].z);
    glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);
    glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);
    glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);
    glVertex3d(vertices[7].x, vertices[7].y, vertices[7].z);
    glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);

    //leftside
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
    glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);
    glVertex3d(vertices[6].x, vertices[6].y, vertices[6].z);
    glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);

    //backward
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);
    glVertex3d(vertices[6].x, vertices[6].y, vertices[6].z);
    glVertex3d(vertices[7].x, vertices[7].y, vertices[7].z);
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);
    glVertex3d(vertices[5].x, vertices[5].y, vertices[5].z);
    glVertex3d(vertices[7].x, vertices[7].y, vertices[7].z);
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);

    //upper
    glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
    glVertex3d(vertices[6].x, vertices[6].y, vertices[6].z);
    glVertex3d(vertices[7].x, vertices[7].y, vertices[7].z);
    glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
    glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);
    glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);
    glVertex3d(vertices[7].x, vertices[7].y, vertices[7].z);
    glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);

    //lower
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
    glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);
    glVertex3d(vertices[5].x, vertices[5].y, vertices[5].z);
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);
    glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);
    glVertex3d(vertices[5].x, vertices[5].y, vertices[5].z);
    glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);

    glEnd();
    glPopMatrix();
  }

  static void DrawShader(GLdouble x, GLdouble y, GLdouble w, GLdouble h)
  {
    //glUseProgram(shader_program);
    DrawRect(x, y, w, h);
    //glUseProgram(0);
  }

  //for Custom Classes
  static void DrawTexture(GLVec2 pos, GLVec2 siz)
  {
    DrawTexture(pos.x - (0.5 * siz.x), pos.y - (0.5 * siz.y), siz.x, siz.y);
  }

  static void DrawRect(GLVec2 pos, GLVec2 siz)
  {
    DrawRect(pos.x - (0.5 * siz.x), pos.y - (0.5 * siz.y), siz.x, siz.y);
  }

  static void DrawLine(GLVec2 start_pos, GLVec2 end_pos, GLint width)
  {
    DrawLine(start_pos.x, start_pos.y, end_pos.x, end_pos.y, width);
  }

  static void DrawPoint(GLVec2 pos, GLint width)
  {
    DrawPoint(pos.x, pos.y, width);
  }

  static void DrawShader(GLVec2 pos, GLVec2 siz)
  {
    DrawShader(pos.x, pos.y, siz.x, siz.y);
  }

  static void DrawCube(GLVec3 pos, GLVec3 siz)
  {
    DrawCube(pos.x, pos.y, pos.z, siz.x, siz.y, siz.z);
  }
};
#endif


#ifndef __GLOBJECT_HPP__
#define __GLOBJECT_HPP__

namespace RenderType
{
  const int Rect = 0;
  const int Texture = 1;
  const int Polygon = 2;
  const int Shader = 3;
};

class GLObject
{
  int id;
  int type;
  int order;
  char* name;
  GLuint textureID;

  GLVec2 siz;
  GLVec2 pos;
  GLColor color;

public:
  GLObject(GLVec2 _pos, GLVec2 _siz)
  {
    siz = _siz;
    pos = _pos;
  }

  void SetType(GLint _type)
  {
    type = _type;
  }

  void SetTexture(GLuint _textureID)
  {
    type = RenderType::Texture;
    textureID = _textureID;
  }

  bool Render()
  {
    switch (type)
    {
    case RenderType::Rect:
      GLUtils::DrawRect(pos, siz);
      break;

    case RenderType::Texture:
      GLUtils::DrawTexture(pos, siz);
      break;

    case RenderType::Shader:
      GLUtils::DrawShader(pos, siz);
      break;

    case RenderType::Polygon:
      //TBD
      break;
    }

    return false;
  }
};

#endif

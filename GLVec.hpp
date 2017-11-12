#ifndef __GLVEC_HPP__
#define __GLVEC_HPP__

#include "GLUtils.hpp"
using namespace GLUtils;

namespace RenderType
{
    const int Rect = 0;
    const int Texture = 1;
    const int Polygon = 2;
    const int Shader = 3;
};

struct GLPoint
{
  GLfloat x;
};

struct GLVec2
{
  GLfloat x;
  GLfloat y;
};

struct GLVec3
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
};

struct GLVec4
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat w;
};

struct GLColor
{
  GLfloat r;
  GLfloat g;
  GLfloat b;
  GLfloat a;
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
        switch(type)
        {
            case RenderType::Rect:
                DrawRect(pos.x, pos.y, siz.x, siz.y);
                break;

            case RenderType::Texture:
                DrawTexture(pos.x, pos.y, siz.x, siz.y);
                break;
                
            case RenderType::Shader:
                DrawShader(pos.x, pos.y, siz.x, siz.y);
                break;
                
            case RenderType::Polygon:
                //TBD
                break;
        }
        
        return false;
    }
};

class GLScene
{
    int siz;
    GLObject* objects[100];
    
public:
    GLScene()
    {
        siz = 0;
    }
    
    void Push(GLObject* obj)
    {
        objects[siz] = obj;
        siz++;
    }

    void Pop()
    {
        objects[siz] = NULL;
        siz--;
    }
    
    bool Render()
    {
        for (int idx = 0; idx < siz; idx++)
        {
            objects[idx]->Render();
        }
        return false;
    }
};

#endif

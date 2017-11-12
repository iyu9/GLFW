#ifndef __GLVEC_HPP__
#define __GLVEC_HPP__

#include "GLUtils.hpp"
using namespace GLUtils;

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

class GLObject
{
    int id;
    int type;
    int order;
    char* name;
    GLuint textureID;
    
    GLVec2 size;
    GLVec2 position;
    
public:
    GLObject(GLVec2 _size, GLVec2 _pos)
    {
        size = _size;
        position = _pos;
    }
    
    bool Render()
    {
        const int RENDER_RECT = 0;
        const int RENDER_POLYGON = 1;
        
        switch(type)
        {
            case RENDER_RECT:
                DrawRect(position.x, position.y, size.x, size.y);
                break;
                
            case RENDER_POLYGON:
                break;
        }
        
        return false;
    }
};

class GLScene
{
    int size;
    GLObject* objects[100];
    
public:
    GLScene()
    {
        size = 0;
    }
    
    void Push(GLObject* obj)
    {
        objects[size] = obj;
        size++;
    }

    void Pop()
    {
        objects[size] = NULL;
        size--;
    }
    
    bool Render()
    {
        for (int idx = 0; idx < size; idx++)
        {
            objects[idx]->Render();
        }
        return false;
    }
};

#endif

#ifndef __GLVEC_HPP__
#define __GLVEC_HPP__

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
    
public:
    GLObject(){}
    
    bool Render()
    {
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
        return false;
    }
};

#endif

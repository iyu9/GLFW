#ifndef __GLBMPLOADER_HPP__
#define __GLBMPLOADER_HPP__

class BMP
{
public:
  int sizeX;
  int sizeY;
  char *Data;
  bool Load(const char *filename);
  GLuint texture;
  void SetTexture();
  BMP(const char *FileName);
  ~BMP();
  void Release();
};

BMP::BMP(const char *FileName)
{
  Load(FileName);
  SetTexture();
}

BMP::~BMP()
{
  free(Data);
}

bool BMP::Load(const char *FileName)
{
  FILE *File;
  unsigned long size;
  size_t i;
  unsigned short int planes;
  unsigned short int bpp;
  char temp;

  if ((File = fopen(FileName, "rb")) == NULL)
  {
    printf("No File");
    return false;
  }

  //Seek BMP Width
  fseek(File, 18, SEEK_CUR);

  if ((i = fread(&sizeX, 4, 1, File)) != 1)
  {
    printf("Read Width Error");
    return false;
  }
  std::cout << "sizeX = " << sizeX << std::endl;

  if ((i = fread(&sizeY, 4, 1, File)) != 1) {
    printf("Read Height Error");
    return false;
  }
  std::cout << "sizeY = " << sizeY << std::endl;

  //Calc BMP Image Size
  size = sizeX * sizeY * 3;
  if ((fread(&planes, 2, 1, File)) != 1) {
    printf("NOT READ PLANE NUM");
    return false;
  }
  if (planes != 1) {
    printf("PLANE NOT 1");
    return false;
  }

  //Read Pixel
  if ((i = fread(&bpp, 2, 1, File)) != 1) {
    printf("NOT Read BMP Pixel Nums");
    return false;
  }
  if (bpp != 24) {
    printf("NOT 24bit BMP Image");
    return false;
  }

  //Read RGB
  fseek(File, 24, SEEK_CUR);
  printf("memory allocated = %lu Bytes", size);
  Data = (char *)malloc(size);
  if (Data == NULL) {
    printf("Cannnot Allocate BMP Memory");
    return false;
  }
  if ((i = fread(Data, size, 1, File)) != 1) {
    printf("Cannot Read BMP Data");
    return false;
  }
    
  //BGR convert RGB
  for (i = 0; i < size; i += 3) {
    temp = Data[i];
    Data[i] = Data[i + 2];
    Data[i + 2] = temp;
  }
  return true;
}

void BMP::SetTexture()
{
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, 3, sizeX, sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, Data);
}

void BMP::Release()
{
  delete[] Data;
}

#endif

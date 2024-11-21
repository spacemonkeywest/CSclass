#ifndef DREAM_H
#define DREAM_H

class Dream {
  private:
    int dreamLevel;
    int *ptr;

  public:
    Dream(int numElements, int value);
    ~Dream();
};

#endif
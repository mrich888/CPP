#include <iostream>

class Fruit
{
public:
  virtual void show() = 0;
};
class SouthApple : public Fruit
{
public:
  void show()
  {
    std::cout << "北方苹果\n";
  }
};
class NorthApple : public Fruit
{
public:
  void show()
  {
    std::cout << "南方苹果\n";
  }
};
class SouthPear : public Fruit
{
public:
  void show()
  {
    std::cout << "北方梨\n";
  }
};
class NorthPear : public Fruit
{
public:
  void show()
  {
    std::cout << "南方梨\n";
  }
};

class Factory
{
public:
  virtual Fruit* createApple() = 0;
  virtual Fruit* createPear() = 0;
};

class NorthFactory:public Factory
{
public:
  Fruit* createApple()
  {
    return new NorthApple;
  }
  Fruit* createPear()
  {
    return new NorthPear;
  }
};

class SouthFactory:public Factory
{
public:
  Fruit* createApple()
  {
    return new SouthApple;
  }
  Fruit* createPear()
  {
    return new SouthPear;
  }
};

int main()
{
    Factory *f = new NorthFactory;
    f->NorthFactory.show();
    f->

}
  
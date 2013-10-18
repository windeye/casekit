#include <stdio.h>
#include <string>
#include <iostream>

template <class T, int n>
class point
{
  public:
  point(T dim[n])
  {
    for(int i =0;i<n;i++)
    {
      _dim[i] = dim[i];
    }
  }
  public:
    T _dim[n];
};

int main()
{
  int dim[3] = {2,2,3};
  point<int, 2> p3(dim);
  return 0;
}

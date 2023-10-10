#include "vector.h"

Vector<int>::Vector()
{
   len = 0;
   pmas = nullptr;
}

int* Vector<int>::retPmas()
{
   return pmas;
}

void Vector<int>::push(int digit)
{
   if (!pmas)
   {
      len++;
      pmas = new int[len];
      pmas[len-1] = digit;
   }
   else
   {
      len++;
      int* tempMas = new int[len];
      for (int i = 0; i < len - 1; i++)
      {
         tempMas[i] = pmas[i];
      }
      tempMas[len-1] = digit;
      delete []pmas;
      pmas = tempMas;
   }
}

int Vector<int>::maxValue()
{  int maximum = 0;
   for (int i = 0; i < len; i++)
   {
      if (pmas[i] > maximum)
         maximum = pmas[i];
   }
   return maximum;
}

Vector<int>::~Vector()
{
   delete []pmas;
}

void Vector<int>::display()
{
   for (int i = 0; i < len; i++)
   {
      std::cout << pmas[i] << ' ';
   }
}

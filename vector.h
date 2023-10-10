#pragma once
#include <iostream>

template<typename T>
class Vector
{
private:
   int len;
   T** pmas;
public:
   Vector();
   T* retPointer(int);
   void push(int);
   void display();
   int retLen();
   int maxValue();
   void resetLen();
   T** retPmas();
   void resetVector();
   ~Vector();
};

template<>
class Vector<int>
{
private:
   int len;
   int* pmas;
public:
   Vector();
   void push(int);
   void display();
   int retLen();
   int* retPmas();
   int maxValue();
   ~Vector();
};

template<typename T>
Vector<T>::Vector()
{
   len = 0;
   pmas = nullptr;
}

template<typename T>
T** Vector<T>:: retPmas()
{
   return pmas;
}

template<typename T>
T* Vector<T>::retPointer(int pos)
{
   return pmas[pos-1];   
}

template<typename T>
void Vector<T>::push(int digit)
{
   if (!pmas)
   {
      len++;
      pmas = new T*[len];
      pmas[len-1] = new T;
      (pmas[len-1])->number = digit;
   }
   else
   {
      len++;
      T** tempMas = new T*[len];
      for (int i = 0; i < len - 1; i++)
      {
         tempMas[i] = pmas[i];
      }
      tempMas[len-1] = new T;
      tempMas[len-1]->number = digit;
      delete []pmas;
      pmas = tempMas;
   }
}

template<typename T>
int Vector<T>::maxValue()
{
   return len;
}

template<typename T>
void Vector<T>::display()
{
   for (int i = 0; i < len; i++)
   {
      std::cout << pmas[i]->number << std::endl;
   }
}

template<typename T>
void Vector<T>::resetLen()
{
   len = 0;
}

template<typename T>
Vector<T>::~Vector()
{
   delete [] pmas;
}

template<typename T>
void Vector<T>::resetVector()
{
   delete [] pmas;
   pmas = nullptr;
   len = 0;
}

template<typename T>
int Vector<T>::retLen()
{
   return len;
}

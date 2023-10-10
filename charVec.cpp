#include "vector.h"
#include <cstdlib>

Vector<char>::Vector()
{
   len = 0;
   pmas = nullptr;
}

void Vector<char>::push(char ch)
{
   if (!len) 
   {
      len++;
      pmas = new char[len];
      pmas[len-1] = ch;
   }
   else
   {
      len++;
      char* tempMas = new char[len];
      for (int i = 0; i < len - 1; i++)
      {
         tempMas[i] = pmas[i];
      }
      tempMas[len - 1] = ch;
      delete []pmas;
      pmas = tempMas;
   }
}

int Vector<char>::retLen()
{
   return len;
}

char* Vector<char>::retPmas()
{
   return pmas;
}

int Vector<char>::charMasToInt()
{
   len++;
   char* tempMas = new char[len];
   for (int i = 0; i < len - 1; i++)
   {
      tempMas[i] = pmas[i];
   }
   tempMas[len - 1] = '\0';
   delete []pmas;
   pmas = tempMas;
   return atoi(pmas);
}

void Vector<char>::display()
{
   for (int i = 0; i < len; i++)
   {
      std::cout << pmas[i];
   }
   std::cout << std::endl;
}

Vector<char>::~Vector()
{
   delete []pmas;
}


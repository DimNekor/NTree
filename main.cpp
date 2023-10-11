#include "N-Tree.h"
#include <limits>

void moveCursorInTree(NTree&, int, int);

int main()
{  
   bool isContinue = true;
   while (isContinue)
   {
      std::cout << "Do you want to start program? Press 's'" << std::endl;
      std::cout << "Do you want to finish program? Press 'f'" << std::endl;
      char choice;
      bool flag = true;
      std::cin >> choice;
      NTree ntree;
      while (choice == 's')
      {  
         if (flag) 
         {
            std::cout << "_______The tree was created!______" << std::endl;
            std::cout << "Do you want to fill it? Press 'f'" << std::endl;
            std::cout << "Do you want to end the program? Press 'e'" << std::endl;
            std::cin >> choice;
            flag = false;
         }
         if (choice == 's')
         {
            std::cout << "Do you want to display tree? Press 'd'" << std::endl;
            std::cout << "Do you want to remove the farthest leaves? Press 'r'" << std::endl;
            std::cout << "Do you want to end the program? Press 'e'" << std::endl;
            std::cin >> choice;
            if (choice == 'd')
            {
               choice = 's';
               ntree.display();
            }
            else if (choice == 'r')
            {  
               choice = 's';
               ntree.initializeHeight();
               ntree.rmFarLeaves();
               ntree.display();
            }
            else if (choice == 'e')
            {
            
            }
            else
            {
               std::cout << "Incorrect input!" << std::endl;
               choice = 's';
            }
         }
         else if (choice == 'f')
         {
            std::cout << "Do you want to fill it from file? Press 'f'" << std::endl;
            std::cout << "Do you want to fill it by keyboard? Press 'k'" << std::endl;
            std::cin >> choice;
            if (choice == 'f')
            {  
               char filename[30];
               std::cout << "Enter the name of file" << std::endl;
               std::cin >> filename;
               FILE* fp = fopen(filename, "r");
               while (!fp)
               {
                  std::cout << "Incorrect name of file" << std::endl;
                  std::cin >> filename;
                  fp = fopen(filename, "r");
               }
               char ch;
               int numOfLines = 0;
               while( (ch = getc(fp)) != EOF)
               {
                  if (ch == '\n') numOfLines++;
               }
               fclose(fp);
               FILE* file = fopen(filename, "r");
               int numTransitionsDown = 0;
               int numPositions = 0;
               Vector<char> vecSym;
               while( (ch = getc(file)) != EOF)
               {
                  if (numTransitionsDown < 2)
                  {
                     if (ch != ' ' &&  ch != '\n' && ch != '\r')
                     {  
                        vecSym.push(ch);
                     } 
                     else if (ch == ' ')
                     {
                        ntree.addEl(vecSym.charMasToInt());
                        vecSym.~Vector();
                     }
                     else if (ch == '\n' && numTransitionsDown == numOfLines - 1)
                     {
                        ntree.addEl(vecSym.charMasToInt()); 
                        numTransitionsDown++;
                     }
                     else if (ch == '\n')
                     {
                        ntree.addEl(vecSym.charMasToInt());
                        numTransitionsDown++;
                        vecSym.~Vector();
                     }
                  }
                  else 
                  {
                     if (ch != ' ' && ch != '\n' && ch != '\r' && ch != '|')
                     {
                        std::cout << ch << std::endl;
                        vecSym.push(ch);
                     }
                     else if (ch == '|')
                     {  
                        int temp = numPositions;
                        moveCursorInTree(ntree, numPositions, numTransitionsDown);
                        numPositions = temp;
                        numPositions++;
                        ntree.addEl(vecSym.charMasToInt());
                        vecSym.~Vector();
                     }
                     else if (ch == ' ')
                     {
                        int temp = numPositions;
                        moveCursorInTree(ntree, numPositions, numTransitionsDown);
                        numPositions = temp;
                        ntree.addEl(vecSym.charMasToInt());
                        vecSym.~Vector();
                     }
                     else if (ch == '\n' && numTransitionsDown == numOfLines -  1)
                     {
                        moveCursorInTree(ntree, numPositions, numTransitionsDown);
                        ntree.addEl(vecSym.charMasToInt());
                     } 
                     else if (ch == '\n')
                     {  
                        moveCursorInTree(ntree, numPositions, numTransitionsDown);
                        ntree.addEl(vecSym.charMasToInt());
                        numTransitionsDown++;
                        numPositions++;
                        vecSym.~Vector();
                     }
                  }   
               }
               fclose(file);
               choice = 's';          
            }
            else if (choice == 'k')
            {  
               bool isRoot = true;
               bool isNotEnd = true; 
               while (isNotEnd)
               {
                  int num;
                  if (isRoot)
                  {
                     std::cout << "Enter the number in root" << std::endl;
                     std::cin >> num;
                     while (!std::cin.good())
                     { 
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Enter a number!" <<std::endl;
                        std::cin >> num;
                     }
                     isRoot = false; 
                     ntree.addEl(num);          
                  }
                  else
                  {
                     if (ntree.getNumOfChilds())
                     {
                        std::cout << "You are in note, that has " << ntree.getNumOfChilds() << "children" << std::endl;
                        std::cout << "If you want to add more children, enter 'a'" << std::endl;
                        std::cout << "If you want to move to another children, enter 'm'" << std::endl;
                        std::cout << "If you want to move to root, enter 'r'" << std::endl;
                        std::cout << "If you want to finish adding, enter 'f'" << std::endl;
                        std::cin >> choice;
                        if (choice == 'a')
                        {
                           std::cout << "Enter the digit" << std::endl;
                           std::cin >> num;
                           while (!std::cin.good())
                           {
                              std::cin.clear();
                              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                              std::cout << "Enter a number!" <<std::endl;
                              std::cin >> num;
                           }
                           ntree.addEl(num);
                        }
                        else if (choice == 'm')
                        {
                           std::cout << "Enter numbers from 1 to " << ntree.getNumOfChilds() << " to move to another node"  << std::endl;
                           std::cin >> num;
                           while (!std::cin.good() || num > ntree.getNumOfChilds())
                           {
                              std::cin.clear();
                              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                              std::cout << "Enter a number from 1 to "<< ntree.getNumOfChilds() << '!' << std::endl;
                              std::cin >> num;
                           }
                           ntree.moveToNode(num);
                        }
                        else if (choice == 'r')
                        {
                           ntree.currentEqualRoot();
                        }
                        else if (choice == 'f')
                        {
                           isNotEnd = false;
                           choice = 's';
                        }
                        else
                        {
                           choice = 's';
                           std::cout << "***Incorrect input!" << std::endl;
                        }
                     }
                     else
                     {
                        std::cout << "You are in note, that has not children" << std::endl;
                        std::cout << "If you want to add child here, press 'a'" << std::endl;
                        std::cout << "If you want to move to root, press 'r'" << std::endl;
                        std::cout << "If you want to finish adding, press 'f'" << std::endl;
                        std::cin >> choice;
                        if (choice == 'a')
                        {
                           std::cout << "Enter the digit" << std::endl;
                           std::cin >> num;
                           while (!std::cin.good())
                           {
                              std::cin.clear();
                              std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                              std::cout << "Enter a number!" <<std::endl;
                              std::cin >> num;
                           }
                           ntree.addEl(num);
                        }
                        else if (choice == 'r')
                        {
                           ntree.currentEqualRoot();
                        }
                        else if (choice == 'f')
                        {
                           isNotEnd = false;
                           choice = 's';
                        }
                        else
                        {
                           std::cout << "Incorrect input!" << std::endl;
                        }
                     }
                  }
               }
            }
            else
            {
               std::cout << "Incorrect input!" << std::endl;
               choice = 's';
            }
         }   
      }   
      if (choice == 'f' || choice == 'e')
      {
         isContinue = false;
         std::cout << "Good Bye!" << std::endl;
      }
      else
      {    
         isContinue = true;
      }
   }         
   return 0;
}

void moveCursorInTree(NTree& ntree, int numPositions, int numTransitionsDown)
{  
   ntree.currentEqualRoot();
   for (int i = 0; i < numTransitionsDown - 1; i++)
   {
      int lastChildren = 0;
      if (ntree.getNumOfChilds() <= numPositions)
      {
         int temp = ntree.getNumOfChilds();
         if (lastChildren != ntree.getNumOfChilds())
         {
            lastChildren = ntree.getNumOfChilds();
         }
         ntree.moveToNode(numPositions/ntree.getNumOfChilds() % temp);
         numPositions = numPositions - temp;
         lastChildren = ntree.getNumOfChilds();
       }
      else
      {
         ntree.moveToNode(numPositions + 1);
      }
   }  
}

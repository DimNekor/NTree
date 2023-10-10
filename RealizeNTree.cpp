#include "N-Tree.h"

NTree::NTree()
{
   height = 0;
   root = nullptr;
   current = nullptr;
}

void NTree::currentEqualRoot()
{
   current = root;
}

void NTree::moveToNode(int pos)
{
   current = current->children.retPointer(pos);    
}

void NTree::addEl(int el)
{
   if (!root)
   {
      root = new Node;
      current = root;
      root->number = el;
   }
   else
   {
      current->children.push(el);
   }
}

void NTree::display(Node* node, int depth)
{
   for (int i = node->children.retLen(); 0 < i; i--)
   {  
      display(node->children.retPointer( i ), depth + 1);
      if (i == node->children.retLen())
      {
         for (int i = 0; i < depth; i++)
         {
            std::cout << "     ";
         }
         std::cout << node->number << std::endl;
      } 
      if (i == 1) std::cout << std::endl; 
   }
   if (!(node->children.retPmas()))
   {   
      for (int i = 0; i< depth; i++)
      {
         std::cout << "     ";
      }
      std::cout << node->number << std::endl;
   }
}

void NTree::display()
{
   display(root, 1); 
}

int NTree::retHeight(Node* node)
{
   if (!(node->children.retPmas()))
   {
      return 0;
   }
   Vector<int> max;
   int maximum;
   for (int i = node->children.retLen(); 0 < i; i--)
   {
      max.push(retHeight(node->children.retPointer(i)));
      maximum = max.maxValue() + 1;
   }
   return maximum;
}

void NTree::initializeHeight()
{
   height = retHeight(root);
}

int NTree::retHeight()
{
   return height;
}

void NTree::rmFarLeaves()
{
   rmFarLeaves(root, 0);
}

void NTree::rmFarLeaves(Node* node, int curHeight)
{
   for( int i = node->children.retLen(); 0 < i; i--)
   {  
      rmFarLeaves(node->children.retPointer(i), curHeight + 1);
      if (i == 1 && curHeight == height - 1)
      {
         node->children.resetVector();
      }
   }
}

int NTree::getNumOfChilds()
{
   return getNumOfChilds(current);
}

int NTree::getNumOfChilds(Node* current)
{
   return current->children.retLen();
}

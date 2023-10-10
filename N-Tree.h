#pragma once
#include "vector.h"

struct Node
{
   int number;
   Vector<Node> children;
};

class NTree
{
private:
   int height;
   Node* root;
   Node* current;
   void display(Node*, int);
   int retHeight(Node*);
   void rmFarLeaves(Node*, int);
   int getNumOfChilds(Node*);
public:
   NTree();
   void currentEqualRoot();
   void addEl(int);
   void moveToNode(int);
   void rmFarLeaves();
   int retHeight();
   void initializeHeight();
   int  getNumOfChilds();
   void display();
};

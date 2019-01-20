#pragma once
#include <iostream>
#include<vector>
class Literal;

class Node {
public:
  Node() {}
  virtual ~Node() {}
  //virtual const Literal* eval() const = 0;
  virtual const Literal* eval(int scope=0) const =0;
  virtual std::string IsA() const {return "Node";}
  virtual std::vector<Node*> * getStmtVector() const {return nullptr;}
  virtual Node * getLeft() const {return nullptr;}
  virtual Node * getRight() const {return nullptr;}
  virtual void print() const { 
    std::cout << "NODE" << std::endl; 
  }

};


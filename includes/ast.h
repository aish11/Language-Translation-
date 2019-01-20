#pragma once

//  Declarations for a calculator that builds an AST
//  and a graphical representation of the AST.
//  by Brian Malloy

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "literal.h"
#include "symbolTable.h"
extern void yyerror(const char*);
extern void yyerror(const char*, const char);

//const Literal* UnaryMinusNode(Node*);
//const Literal* UnaryAddNode(Node*);


void freeAST(Node*);

class PrintNode : public Node {
public:
  PrintNode(Node * node): Node (), node(node){}
  //virtual ~PrintNode(){ /*if(node) delete node;*/}
  const Literal* eval(int scope = 0) const;
  PrintNode(const PrintNode&) = delete;
  PrintNode& operator=(const PrintNode&) = delete;
  virtual std::string IsA() const { return "PrintNode";}
private:
  Node *node;
};

class FunctionNode : public Node {
public:
  FunctionNode(std::string id, Node *params, Node *node) : Node(), params(params), suiteNode(node),ident(id){}

  std::string getIdent() const { return ident; }
  virtual const Literal* eval(int scope = 0) const;
  virtual std::string IsA() const { return "FunctionNode";}
  FunctionNode(const FunctionNode&) = delete;
  FunctionNode& operator=(const FunctionNode&) = delete;
private:
  Node *params;
  Node *suiteNode;
  std::string ident;
};

class SuiteNode : public Node {
public:
  SuiteNode(std::vector<Node*> *stmts):Node(),stmts(stmts){}
  virtual ~SuiteNode();
  virtual const Literal * eval(int scope = 0) const;
  virtual std::string IsA() const { return "SuiteNode";}
  virtual std::vector<Node*> * getStmtVector() const {return stmts;}
  SuiteNode(const SuiteNode&) = delete;
  SuiteNode& operator=(const SuiteNode&) = delete;
private:
  std:: vector<Node*> *stmts;
};

class CallFunctionNode: public Node
{
public:
  CallFunctionNode(std::string function,Node *argSuite): Node(),function(function),argSuite(argSuite){}
  //virtual ~CallFunctionNode(){}
  virtual const Literal *eval(int scope = 0)const;
  const Node *AsgArguments(std::vector<Node*>* params, std::vector<Node*> *values)const;
  CallFunctionNode(const CallFunctionNode&) = delete;
  CallFunctionNode& operator=(const CallFunctionNode&) = delete;
private:
  std::string function;
  Node *argSuite;
};

class ReturnNode: public Node
{
public:
  ReturnNode(Node * val):Node(), val(val){}
  //virtual ~ReturnNode(){ /*if(val) delete val;*/}
  virtual const Literal *eval(int scope = 0)const;
  virtual std::string IsA() const { return "ReturnNode";}
  ReturnNode(const ReturnNode&) = delete;
  ReturnNode& operator=(const ReturnNode&) = delete;
private:
  Node *val;  
};

class IfElseNode : public Node
{
public:
   IfElseNode(Node *test, Node *ifSuite, Node *elseSuite): Node(), test(test), ifSuite(ifSuite), elseSuite(elseSuite){}
   //virtual ~IfElseNode(){ if(test) delete test; if(ifSuite) delete ifSuite; if(elseSuite) delete elseSuite;}
   virtual const Literal *eval(int scope = 0) const;
   virtual std::string IsA() const { return "IfElseNode";}
   IfElseNode(const IfElseNode&) = delete;
  IfElseNode& operator=(const IfElseNode&) = delete;
private:
  Node *test;
  Node *ifSuite;
  Node *elseSuite;  
};



class StringNode : public Node {
public:
  StringNode(const std::string& s) : Node(), str(s) { } 
  virtual ~StringNode() {}
  virtual const Literal* eval(int scope=0) const;
private:
  std::string str;
};


class IdentNode : public Node {
public:
  IdentNode(const std::string id) : Node(), ident(id) { } 
  virtual ~IdentNode() {}
  const std::string getIdent() const { return ident; }
  virtual const Literal* eval(int scope=0) const;
  virtual std::string IsA() const { return "IdentNode";}
private:
  std::string ident;
};


class TernaryNode : public Node {
public:
  TernaryNode(Node* l, Node* index) : Node(), left(l), index(index) {}
  virtual const Literal* eval(int scope=0) const = 0;
  Node* getLeft()  const { return left; }
  Node* getindex() const { return index; }
  TernaryNode(const TernaryNode&) = delete;
  TernaryNode& operator=(const TernaryNode&) = delete;
protected:
  Node *left;
  Node *index;
};


class IndexTernaryNode : public TernaryNode {
public:
  IndexTernaryNode(Node* left, Node* index) : TernaryNode(left,index) {}
  virtual const Literal* eval(int scope=0) const;
};

class SingleIndexTernaryNode : public TernaryNode {
public:
  SingleIndexTernaryNode(Node* left, Node* index) : TernaryNode(left,index) {}
  virtual const Literal* eval(int scope=0) const;
};


class IndexBinaryNode : public Node {
public:
  IndexBinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval(int scope=0) const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  IndexBinaryNode(const IndexBinaryNode&) = delete;
  IndexBinaryNode& operator=(const IndexBinaryNode&) = delete;
protected:
  Node *left;
  Node *right;
};

class IndexBinaryevalNode : public IndexBinaryNode {
public:
  IndexBinaryevalNode(Node* left, Node* right) : IndexBinaryNode(left,right) {}
  virtual const Literal* eval(int scope=0) const;
};


class BinaryNode : public Node {
public:
  BinaryNode(Node* l, Node* r) : Node(), left(l), right(r) {}
  virtual const Literal* eval(int scope=0) const = 0;
  Node* getLeft()  const { return left; }
  Node* getRight() const { return right; }
  BinaryNode(const BinaryNode&) = delete;
  BinaryNode& operator=(const BinaryNode&) = delete;
  virtual std::string IsA() const { return "BinaryNode";}
protected:
  Node *left;
  Node *right;
};



class UnaryNode : public Node {
public:
  UnaryNode(Node* n) : Node(), node(n) {}
  virtual const Literal* eval(int scope=0) const = 0;
  Node* getUnaryNode()  const { return node; }
  UnaryNode(const UnaryNode&) = delete;
  UnaryNode& operator=(const UnaryNode&) = delete;
protected:
  Node *node;
};


class UnaryMinusNode : public UnaryNode {
public:
  UnaryMinusNode(Node* node) : UnaryNode(node) { }
  virtual const Literal* eval(int scope=0) const;
//protected:
 // Node *node;
};

class UnaryPlusNode : public UnaryNode {
public:
  UnaryPlusNode(Node* node) : UnaryNode(node) { }
  virtual const Literal* eval(int scope=0) const;

};



class AsgBinaryNode : public BinaryNode {
public:
  AsgBinaryNode(Node* left, Node* right);
  //virtual const Literal* eval() const;
  virtual const Literal* eval(int scope = 0) const;
  virtual std::string IsA() const { return "AsgBinaryNode";}
};

class AddBinaryNode : public BinaryNode {
public:
  AddBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(int scope = 0) const;
};

class SubBinaryNode : public BinaryNode {
public:
  SubBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(int scope = 0) const;
};

class MulBinaryNode : public BinaryNode {
public:
  MulBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval(int scope = 0) const;
};

class DivBinaryNode : public BinaryNode {
public:
  DivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(int scope = 0) const;
};

class ModBinaryNode : public BinaryNode {
public:
  ModBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(int scope = 0) const;
};

class PowBinaryNode : public BinaryNode {
public:
  PowBinaryNode(Node* left, Node* right) : BinaryNode(left, right) {}
  virtual const Literal* eval(int scope = 0) const;
};

class DoubleDivBinaryNode : public BinaryNode {
public:
  DoubleDivBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(int scope = 0) const;
};

class SIBinaryNode : public BinaryNode {
public:
  SIBinaryNode(Node* left, Node* right) : BinaryNode(left, right) { }
  virtual const Literal* eval(int scope = 0) const;
};

class ComparisonBinaryOperation : public BinaryNode
{
public:
  ComparisonBinaryOperation(Node* left, Node* right, int operation) : BinaryNode(left, right),operation(operation) { };
  virtual const Literal* eval(int scope = 0) const;
private:
  int operation;  
};
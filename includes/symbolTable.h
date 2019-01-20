#ifndef SYMBOLTABLE__H
#define SYMBOLTABLE__H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

class Literal;

class Node;

class SymbolTable {
public:
  static   SymbolTable& getInstance();
  //void     setValue(const std::string& name, const Literal* val);
  //const Literal* getValue(const std::string& name) const;
  
  void setValue(const std::string& name, const Literal* val);
  void setFunction(const std::string&name, const Node * func);
  void setFunctionParams(const std::string&name, const Node *params);
  void pushScope();
  void resetTmpScope();
  int getCurrentScope() const;
  void popScope();
  bool isTmpScopeSet() const;
  void setTempScope(int val);
  const Literal* getValue(const std::string& name, int scope) const;
  const Node * getSuiteNode(const std::string&name, int &tempScope) const ;
  const Node *getParamsSuite(const std::string&name) const;


private:
 // std::map<std::string, const Literal*> table;
 // SymbolTable() : table() {}
std::map<std::string, const Literal*> LiteralTable;
std::map<std::string, const Node*>FunctionTable;
std::map<std::string, const Node*>ParamsTable;
std::map<std::string, const int> StackMap;
int Scope;
int tmpScope;
SymbolTable() : LiteralTable(), FunctionTable(),ParamsTable(),StackMap(),Scope(0),tmpScope(-1) {}

};

#endif

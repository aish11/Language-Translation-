#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "poolOfNodes.h"
#include "ast.h"
#include "symbolTable.h"

void freeAST(Node* node) {
  if ( node ) {
    BinaryNode* temp = dynamic_cast<BinaryNode*>(node);
    if ( temp ) {
      freeAST(temp->getLeft());
      freeAST(temp->getRight());
    }
    delete node;
  }
}


const Literal* UnaryMinusNode::eval(int scope) const 
{
  if (!node) {
    throw std::string("error");
  }
const Literal* res = node->eval(scope);
return (*res).opUnaryMinus();
} 

const Literal* UnaryPlusNode::eval(int scope) const 
{
  if (!node) {
    throw std::string("error");
  }
const Literal* res = node->eval(scope);
return (*res).opUnaryPlus();
}


const Literal* StringNode::eval(int scope) const { 
  //const Literal* val = new StringLiteral(str);

  const Literal* val = SymbolTable::getInstance().getValue(str,scope);
  return val;
}


const Literal* IndexBinaryevalNode::eval(int scope) const { 
  //if (!left || !right) {
  //  throw std::string("error");
  //}

  const IntLiteral* x = static_cast<const IntLiteral*>(left->eval(scope));
  const IntLiteral* y = static_cast<const IntLiteral*>(right->eval(scope));
  return new TupleLiteral(*x,*y);
}


const Literal* IdentNode::eval(int scope) const { 
  const Literal* val;
  try{ 
  val = SymbolTable::getInstance().getValue(ident, scope);
  }
  catch(const std::string& msg)
  {
    std::cout << "Error is :: " << msg << std::endl;
  }
  return val;
}

const Literal* IndexTernaryNode::eval(int scope) const { 
  if (!left || !index) {
    throw std::string("error");
  }
   //std::cout << "test" << std::endl;
  const Literal* x = left->eval(scope);
  const Literal* y = index->eval(scope);
  //const Literal* z = index2->eval();
  return ((*x).SliceOf(*y));
}

/*const Literal* SingleIndexTernaryNode::eval() const { 
  if (!left || !index) {
    throw std::string("error");
  }
  //std::cout << "test" << std::endl;
  const Literal* x = left->eval();
  const Literal* y = index->eval();
  //const Literal* z = index2->eval();
  return ((*x).IndexOf(*y));
}
*/

AsgBinaryNode::AsgBinaryNode(Node* left, Node* right) : 
  BinaryNode(left, right) { 
  //const Literal* res = right->eval();
  //const std::string n = static_cast<IdentNode*>(left)->getIdent();
  //SymbolTable::getInstance().setValue(n, res);
}


const Literal* AsgBinaryNode::eval(int scope) const { 
  if (!left || !right) {
    throw std::string("error");
  }
  //const Literal* res = right->eval();

  const std::string n = static_cast<IdentNode*>(left)->getIdent();
  const Literal *res = nullptr;
  if(scope == 2)
  {
  SymbolTable::getInstance().setValue(n, res);
  }
  else
  {

    /*res = right->eval(1);
    SymbolTable::getInstance().setValue(n,res);
    PoolOfNodes::getInstance().add(res);
    */
    if(right != nullptr)
     {   
         res = right->eval(1);
         if(res != nullptr)
            PoolOfNodes::getInstance().add(res);
     } 
     SymbolTable::getInstance().setValue(n, res);
  }
  PoolOfNodes::getInstance().add(right);
  return res;
}

const Literal* AddBinaryNode::eval(int scope) const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(scope);
  const Literal* y = right->eval(scope);
  return (*x+*y);
}

const Literal* SubBinaryNode::eval(int scope) const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(scope);
  const Literal* y = right->eval(scope);
  return ((*x)-(*y));
}

const Literal* MulBinaryNode::eval(int scope) const { 
  if (!left || !right) {
    throw std::string("error");
  }
  //std::cout << "mul" << std::endl;
  const Literal* x = left->eval(scope);
  const Literal* y = right->eval(scope);
  return ((*x)*(*y));
}

const Literal* DivBinaryNode::eval(int scope) const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(scope);
  const Literal* y = right->eval(scope);
  return ((*x)/(*y));
}

const Literal* ModBinaryNode::eval(int scope) const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(scope);
  const Literal* y = right->eval(scope);
  return ((*x)%(*y));
}

const Literal* PowBinaryNode::eval(int scope) const { 
  if (!left || !right) {
    throw "error";
  }
  const Literal* x = left->eval(scope);
  const Literal* y = right->eval(scope);
  return ((*x)^(*y));
}

const Literal* DoubleDivBinaryNode::eval(int scope) const { 
  if (!left || !right) {
    throw std::string("error");
  }
  const Literal* x = left->eval(scope);
  const Literal* y = right->eval(scope);
  return ((*x).DoubleDiv(*y));
}


const Literal* SIBinaryNode::eval(int scope) const { 
  std::cout<<"Ast here "<<std::endl;
  if (!left || !right) {
    throw std::string("error");
  }
  
  const Literal* x = left->eval(scope);
  //const StringLiteral* x = static_cast<const StringLiteral*>(left->eval());
  //const IntLiteral* y = static_cast<const IntLiteral*>(right->eval());
  const Literal* y = right->eval(scope);
  return ((*x).IndexOf(*y));
}


/*const Literal* SingleIndexBinaryNode::eval() const { 
  if (!left || !right) {
    throw std::string("error");
  }
  std::cout<<"Ast here "<<std::endl;
  const Literal* x = left->eval();
  const Literal* y = right->eval();
  //const IntLiteral *il = static_cast<const IntLiteral*>(y);
  //std::cout << il->getVal() << std::endl;
  //return (opIndex(*x,static_cast<IntegerLiteral>(*y));
  return ((*x).IndexOf(*y));
}

*/
const Literal* PrintNode::eval(int scope) const 
{ 
  Literal const *res = (node)->eval(scope);
  res->print();
  return res;
}

const Literal* FunctionNode::eval(int ) const 
{ 
  std::string n = getIdent();
  //scope = 0;
  //std::cout<<"FunctionNode : eval step 1"<<std::endl;
  SymbolTable::getInstance().setFunction(n, suiteNode);
  SymbolTable::getInstance().setFunctionParams(n, params);
  PoolOfNodes::getInstance().add(suiteNode);
  PoolOfNodes::getInstance().add(params);
  return nullptr;
}

const Literal* SuiteNode::eval(int scope) const 
{ 
  const Literal *res = nullptr;
  //std::cout<<"SuiteNode : eval step 1"<<std::endl;
  for (const Node *stmt : (*stmts))
  {
    if(stmt->IsA() == "AsgBinaryNode")
    { 
      //std::cout<<"SuiteNode : eval step 2"<<std::endl;
      res = stmt->eval(2);
      if(res!= nullptr)
        PoolOfNodes::getInstance().add(res);
      //std::cout<<"SuiteNode : eval step 3"<<std::endl;
    }
  }
  //int i=3;
  for (const Node *stmt : (*stmts))
  {
    //std::cout<<"SuiteNode : eval step "<<i++<<std::endl;
    if(stmt->IsA() == "ReturnNode")
    { 
      res = stmt->eval(scope);
      PoolOfNodes::getInstance().add(res);
      return res;
    }
    else if(stmt->IsA() == "IfElseNode")
    {  
      res = stmt->eval(scope);
      PoolOfNodes::getInstance().add(res);
      if (res != nullptr)
        return res;
    }
    else
    {
      const Literal *val = stmt->eval(scope);
      if(val!=nullptr)
          PoolOfNodes::getInstance().add(val);
    }
  }
  return res;
}

SuiteNode::~SuiteNode() 
{ 
    delete stmts;
}

const Literal * CallFunctionNode::eval(int scope) const
{
  int tempScope = -1;
  const Node* suiteNode = SymbolTable::getInstance().getSuiteNode(function, tempScope);
  const Node* paramSuite = SymbolTable::getInstance().getParamsSuite(function);
  const Literal *res;
  if(argSuite!=nullptr)
  {  
  SymbolTable::getInstance().pushScope(); 

  std::vector<Node *> *params = paramSuite->getStmtVector();
  std::vector<Node *> *values = argSuite->getStmtVector();
  AsgArguments(params, values);
  res = suiteNode->eval(scope);
  if(res != nullptr)
    PoolOfNodes::getInstance().add(res);
  SymbolTable::getInstance().popScope();
  SymbolTable::getInstance().resetTmpScope();
  }
  else
  {
    std::cout<<"second"<<std::endl;
    if(tempScope != -1)
    SymbolTable::getInstance().setTempScope(tempScope);
  SymbolTable::getInstance().pushScope(); 
  res = suiteNode->eval(scope);
  SymbolTable::getInstance().resetTmpScope();
  SymbolTable::getInstance().popScope();

  }
  return res;
}


const Node *CallFunctionNode::AsgArguments(std::vector<Node*>* params, std::vector<Node*> *values)const
{
  const Node *res = nullptr;
  int i=0;
  for (Node *param : (*params))
  {
    const Literal *rhs = nullptr;
    Node *left = param->getLeft();
    Node *right = param->getRight();
    std::string n = static_cast<IdentNode*>(left)->getIdent();
    if(right != nullptr)
      rhs = right->eval();
    if(rhs != nullptr)
    {
        SymbolTable::getInstance().setValue(n, rhs);
        PoolOfNodes::getInstance().add(rhs);
    }
  }
  for (Node *val : (*values))
  {
    const Literal *rhs = val->eval();
    Node *param = params->at(i);
    Node *left = param->getLeft();
    std::string n = static_cast<IdentNode*>(left)->getIdent();
    SymbolTable::getInstance().setValue(n, rhs);
    PoolOfNodes::getInstance().add(res);
    PoolOfNodes::getInstance().add(left);
    PoolOfNodes::getInstance().add(rhs);
    ++i;
  }
  return res;
}


const Literal *ReturnNode::eval(int scope) const
{
  const Literal *res = val->eval(scope);
  //res->print();
  //std::cout<<"Return node"<<res<<std::endl;
  return res;
}


const Literal * IfElseNode::eval(int scope) const
{
  
  /*const Literal *condition = test->eval(scope);
  const Literal *val = nullptr;
  if (condition->isTrue())
    val = ifSuite->eval(scope);
  else
    val = elseSuite->eval(scope);
  PoolOfNodes::getInstance().add(val);  
  return val;
  */ 
  if(!test)
    return 0;
  const Literal *val = nullptr;
  //SymbolTable& st = SymbolTable::getInstance();
  const Literal *condition = test->eval(scope);
  condition = dynamic_cast<const Literal*>(condition);
  if(!condition) throw std::string("could not evaluate test in ifnode");

  bool flag = condition->eval(scope)->isTrue();
  if(flag)
  {
    if(!ifSuite) throw std::string("thensuite is null");
    //st.pushScope();
    val = ifSuite->eval(scope); 
  }
  else if (!flag)
  {
    if(!elseSuite) 
      {return nullptr;}
    val = elseSuite->eval(scope);
  }
  else {throw std::string("Neither true nor flase");}
  PoolOfNodes::getInstance().add(val); 
  return val;
  }
  

const Literal* ComparisonBinaryOperation::eval(int scope) const 
{
  const Literal* x = left->eval(scope);
  const Literal* y = right->eval(scope);
  switch(operation)
  {
    case 1:
        return (*x)<(*y);
        break;
    case 2:
        return(*x>*y);
        break;
    case 3:
        return (*x==*y);
        break;
    case 4:
        return (*x>=*y);
        break;
    case 5:
        return(*x<=*y);
        break;
    case 6:
        return(*x!=*y);
        break;
    default:
        break;
    }
  return nullptr;
}
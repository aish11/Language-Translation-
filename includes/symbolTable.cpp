#include <map>
#include <algorithm>
#include "symbolTable.h"
#include "literal.h"

SymbolTable& SymbolTable::getInstance() {
  static SymbolTable instance;
  return instance;
}

/*const Literal* SymbolTable::getValue(const std::string& name) const {
  std::map<std::string, const Literal*>::const_iterator it = table.find(name);
  if ( it == table.end() ) throw name+std::string(" not found");
  return it->second;
}

void SymbolTable::setValue(const std::string& name, const Literal* val) { 
  //table[name] = val;
	std::pair<std::string, const Literal*> temp(name, val);
  std::map<std::string, const Literal*>::const_iterator it = 
    table.find(name);
  if ( it == table.end() ) 
  {
	  table.insert(temp);
  }
  else
  {
	  table[name]=val;
  }
}

*/

const Literal* SymbolTable::getValue(const std::string& name, int scope) const{
  int curr_scope = getCurrentScope();
  if(isTmpScopeSet())
  {
    while(curr_scope<=Scope){
      std::string mangled_name = std::to_string(curr_scope)+"_"+name;
      std::map<std::string, const Literal*>::const_iterator it = LiteralTable.find(mangled_name);
      if ( it == LiteralTable.end()) { 
         curr_scope++;
         if(scope == 1){
          return nullptr;
        }
      }
      else{
        return it->second;
      }
    }
    return nullptr;
  }
  else{
  while(curr_scope>=0)
  {
    std::string mangled_name = std::to_string(curr_scope)+"_"+name;
    std::map<std::string, const Literal*>::const_iterator it = LiteralTable.find(mangled_name);
    if ( it == LiteralTable.end()) 
    { 
       curr_scope--;
       if(scope == 1)
       {
        return nullptr;
      }
    }
    else
    {
      return it->second;
    }
  }
  return nullptr;
}
}

void SymbolTable::setValue(const std::string& name, const Literal* val) {

  int curr_scope = getCurrentScope();
  std::string mangled_name =  std::to_string(curr_scope) +"_"+ name ;
  std::pair<std::string, const int > scope_entry(mangled_name, curr_scope);
  std::pair<std::string, const Literal*> temp(mangled_name, val);
  std::map<std::string, const Literal*>::const_iterator it = LiteralTable.find(mangled_name);
  if ( it == LiteralTable.end() ) 
  {
    LiteralTable.insert(temp);
    //std::cout<<"value set "<<mangled_name<<std::endl;
    StackMap.insert(scope_entry);
  }
  else
  {
    LiteralTable[mangled_name]=val;
  }
}

void  SymbolTable::setFunction(const std::string&name, const Node * func)
{
  int curr_scope = getCurrentScope();
  std::string mangled_name = std::to_string(curr_scope)+"_"+name;
  std::pair<std::string, const Node*> temp(mangled_name, func);
  std::pair<std::string, const int > scope_entry(mangled_name, curr_scope);
  std::map<std::string, const Node*>::const_iterator it = FunctionTable.find(mangled_name);
  if ( it == FunctionTable.end() ) 
  {
    //std::cout<<"setFunction "<<mangled_name<<std::endl;
    FunctionTable.insert(temp);
    StackMap.insert(scope_entry);
  }
  else
  {
    FunctionTable[mangled_name]=func;
  }
}

void  SymbolTable::pushScope()
{
  Scope++;
}

void  SymbolTable::popScope()
{
  int curr_scope = Scope;
  if(Scope == 0)
    return;
  for (auto it=StackMap.begin(); it!=StackMap.end(); ++it)
  {
    if(it->second == curr_scope && curr_scope!=0)
    { 
     // std::cout<<"pop scope "<<it->first<<std::endl;
      FunctionTable.erase((it->first));
      LiteralTable.erase((it->first));
      //ParamsTable.erase((it->first));
      StackMap.erase(it->first);
    }
  }  
  Scope--;
}

int SymbolTable::getCurrentScope() const
{  
  if(tmpScope != -1)
    return tmpScope;
  else
    return Scope;
}

const Node *  SymbolTable::getSuiteNode(const std::string&name, int &tempScope) const
{
   int curr_scope = getCurrentScope();
   while(curr_scope>=0)
   {
    std::string mangled_name = std::to_string(curr_scope)+"_"+name;
    //std::cout<<"getFunction "<<mangled_name<<std::endl;
    std::map<std::string, const Node*>::const_iterator it = FunctionTable.find(mangled_name);
    if (it == FunctionTable.end()) 
    { 
       curr_scope--;
       tempScope = curr_scope;
    }
    else
    {
      return it->second;
    }
  }
  return nullptr;
}
 void  SymbolTable::setFunctionParams(const std::string&name, const Node * params)
{
  int curr_scope = getCurrentScope();
  std::string mangled_name = std::to_string(curr_scope)+"_param"+name;
  std::pair<std::string, const Node*> temp(mangled_name, params);
  std::pair<std::string, const int > scope_entry(mangled_name, curr_scope);
  std::map<std::string, const Node*>::const_iterator it = ParamsTable.find(mangled_name);
  if ( it == ParamsTable.end() ) 
  {
    ParamsTable.insert(temp);
    StackMap.insert(scope_entry);
  }
  else
  {
    ParamsTable[mangled_name]=params;
  }
}

const Node *  SymbolTable::getParamsSuite(const std::string&name) const
{
   int curr_scope = getCurrentScope();
   while(curr_scope>=0)
   {    
    std::string mangled_name = std::to_string(curr_scope)+"_param"+name;
    std::map<std::string, const Node*>::const_iterator it = ParamsTable.find(mangled_name);
    if (it == ParamsTable.end()) 
    { 
       curr_scope--;
    }
    else
    {
      return it->second;
    }
  }
  return nullptr;
}

 void SymbolTable::resetTmpScope()
 {
   tmpScope = -1;
 }

 bool SymbolTable:: isTmpScopeSet() const
 {
   if(tmpScope != -1)
     return true;
   else
    return false;
 }

 void SymbolTable::setTempScope(int val)
 {
   tmpScope = val;
 }
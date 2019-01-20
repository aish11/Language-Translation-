//#include "node.h"

#include "literal.h"
#include "poolOfNodes.h"
#include <math.h>
#include <iomanip>
#include <string.h>


  StringLiteral::StringLiteral(const std::string _val): val(_val) {
  }
  //~StringLiteral() {}
  const Literal* StringLiteral::operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  const Literal* StringLiteral::opPlus(float  ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opPlus(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opPlus(const std::string& lhs) const  {
    const Literal* node = new StringLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }


  const Literal* StringLiteral::operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  const Literal* StringLiteral::opSubt(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opSubt(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opSubt(const std::string&) const {
    throw std::string( "invalid_argument" );
  }



  const Literal* StringLiteral::operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  const Literal* StringLiteral::opMult(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opMult(int lhs) const  {
    std::string res;
    for(int i=0;i<lhs;i++)
    {
      res=res+val;
    }
    const Literal* node = new StringLiteral(res);
    PoolOfNodes::getInstance().add(node);
    return node;
    
  }
  const Literal* StringLiteral::opMult(const std::string&) const  {
  throw std::string( "invalid_argument" );
  }
  

  const Literal* StringLiteral::operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  const Literal* StringLiteral::opDiv(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opDiv(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* StringLiteral::operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  const Literal* StringLiteral::opMod(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opMod(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opMod(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }


  const Literal* StringLiteral::DoubleDiv(const Literal& rhs) const  {
    return rhs.opDoubleDiv(val);
  }
  const Literal* StringLiteral::opDoubleDiv(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opDoubleDiv(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opDoubleDiv(const std::string& ) const  {
    throw std::string( "invalid_argument" );
  }
  
  const Literal* StringLiteral::operator^(const Literal& rhs) const  {
    return rhs.opPow(val);
  }
  const Literal* StringLiteral::opPow(float ) const  {
   throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opPow(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opPow(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }
   const Literal* StringLiteral::opUnaryMinus() const
  {
    throw std::string( "invalid_argument" );
  }
  
   const Literal* StringLiteral::opUnaryPlus() const
  {
    throw std::string( "invalid_argument" );
  }


  const Literal* StringLiteral::IndexOf(const Literal& rhs) const  {
   std::cout << "StringLiteral" << std::endl;
    return rhs.opIndexOf(val);
  }
  const Literal* StringLiteral::opIndexOf(float ) const  {
    throw std::string( "invalid_argumentSF" );
  }
  const Literal* StringLiteral::opIndexOf(int lhs) const  {
    std::cout << "StringLiteral Int" << std::endl;
    char c =val.at(lhs);
    std::string s(c+"\0");
    //std::cout << s << std::endl;
    const Literal* node = new StringLiteral(s);
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  const Literal* StringLiteral::opIndexOf(const std::string& ) const  {
    throw std::string("String string");
  }

  const Literal* StringLiteral::SliceOf(const Literal& rhs ) const  {
    return rhs.opSliceOf(val);
  }
  const Literal* StringLiteral::opSliceOf(float ) const  {
    throw std::string( "invalid_argument4" );
  }
  const Literal* StringLiteral::opSliceOf(int ) const  {
    throw std::string( "invalid_argument5str" );
  }
  const Literal* StringLiteral::opSliceOf(const std::string& ) const  {
    throw std::string("string Sliceoftuple Sliceoftuple Sliceoftuple");
  }

  const Literal* StringLiteral::operator<=(const Literal& ) const  {
    //return rhs.opLesEql(val);
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opLesEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opLesEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opLesEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* StringLiteral::operator>=(const Literal& ) const  {
    //return rhs.opGrtEql(val);
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opGrtEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opGrtEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opGrtEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* StringLiteral::operator<(const Literal& ) const  {
    //return rhs.opLes(val);
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opLes(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opLes(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opLes(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
 
 const Literal* StringLiteral::operator>(const Literal& ) const  {
    //return rhs.opGrt(val);
  throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opGrt(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opGrt(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opGrt(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* StringLiteral::operator==(const Literal& ) const  {
  
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opEqlEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opEqlEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
 const Literal* StringLiteral::opEqlEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

 const Literal* StringLiteral::operator!=(const Literal& ) const  {
   // return rhs.opNotEql(val);
  throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opNotEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opNotEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* StringLiteral::opNotEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  bool StringLiteral::isTrue() const {
    /*if (val != 0) 
      return true; 
    else return false;
    */
    throw std::string( "invalid_argument" ); 
  }


  //const std::string StringLiteral::getVal() const { return val;}
  const Literal* StringLiteral::eval(int ) const { return this; }
  void StringLiteral::print() const { 
    std::cout << "STR: " << val << std::endl; 
  }







  FloatLiteral::FloatLiteral(float _val): val(_val) {}
  //~FloatLiteral() {}
  const Literal* FloatLiteral::operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  const Literal* FloatLiteral::opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  const Literal* FloatLiteral::opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opPlus(const std::string& ) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* FloatLiteral::operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  const Literal* FloatLiteral::opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opSubt(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opSubt(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* FloatLiteral::operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  const Literal* FloatLiteral::opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opMult(int lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opMult(const std::string&) const  {
   throw std::string( "invalid_argument" );
  }

  const Literal* FloatLiteral::operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  const Literal* FloatLiteral::opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opDiv(const std::string& ) const  {
    throw std::string( "invalid_argument" );
  }


  const Literal* FloatLiteral::operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  const Literal* FloatLiteral::opMod(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(fmodf(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float left = lhs;
    const Literal* node = new FloatLiteral(lhs-(val*(floor(left/val))));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  const Literal* FloatLiteral::opMod(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* FloatLiteral::DoubleDiv(const Literal& rhs) const  {
    return rhs.opDoubleDiv(val);
  }
  const Literal* FloatLiteral::opDoubleDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(float(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opDoubleDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(float(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opDoubleDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* FloatLiteral::operator^(const Literal& rhs) const  {
    return rhs.opPow(val);
  }
  const Literal* FloatLiteral::opPow(float lhs) const  {
    const Literal* node = new FloatLiteral(pow(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opPow(int lhs) const  {
    const Literal* node = new FloatLiteral(pow(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opPow(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

   const Literal* FloatLiteral::opUnaryMinus() const
  {
    const Literal* node = new FloatLiteral(-1*val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  const Literal* FloatLiteral::opUnaryPlus() const
  {
    const Literal* node = new FloatLiteral(val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  const Literal* FloatLiteral::IndexOf(const Literal& rhs) const  {
    return rhs.opIndexOf(val);
  }
  const Literal* FloatLiteral::opIndexOf(float ) const  {
    throw std::string( "invalid_argument1" );
  }
  const Literal* FloatLiteral::opIndexOf(int ) const  {
    throw std::string( "invalid_argument2" );
  }
  const Literal* FloatLiteral::opIndexOf(const std::string& ) const  {
    throw std::string( "invalid_argument3" );
  }

   
  const Literal* FloatLiteral::SliceOf(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* FloatLiteral::opSliceOf(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* FloatLiteral::opSliceOf(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* FloatLiteral::opSliceOf(const std::string& ) const  {
    throw std::string( "invalid_argument" );
  }
  
  const Literal* FloatLiteral::operator<=(const Literal&rhs) const{return rhs.opLesEql(val);}
   const Literal* FloatLiteral::opLesEql(int lhs) const
  { 
    const Literal* node;
    if(lhs<= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* FloatLiteral::opLesEql(float lhs) const
  {
    const Literal* node;
    if(lhs<= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opLesEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* FloatLiteral::operator>=(const Literal&rhs) const{return rhs.opGrtEql(val);}
   const Literal* FloatLiteral::opGrtEql(int lhs) const
  {
    const Literal* node;
    if(lhs>= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opGrtEql(float lhs) const
  {
    const Literal* node;
    if(lhs>= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opGrtEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  const Literal* FloatLiteral::operator<(const Literal&rhs) const{return rhs.opLesEql(val);}
   const Literal* FloatLiteral::opLes(int lhs) const
  {
    const Literal* node;
    if(lhs < val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opLes(float lhs) const
  {
    const Literal* node;
    if(lhs< val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opLes(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
   const Literal* FloatLiteral::operator>(const Literal&rhs) const{return rhs.opGrt(val);}
   const Literal* FloatLiteral::opGrt(int lhs) const
  {
    const Literal* node;
    if(lhs > val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opGrt(float lhs) const
  {
    const Literal* node;
    if(lhs > val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opGrt(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* FloatLiteral::operator==(const Literal&rhs) const{return rhs.opEqlEql(val);}
   const Literal* FloatLiteral::opEqlEql(int lhs) const
  {
    const Literal* node;
    if(lhs == val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 
   const Literal* FloatLiteral::opEqlEql(float lhs) const
  {
    const Literal* node;
    if(lhs == val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opEqlEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* FloatLiteral::operator!=(const Literal&rhs) const{return rhs.opNotEql(val);}
   const Literal* FloatLiteral::opNotEql(int lhs) const
  {
   const Literal* node;
    if(lhs != val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* FloatLiteral::opNotEql(float lhs) const
  {
    const Literal* node;
    if(lhs != val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* FloatLiteral::opNotEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  
  bool FloatLiteral::isTrue() const {
    if (val != 0) 
      return true; 
    else return false; 
  }


  const Literal* FloatLiteral::eval(int ) const { return this; }
  void FloatLiteral::print() const { 
    std::cout << "FLOAT: " << std::setprecision(5) << val << std::endl; 
  }


 IntLiteral::IntLiteral(int _val): val(_val) {}
  //~IntLiteral() {}
  const Literal* IntLiteral::operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  const Literal* IntLiteral::opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opPlus(int lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opPlus(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* IntLiteral::operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  const Literal* IntLiteral::opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opSubt(int lhs) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opSubt(const std::string&) const  {
  throw std::string( "invalid_argument" );
  }

  const Literal* IntLiteral::operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  const Literal* IntLiteral::opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opMult(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* IntLiteral::operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  const Literal* IntLiteral::opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float left = lhs;
    const Literal* node = new IntLiteral(floor(left / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* IntLiteral::operator%(const Literal& rhs) const  {
    return rhs.opMod(val);
  }
  const Literal* IntLiteral::opMod(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float left = lhs;
    const Literal* node = new FloatLiteral(lhs-(val*(floor(left/val))));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opMod(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float left = lhs;
    const Literal* node = new IntLiteral(lhs-(val*(floor(left/val))));
  
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opMod(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* IntLiteral::DoubleDiv(const Literal& rhs) const  {
    return rhs.opDoubleDiv(val);
  }
  const Literal* IntLiteral::opDoubleDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opDoubleDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float left = lhs;
    const Literal* node = new IntLiteral(floor(left / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opDoubleDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

   const Literal* IntLiteral::operator^(const Literal& rhs) const  {
    return rhs.opPow(val);
  }
  const Literal* IntLiteral::opPow(float lhs) const  {
    const Literal* node = new FloatLiteral(pow(lhs,val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opPow(int lhs) const  {
    const Literal* node;
    if(val<0) 
    {
       node = new FloatLiteral(pow(lhs,val));
    }
    else 
    {
      node = new IntLiteral(pow(lhs,val));
    }
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opPow(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* IntLiteral::IndexOf(const Literal& rhs) const  {
    return rhs.opIndexOf(val);
  }
  const Literal* IntLiteral::opIndexOf(float ) const  {
    throw std::string( "invalid_argument4" );
  }
  const Literal* IntLiteral::opIndexOf(int ) const  {
    throw std::string( "invalid_argument5" );
  }
  const Literal* IntLiteral::opIndexOf(const std::string& lhs) const  {
    std::cout << "Here ast" << std::endl;
    std::string x="";
    char c = lhs.at(val);
    x+=c;
    //std::string s(c+"\0");
    std::cout << lhs << " "<< val << " "<< x <<std::endl;
    const Literal* node = new StringLiteral(x);

    PoolOfNodes::getInstance().add(node);
    return node; 
  }

  const Literal* IntLiteral::SliceOf(const Literal& rhs) const  {
    return rhs.opIndexOf(val);
  }
  const Literal* IntLiteral::opSliceOf(float ) const  {
    throw std::string( "invalid_argument4" );
  }
  const Literal* IntLiteral::opSliceOf(int ) const  {
    throw std::string( "invalid_argument5int" );
  }
  const Literal* IntLiteral::opSliceOf(const std::string& lhs) const  {
    std::string x="";
    int ind=0;
    if(val<0){ind=lhs.length()+val;}
    else {ind=val;}
    char c = lhs.at(ind);
    x+=c;
    //std::string s(c+"\0");
    //std::cout << lhs << " "<< val << " "<< x <<std::endl;
    const Literal* node = new StringLiteral(x);

    PoolOfNodes::getInstance().add(node);
    return node; 
  }


  const Literal* IntLiteral::opUnaryMinus() const
  {
    const Literal* node = new IntLiteral(-1*val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opUnaryPlus() const
  {
    const Literal* node = new IntLiteral(val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  const Literal* IntLiteral::operator<=(const Literal&rhs) const{return rhs.opLesEql(val);}
   const Literal* IntLiteral::opLesEql(int lhs) const
  { 
    const Literal* node;
    if(lhs<= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* IntLiteral::opLesEql(float lhs) const
  {
    const Literal* node;
    if(lhs<= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opLesEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* IntLiteral::operator>=(const Literal&rhs) const{return rhs.opGrtEql(val);}
   const Literal* IntLiteral::opGrtEql(int lhs) const
  {
    const Literal* node;
    if(lhs>= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opGrtEql(float lhs) const
  {
    const Literal* node;
    if(lhs>= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opGrtEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  const Literal* IntLiteral::operator<(const Literal&rhs) const{return rhs.opLesEql(val);}
   const Literal* IntLiteral::opLes(int lhs) const
  {
    const Literal* node;
    if(lhs < val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opLes(float lhs) const
  {
    const Literal* node;
    if(lhs< val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opLes(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
   const Literal* IntLiteral::operator>(const Literal&rhs) const{return rhs.opGrt(val);}
   const Literal* IntLiteral::opGrt(int lhs) const
  {
    const Literal* node;
    if(lhs > val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opGrt(float lhs) const
  {
    const Literal* node;
    if(lhs > val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opGrt(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* IntLiteral::operator==(const Literal&rhs) const{return rhs.opEqlEql(val);}
   const Literal* IntLiteral::opEqlEql(int lhs) const
  {
    const Literal* node;
    if(lhs == val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 
   const Literal* IntLiteral::opEqlEql(float lhs) const
  {
    const Literal* node;
    if(lhs == val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opEqlEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* IntLiteral::operator!=(const Literal&rhs) const{return rhs.opNotEql(val);}
   const Literal* IntLiteral::opNotEql(int lhs) const
  {
   const Literal* node;
    if(lhs != val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* IntLiteral::opNotEql(float lhs) const
  {
    const Literal* node;
    if(lhs != val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* IntLiteral::opNotEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  
  bool IntLiteral::isTrue() const {
    if (val != 0) 
      return true; 
    else return false; 
  }

 //int IntLiteral::getVal() const { return val;}
  const Literal* IntLiteral::eval(int ) const { return this; }
  void IntLiteral::print() const { 
    std::cout << "INT: " << std::setprecision(5) << val << std::endl; 
  }



 BooleanLiteral::BooleanLiteral(int val): val(val) {}
  //~BooleanLiteral() {}
  const Literal* BooleanLiteral::operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  const Literal* BooleanLiteral::opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(val + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opPlus(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* BooleanLiteral::operator-(const Literal& rhs) const  {
   return rhs.opSubt(val);
  }
  const Literal* BooleanLiteral::opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opSubt(int lhs ) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opSubt(const std::string& ) const  {
  throw std::string( "invalid_argument" );
  }

  const Literal* BooleanLiteral::operator*(const Literal& rhs) const  {
  return rhs.opMult(val);
  }
  const Literal* BooleanLiteral::opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opMult(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* BooleanLiteral::operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  const Literal* BooleanLiteral::opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float left = lhs;
    const Literal* node = new IntLiteral(floor(left / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* BooleanLiteral::operator%(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opMod(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opMod(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opMod(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* BooleanLiteral::DoubleDiv(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opDoubleDiv(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opDoubleDiv(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opDoubleDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

   const Literal* BooleanLiteral::operator^(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opPow(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opPow(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opPow(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* BooleanLiteral::IndexOf(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opIndexOf(float ) const  {
    throw std::string( "invalid_argument4" );
  }
  const Literal* BooleanLiteral::opIndexOf(int ) const  {
    throw std::string( "invalid_argument5" );
  }
  const Literal* BooleanLiteral::opIndexOf(const std::string& ) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* BooleanLiteral::SliceOf(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opSliceOf(float ) const  {
    throw std::string( "invalid_argument4" );
  }
  const Literal* BooleanLiteral::opSliceOf(int ) const  {
    throw std::string( "invalid_argument5int" );
  }
  const Literal* BooleanLiteral::opSliceOf(const std::string& ) const  {
    throw std::string( "invalid_argument" );
  }


  const Literal* BooleanLiteral::opUnaryMinus() const
  {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::opUnaryPlus() const
  {
    throw std::string( "invalid_argument" );
  }
 
 const Literal* BooleanLiteral::operator<=(const Literal&rhs) const{return rhs.opLesEql(val);}
   const Literal* BooleanLiteral::opLesEql(int lhs) const
  { 
    const Literal* node;
    if(lhs<= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }

   const Literal* BooleanLiteral::opLesEql(float lhs) const
  {
    const Literal* node;
    if(lhs<= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opLesEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* BooleanLiteral::operator>=(const Literal&rhs) const{return rhs.opGrtEql(val);}
   const Literal* BooleanLiteral::opGrtEql(int lhs) const
  {
    const Literal* node;
    if(lhs>= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* BooleanLiteral::opGrtEql(float lhs) const
  {
    const Literal* node;
    if(lhs>= val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opGrtEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  const Literal* BooleanLiteral::operator<(const Literal&rhs) const{return rhs.opLesEql(val);}
   const Literal* BooleanLiteral::opLes(int lhs) const
  {
    const Literal* node;
    if(lhs < val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* BooleanLiteral::opLes(float lhs) const
  {
    const Literal* node;
    if(lhs< val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opLes(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
   const Literal* BooleanLiteral::operator>(const Literal&rhs) const{return rhs.opGrt(val);}
   const Literal* BooleanLiteral::opGrt(int lhs) const
  {
    const Literal* node;
    if(lhs > val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* BooleanLiteral::opGrt(float lhs) const
  {
    const Literal* node;
    if(lhs > val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opGrt(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* BooleanLiteral::operator==(const Literal&rhs) const{return rhs.opEqlEql(val);}
   const Literal* BooleanLiteral::opEqlEql(int lhs) const
  {
    const Literal* node;
    if(lhs == val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
 
   const Literal* BooleanLiteral::opEqlEql(float lhs) const
  {
    const Literal* node;
    if(lhs == val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opEqlEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

   const Literal* BooleanLiteral::operator!=(const Literal&rhs) const{return rhs.opNotEql(val);}
   const Literal* BooleanLiteral::opNotEql(int lhs) const
  {
   const Literal* node;
    if(lhs != val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
   const Literal* BooleanLiteral::opNotEql(float lhs) const
  {
    const Literal* node;
    if(lhs != val)
    {node = new BooleanLiteral(1);}
    else 
    {node = new BooleanLiteral(0);}
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  const Literal* BooleanLiteral::opNotEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  bool BooleanLiteral::isTrue() const {
    if (val != 0) 
      return true; 
    else return false; 
  }


  const Literal* BooleanLiteral::eval(int ) const { return new IntLiteral(val);  }
  void BooleanLiteral::print() const { 
    std::string boolean = "true";
    if (val==0)
      boolean = "false";
    std::cout << "BOOLEAN: "<<boolean << std::endl; 
  }


 TupleLiteral::TupleLiteral(IntLiteral _val1, IntLiteral _val2): val1(_val1),val2(_val2) {}
//~TupleLiteral() {}
  const Literal* TupleLiteral::operator+(const Literal& ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opPlus(float ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opPlus(int ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opPlus(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::operator-(const Literal& ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opSubt(float ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opSubt(int ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opSubt(const std::string&) const  {
  throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::operator*(const Literal& ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opMult(float ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opMult(int ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opMult(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::operator/(const Literal& ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opDiv(float ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opDiv(int ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::operator%(const Literal& ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opMod(float ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opMod(int ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opMod(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::DoubleDiv(const Literal& ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opDoubleDiv(float ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opDoubleDiv(int ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opDoubleDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

   const Literal* TupleLiteral::operator^(const Literal& ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opPow(float ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opPow(int ) const  {
     throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opPow(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::IndexOf(const Literal& ) const  {
    throw std::string( "invalid_argument5" );

  }
  const Literal* TupleLiteral::opIndexOf(float ) const  {
    throw std::string( "invalid_argument4" );
  }
  const Literal* TupleLiteral::opIndexOf(int ) const  {
    throw std::string( "invalid_argument5" );
  }
  const Literal* TupleLiteral::opIndexOf(const std::string& ) const  {
    throw std::string( "invalid_argument5" );
  }

  const Literal* TupleLiteral::SliceOf(const Literal& ) const  {
    //return rhs.opSliceOf(val1,val2);
    throw std::string( "invalid_argument5" );

  }
  const Literal* TupleLiteral::opSliceOf(float ) const  {
    throw std::string( "invalid_argument4" );
  }
  const Literal* TupleLiteral::opSliceOf(int ) const  {
    throw std::string( "invalid_argument5" );
  }
  const Literal* TupleLiteral::opSliceOf(const std::string&  ) const  {
     throw std::string( "invalid_argument5" );
   /*
   std::string x="";
   //if(first==null)

   int first = val1.getVal();
   int last = val2.getVal();

   std::cout<<first<<std::endl;
   std::cout<<last<<std::endl;
   //int increment = val3.getVal();
   //std::cout<<increment<<std::endl;
   int len = lhs.length();
   if(first<0)
   {
    first=len+first;
   // std::cout<<first<<std::endl;
   }
   if(last<0)
    {
      last=len+last;
    //  std::cout<<last<<std::endl;
    }

    for(int i = first;i<last;i++)
    {  
    char c = lhs.at(i);
    x+=c;
    }
    first=0;
    last=0;
    const Literal* node = new StringLiteral(x);
    PoolOfNodes::getInstance().add(node);
    return node;
    */
  }

  const Literal* TupleLiteral::opUnaryMinus() const
  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opUnaryPlus() const
  {
    throw std::string( "invalid_argument" );
  }
 
  const Literal* TupleLiteral::operator<=(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opLesEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opLesEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opLesEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::operator>=(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opGrtEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opGrtEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opGrtEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::operator<(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opLes(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opLes(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opLes(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
 
 const Literal* TupleLiteral::operator>(const Literal& ) const  {
   throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opGrt(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opGrt(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opGrt(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* TupleLiteral::operator==(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opEqlEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opEqlEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opEqlEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
 
 const Literal* TupleLiteral::operator!=(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opNotEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opNotEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* TupleLiteral::opNotEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  
  bool TupleLiteral::isTrue() const {
    throw std::string( "invalid_argument" );
  }


  const Literal* TupleLiteral::eval(int ) const { return this; }
  void TupleLiteral::print() const { 
    //std::cout << "INT: " << val1 << std::endl; 
  }



 NoneLiteral::NoneLiteral(){}
  const Literal* NoneLiteral::operator+(const Literal& ) const  {return this;}
  const Literal* NoneLiteral::opPlus(float ) const  { return this;}
  const Literal* NoneLiteral::opPlus(int ) const  {return this;}
  const Literal* NoneLiteral::opPlus(const std::string&) const  {throw std::string( "invalid_argument" );}

  const Literal* NoneLiteral::operator-(const Literal& ) const  {return this;}
  const Literal* NoneLiteral::opSubt(float ) const  { return this;}
  const Literal* NoneLiteral::opSubt(int ) const  { return this; }
  const Literal* NoneLiteral::opSubt(const std::string&) const  { throw std::string( "invalid_argument" );}

  const Literal* NoneLiteral::operator*(const Literal& ) const  {return this;}
  const Literal* NoneLiteral::opMult(float ) const  { return this;}
  const Literal* NoneLiteral::opMult(int ) const  { return this; }
  const Literal* NoneLiteral::opMult(const std::string&) const  {throw std::string( "invalid_argument" );}

  const Literal* NoneLiteral::operator/(const Literal& ) const  { return this;}
  const Literal* NoneLiteral::opDiv(float ) const  { return this;}
  const Literal* NoneLiteral::opDiv(int ) const  { return this;}
  const Literal* NoneLiteral::opDiv(const std::string&) const  {throw std::string( "invalid_argument" );}

  const Literal* NoneLiteral::operator%(const Literal& ) const  {return this;}
  const Literal* NoneLiteral::opMod(float ) const  { return this; }
  const Literal* NoneLiteral::opMod(int ) const  {return this;}
  const Literal* NoneLiteral::opMod(const std::string&) const  {throw std::string( "invalid_argument" );}

  const Literal* NoneLiteral::DoubleDiv(const Literal& ) const  {return this;}
  const Literal* NoneLiteral::opDoubleDiv(float ) const  { return this;}
  const Literal* NoneLiteral::opDoubleDiv(int ) const  { return this;}
  const Literal* NoneLiteral::opDoubleDiv(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* NoneLiteral::operator^(const Literal& ) const  { return this;}
  const Literal* NoneLiteral::opPow(float ) const  { return this;}
  const Literal* NoneLiteral::opPow(int ) const  { return this;}
  const Literal* NoneLiteral::opPow(const std::string&) const  {
    throw std::string( "invalid_argument" );
  }

  const Literal* NoneLiteral::IndexOf(const Literal& ) const  { return this;}
  const Literal* NoneLiteral::opIndexOf(float ) const  { return this;}
  const Literal* NoneLiteral::opIndexOf(int ) const  { return this;}
  const Literal* NoneLiteral::opIndexOf(const std::string& ) const  { return this;}

  const Literal* NoneLiteral::SliceOf(const Literal& ) const  { return this;}
  const Literal* NoneLiteral::opSliceOf(float ) const  { return this;}
  const Literal* NoneLiteral::opSliceOf(int ) const  { return this;}
  const Literal* NoneLiteral::opSliceOf(const std::string& ) const  { return this;}

  const Literal* NoneLiteral::opUnaryMinus() const
  {
   return this;
  }
  const Literal* NoneLiteral::opUnaryPlus() const
  { return this;}


 
  const Literal* NoneLiteral::operator<=(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opLesEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opLesEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opLesEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* NoneLiteral::operator>=(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opGrtEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opGrtEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opGrtEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* NoneLiteral::operator<(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opLes(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opLes(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opLes(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
 
 const Literal* NoneLiteral::operator>(const Literal& ) const  {
   throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opGrt(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opGrt(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opGrt(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }

  const Literal* NoneLiteral::operator==(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opEqlEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opEqlEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opEqlEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
 
 const Literal* NoneLiteral::operator!=(const Literal& ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opNotEql(float ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opNotEql(int ) const  {
    throw std::string( "invalid_argument" );
  }
  const Literal* NoneLiteral::opNotEql(const std::string& ) const {
    throw std::string( "invalid_argument" );
  }
  
  bool NoneLiteral::isTrue() const {
    return false;
  }

  const Literal* NoneLiteral::eval(int ) const { return this; }
   void NoneLiteral::print() const { 
    std::cout << "None"<<std::endl;  
  }

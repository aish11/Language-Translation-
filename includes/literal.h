//#ifndef LITERAL__H
//#define LITERAL__H

#pragma once
#include "node.h"
extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+(const Literal& rhs) const =0;
  virtual const Literal* opPlus(float) const =0;
  virtual const Literal* opPlus(int) const =0;
  virtual const Literal* opPlus(const std::string&) const =0;

  virtual const Literal* operator*(const Literal& rhs) const =0;
  virtual const Literal* opMult(float) const =0;
  virtual const Literal* opMult(int) const =0;
  virtual const Literal* opMult(const std::string&) const =0;

  virtual const Literal* operator-(const Literal& rhs) const =0;
  virtual const Literal* opSubt(float) const =0;
  virtual const Literal* opSubt(int) const =0;
  virtual const Literal* opSubt(const std::string&) const =0;

  virtual const Literal* operator/(const Literal& rhs) const =0 ;
  virtual const Literal* opDiv(float) const =0 ;
  virtual const Literal* opDiv(int) const =0 ;
  virtual const Literal* opDiv(const std::string&) const =0;


  virtual const Literal* operator%(const Literal& rhs) const =0;
  virtual const Literal* opMod(float) const =0;
  virtual const Literal* opMod(int) const =0;
  virtual const Literal* opMod(const std::string&) const =0;
  
  virtual const Literal* DoubleDiv(const Literal& rhs) const =0 ;
  virtual const Literal* opDoubleDiv(float) const =0;
  virtual const Literal* opDoubleDiv(int) const =0;
  virtual const Literal* opDoubleDiv(const std::string&) const =0;

  virtual const Literal* operator^(const Literal& rhs) const =0;
  virtual const Literal* opPow(float) const =0;
  virtual const Literal* opPow(int) const =0;
  virtual const Literal* opPow(const std::string&) const =0;

  virtual const Literal* IndexOf(const Literal& rhs) const =0 ;
  virtual const Literal* opIndexOf(float) const =0;
  virtual const Literal* opIndexOf(int) const =0;
  virtual const Literal* opIndexOf(const std::string&) const =0;

  virtual const Literal* SliceOf(const Literal& rhs) const =0 ;
  virtual const Literal* opSliceOf(float) const =0;
  virtual const Literal* opSliceOf(int) const =0;
  virtual const Literal* opSliceOf(const std::string&) const =0;

  virtual const Literal* opUnaryMinus() const =0;
  virtual const Literal* opUnaryPlus() const =0;

  virtual const Literal* operator<=(const Literal&rhs) const =0;
  virtual const Literal* opLesEql(int ) const =0;
  virtual const Literal* opLesEql(float ) const =0;
  virtual const Literal* opLesEql(const std::string& ) const =0;

  virtual const Literal* operator>=(const Literal&rhs) const =0;
  virtual const Literal* opGrtEql(int ) const =0; 
  virtual const Literal* opGrtEql(float ) const =0;
  virtual const Literal* opGrtEql(const std::string& ) const =0;

  virtual const Literal* operator<(const Literal&rhs) const =0;
  virtual const Literal* opLes(int ) const =0;
  virtual const Literal* opLes(float ) const =0;
  virtual const Literal* opLes(const std::string& ) const =0;

  virtual const Literal* operator>(const Literal&rhs) const =0;
  virtual const Literal* opGrt(int ) const =0;
  virtual const Literal* opGrt(float ) const =0;
  virtual const Literal* opGrt(const std::string& ) const =0;

  virtual const Literal* operator==(const Literal&rhs)const =0;
  virtual const Literal* opEqlEql(float ) const =0;
  virtual const Literal* opEqlEql(int )const =0;
  virtual const Literal* opEqlEql(const std::string& ) const =0;

  virtual const Literal* operator!=(const Literal&rhs) const =0;
  virtual const Literal* opNotEql(int ) const =0;
  virtual const Literal* opNotEql(float ) const =0;
  virtual const Literal* opNotEql(const std::string& ) const =0;
  virtual bool isTrue() const =0;


  
  virtual const Literal* eval(int scope = 0) const =0;
  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};

class StringLiteral: public Literal {
public:
  
  StringLiteral(std::string _val);
  virtual ~StringLiteral() {}
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;
  virtual const Literal* opPlus(const std::string&) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;
  virtual const Literal* opMult(const std::string&) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;
  virtual const Literal* opSubt(const std::string&) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  virtual const Literal* opDiv(const std::string&) const;


  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  virtual const Literal* opMod(const std::string&) const;
  
  virtual const Literal* DoubleDiv(const Literal& rhs) const;
  virtual const Literal* opDoubleDiv(float) const;
  virtual const Literal* opDoubleDiv(int) const;
  virtual const Literal* opDoubleDiv(const std::string&) const;

  virtual const Literal* operator^(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
  virtual const Literal* opPow(int) const;
  virtual const Literal* opPow(const std::string&) const;

  virtual const Literal* IndexOf(const Literal& rhs) const;
  virtual const Literal* opIndexOf(float) const;
  virtual const Literal* opIndexOf(int) const;
  virtual const Literal* opIndexOf(const std::string&) const;

  virtual const Literal* SliceOf(const Literal& rhs) const;
  virtual const Literal* opSliceOf(float) const;
  virtual const Literal* opSliceOf(int) const;
  virtual const Literal* opSliceOf(const std::string&) const;

  virtual const Literal* opUnaryMinus() const;
  virtual const Literal* opUnaryPlus() const;

  virtual const Literal* operator<=(const Literal&rhs) const;
  virtual const Literal* opLesEql(int ) const;
  virtual const Literal* opLesEql(float ) const;
  virtual const Literal* opLesEql(const std::string& ) const;

  virtual const Literal* operator>=(const Literal&rhs) const;
  virtual const Literal* opGrtEql(int ) const; 
  virtual const Literal* opGrtEql(float ) const;
  virtual const Literal* opGrtEql(const std::string& ) const;

  virtual const Literal* operator<(const Literal&rhs) const;
  virtual const Literal* opLes(int ) const;
  virtual const Literal* opLes(float ) const;
  virtual const Literal* opLes(const std::string& ) const;

  virtual const Literal* operator>(const Literal&rhs) const;
  virtual const Literal* opGrt(int ) const;
  virtual const Literal* opGrt(float ) const;
  virtual const Literal* opGrt(const std::string& ) const;

  virtual const Literal* operator==(const Literal&rhs)const;
  virtual const Literal* opEqlEql(float ) const;
  virtual const Literal* opEqlEql(int )const;
  virtual const Literal* opEqlEql(const std::string& ) const;

  virtual const Literal* operator!=(const Literal&rhs) const;
  virtual const Literal* opNotEql(int ) const;
  virtual const Literal* opNotEql(float ) const;
  virtual const Literal* opNotEql(const std::string& ) const;
  virtual bool isTrue() const;


  
  virtual const Literal* eval(int scope = 0) const;
  virtual void print() const;
private:
  std::string val;
};


class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val);
  virtual ~FloatLiteral() {}
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;
  virtual const Literal* opPlus(const std::string&) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;
  virtual const Literal* opMult(const std::string&) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;
  virtual const Literal* opSubt(const std::string&) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  virtual const Literal* opDiv(const std::string&) const;


  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  virtual const Literal* opMod(const std::string&) const;
  
  virtual const Literal* DoubleDiv(const Literal& rhs) const;
  virtual const Literal* opDoubleDiv(float) const;
  virtual const Literal* opDoubleDiv(int) const;
  virtual const Literal* opDoubleDiv(const std::string&) const;

  virtual const Literal* operator^(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
  virtual const Literal* opPow(int) const;
  virtual const Literal* opPow(const std::string&) const;

  virtual const Literal* IndexOf(const Literal& rhs) const;
  virtual const Literal* opIndexOf(float) const;
  virtual const Literal* opIndexOf(int) const;
  virtual const Literal* opIndexOf(const std::string&) const;

  virtual const Literal* SliceOf(const Literal& rhs) const;
  virtual const Literal* opSliceOf(float) const;
  virtual const Literal* opSliceOf(int) const;
  virtual const Literal* opSliceOf(const std::string&) const;

  virtual const Literal* opUnaryMinus() const;
  virtual const Literal* opUnaryPlus() const;

  virtual const Literal* operator<=(const Literal&rhs) const;
  virtual const Literal* opLesEql(int ) const;
  virtual const Literal* opLesEql(float ) const;
  virtual const Literal* opLesEql(const std::string& ) const;

  virtual const Literal* operator>=(const Literal&rhs) const;
  virtual const Literal* opGrtEql(int ) const; 
  virtual const Literal* opGrtEql(float ) const;
  virtual const Literal* opGrtEql(const std::string& ) const;

  virtual const Literal* operator<(const Literal&rhs) const;
  virtual const Literal* opLes(int ) const;
  virtual const Literal* opLes(float ) const;
  virtual const Literal* opLes(const std::string& ) const;

  virtual const Literal* operator>(const Literal&rhs) const;
  virtual const Literal* opGrt(int ) const;
  virtual const Literal* opGrt(float ) const;
  virtual const Literal* opGrt(const std::string& ) const;

  virtual const Literal* operator==(const Literal&rhs)const;
  virtual const Literal* opEqlEql(float ) const;
  virtual const Literal* opEqlEql(int )const;
  virtual const Literal* opEqlEql(const std::string& ) const;

  virtual const Literal* operator!=(const Literal&rhs) const;
  virtual const Literal* opNotEql(int ) const;
  virtual const Literal* opNotEql(float ) const;
  virtual const Literal* opNotEql(const std::string& ) const;
  virtual bool isTrue() const;


  
  virtual const Literal* eval(int scope = 0) const;
  virtual void print() const;
private:
  float val;
};




class IntLiteral: public Literal {
public:
  IntLiteral(int _val);
  virtual ~IntLiteral() {}
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;
  virtual const Literal* opPlus(const std::string&) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;
  virtual const Literal* opMult(const std::string&) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;
  virtual const Literal* opSubt(const std::string&) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  virtual const Literal* opDiv(const std::string&) const;


  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  virtual const Literal* opMod(const std::string&) const;
  
  virtual const Literal* DoubleDiv(const Literal& rhs) const;
  virtual const Literal* opDoubleDiv(float) const;
  virtual const Literal* opDoubleDiv(int) const;
  virtual const Literal* opDoubleDiv(const std::string&) const;

  virtual const Literal* operator^(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
  virtual const Literal* opPow(int) const;
  virtual const Literal* opPow(const std::string&) const;

  virtual const Literal* IndexOf(const Literal& rhs) const;
  virtual const Literal* opIndexOf(float) const;
  virtual const Literal* opIndexOf(int) const;
  virtual const Literal* opIndexOf(const std::string&) const;

  virtual const Literal* SliceOf(const Literal& rhs) const;
  virtual const Literal* opSliceOf(float) const;
  virtual const Literal* opSliceOf(int) const;
  virtual const Literal* opSliceOf(const std::string&) const;

  virtual const Literal* opUnaryMinus() const;
  virtual const Literal* opUnaryPlus() const;

  virtual const Literal* operator<=(const Literal&rhs) const;
  virtual const Literal* opLesEql(int ) const;
  virtual const Literal* opLesEql(float ) const;
  virtual const Literal* opLesEql(const std::string& ) const;

  virtual const Literal* operator>=(const Literal&rhs) const;
  virtual const Literal* opGrtEql(int ) const; 
  virtual const Literal* opGrtEql(float ) const;
  virtual const Literal* opGrtEql(const std::string& ) const;

  virtual const Literal* operator<(const Literal&rhs) const;
  virtual const Literal* opLes(int ) const;
  virtual const Literal* opLes(float ) const;
  virtual const Literal* opLes(const std::string& ) const;

  virtual const Literal* operator>(const Literal&rhs) const;
  virtual const Literal* opGrt(int ) const;
  virtual const Literal* opGrt(float ) const;
  virtual const Literal* opGrt(const std::string& ) const;

  virtual const Literal* operator==(const Literal&rhs)const;
  virtual const Literal* opEqlEql(float ) const;
  virtual const Literal* opEqlEql(int )const;
  virtual const Literal* opEqlEql(const std::string& ) const;

  virtual const Literal* operator!=(const Literal&rhs) const;
  virtual const Literal* opNotEql(int ) const;
  virtual const Literal* opNotEql(float ) const;
  virtual const Literal* opNotEql(const std::string& ) const;
  virtual bool isTrue() const;


  
  virtual const Literal* eval(int scope = 0) const;
  virtual void print() const;
private:
  int val;
};

class BooleanLiteral: public Literal {
public:
  
  BooleanLiteral(int val);
  virtual ~BooleanLiteral() {}
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;
  virtual const Literal* opPlus(const std::string&) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;
  virtual const Literal* opMult(const std::string&) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;
  virtual const Literal* opSubt(const std::string&) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  virtual const Literal* opDiv(const std::string&) const;


  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  virtual const Literal* opMod(const std::string&) const;
  
  virtual const Literal* DoubleDiv(const Literal& rhs) const;
  virtual const Literal* opDoubleDiv(float) const;
  virtual const Literal* opDoubleDiv(int) const;
  virtual const Literal* opDoubleDiv(const std::string&) const;

  virtual const Literal* operator^(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
  virtual const Literal* opPow(int) const;
  virtual const Literal* opPow(const std::string&) const;

  virtual const Literal* IndexOf(const Literal& rhs) const;
  virtual const Literal* opIndexOf(float) const;
  virtual const Literal* opIndexOf(int) const;
  virtual const Literal* opIndexOf(const std::string&) const;

  virtual const Literal* SliceOf(const Literal& rhs) const;
  virtual const Literal* opSliceOf(float) const;
  virtual const Literal* opSliceOf(int) const;
  virtual const Literal* opSliceOf(const std::string&) const;

  virtual const Literal* opUnaryMinus() const;
  virtual const Literal* opUnaryPlus() const;

  virtual const Literal* operator<=(const Literal&rhs) const;
  virtual const Literal* opLesEql(int ) const;
  virtual const Literal* opLesEql(float ) const;
  virtual const Literal* opLesEql(const std::string& ) const;

  virtual const Literal* operator>=(const Literal&rhs) const;
  virtual const Literal* opGrtEql(int ) const; 
  virtual const Literal* opGrtEql(float ) const;
  virtual const Literal* opGrtEql(const std::string& ) const;

  virtual const Literal* operator<(const Literal&rhs) const;
  virtual const Literal* opLes(int ) const;
  virtual const Literal* opLes(float ) const;
  virtual const Literal* opLes(const std::string& ) const;

  virtual const Literal* operator>(const Literal&rhs) const;
  virtual const Literal* opGrt(int ) const;
  virtual const Literal* opGrt(float ) const;
  virtual const Literal* opGrt(const std::string& ) const;

  virtual const Literal* operator==(const Literal&rhs)const;
  virtual const Literal* opEqlEql(float ) const;
  virtual const Literal* opEqlEql(int )const;
  virtual const Literal* opEqlEql(const std::string& ) const;

  virtual const Literal* operator!=(const Literal&rhs) const;
  virtual const Literal* opNotEql(int ) const;
  virtual const Literal* opNotEql(float ) const;
  virtual const Literal* opNotEql(const std::string& ) const;
  virtual bool isTrue() const;


  
  virtual const Literal* eval(int scope = 0) const;
  virtual void print() const;
private:
  int val;
};

class TupleLiteral: public Literal {
public:
  
  TupleLiteral(IntLiteral _val1, IntLiteral _val2 );
  virtual ~TupleLiteral() {}
  virtual const Literal* operator+(const Literal& rhs) const;
  virtual const Literal* opPlus(float) const;
  virtual const Literal* opPlus(int) const;
  virtual const Literal* opPlus(const std::string&) const;

  virtual const Literal* operator*(const Literal& rhs) const;
  virtual const Literal* opMult(float) const;
  virtual const Literal* opMult(int) const;
  virtual const Literal* opMult(const std::string&) const;

  virtual const Literal* operator-(const Literal& rhs) const;
  virtual const Literal* opSubt(float) const;
  virtual const Literal* opSubt(int) const;
  virtual const Literal* opSubt(const std::string&) const;

  virtual const Literal* operator/(const Literal& rhs) const;
  virtual const Literal* opDiv(float) const;
  virtual const Literal* opDiv(int) const;
  virtual const Literal* opDiv(const std::string&) const;


  virtual const Literal* operator%(const Literal& rhs) const;
  virtual const Literal* opMod(float) const;
  virtual const Literal* opMod(int) const;
  virtual const Literal* opMod(const std::string&) const;
  
  virtual const Literal* DoubleDiv(const Literal& rhs) const;
  virtual const Literal* opDoubleDiv(float) const;
  virtual const Literal* opDoubleDiv(int) const;
  virtual const Literal* opDoubleDiv(const std::string&) const;

  virtual const Literal* operator^(const Literal& rhs) const;
  virtual const Literal* opPow(float) const;
  virtual const Literal* opPow(int) const;
  virtual const Literal* opPow(const std::string&) const;

  virtual const Literal* IndexOf(const Literal& rhs) const;
  virtual const Literal* opIndexOf(float) const;
  virtual const Literal* opIndexOf(int) const;
  virtual const Literal* opIndexOf(const std::string&) const;

  virtual const Literal* SliceOf(const Literal& rhs) const;
  virtual const Literal* opSliceOf(float) const;
  virtual const Literal* opSliceOf(int) const;
  virtual const Literal* opSliceOf(const std::string&) const;

  virtual const Literal* opUnaryMinus() const;
  virtual const Literal* opUnaryPlus() const;

  virtual const Literal* operator<=(const Literal&rhs) const;
  virtual const Literal* opLesEql(int ) const;
  virtual const Literal* opLesEql(float ) const;
  virtual const Literal* opLesEql(const std::string& ) const;

  virtual const Literal* operator>=(const Literal&rhs) const;
  virtual const Literal* opGrtEql(int ) const; 
  virtual const Literal* opGrtEql(float ) const;
  virtual const Literal* opGrtEql(const std::string& ) const;

  virtual const Literal* operator<(const Literal&rhs) const;
  virtual const Literal* opLes(int ) const;
  virtual const Literal* opLes(float ) const;
  virtual const Literal* opLes(const std::string& ) const;

  virtual const Literal* operator>(const Literal&rhs) const;
  virtual const Literal* opGrt(int ) const;
  virtual const Literal* opGrt(float ) const;
  virtual const Literal* opGrt(const std::string& ) const;

  virtual const Literal* operator==(const Literal&rhs)const;
  virtual const Literal* opEqlEql(float ) const;
  virtual const Literal* opEqlEql(int )const;
  virtual const Literal* opEqlEql(const std::string& ) const;

  virtual const Literal* operator!=(const Literal&rhs) const;
  virtual const Literal* opNotEql(int ) const;
  virtual const Literal* opNotEql(float ) const;
  virtual const Literal* opNotEql(const std::string& ) const;
  virtual bool isTrue() const;


  
  virtual const Literal* eval(int scope = 0) const;
  virtual void print() const;
private:
  IntLiteral val1;
  IntLiteral val2;
};


class NoneLiteral: public Literal {
public:
 NoneLiteral();
 virtual ~NoneLiteral() {}
  virtual const Literal* operator+(const Literal& ) const;
  virtual const Literal* opPlus(float ) const;
  virtual const Literal* opPlus(int ) const;
  virtual const Literal* opPlus(const std::string&) const;

  virtual const Literal* operator-(const Literal& ) const;
  virtual const Literal* opSubt(float ) const;
  virtual const Literal* opSubt(int ) const;
  virtual const Literal* opSubt(const std::string&) const;

  virtual const Literal* operator*(const Literal& ) const;
  virtual const Literal* opMult(float ) const;
  virtual const Literal* opMult(int ) const;
  virtual const Literal* opMult(const std::string&) const;

  virtual const Literal* operator/(const Literal& ) const;
  virtual const Literal* opDiv(float ) const;
  virtual const Literal* opDiv(int ) const;
  virtual const Literal* opDiv(const std::string&) const;

  virtual const Literal* operator%(const Literal& ) const;
  virtual const Literal* opMod(float ) const;
  virtual const Literal* opMod(int ) const;
  virtual const Literal* opMod(const std::string&) const;

  virtual const Literal* DoubleDiv(const Literal& ) const;
  virtual const Literal* opDoubleDiv(float ) const;
  virtual const Literal* opDoubleDiv(int ) const;
  virtual const Literal* opDoubleDiv(const std::string&) const ;

  virtual const Literal* operator^(const Literal& ) const;
  virtual const Literal* opPow(float ) const;
  virtual const Literal* opPow(int ) const;
  virtual const Literal* opPow(const std::string&) const ;

  virtual const Literal* IndexOf(const Literal& ) const;
  virtual const Literal* opIndexOf(float ) const;
  virtual const Literal* opIndexOf(int ) const;
  virtual const Literal* opIndexOf(const std::string& ) const;

  virtual const Literal* SliceOf(const Literal& ) const;
  virtual const Literal* opSliceOf(float ) const;
  virtual const Literal* opSliceOf(int ) const;
  virtual const Literal* opSliceOf(const std::string& ) const;

  virtual const Literal* opUnaryMinus() const;
  virtual const Literal* opUnaryPlus() const;
  virtual const Literal* operator<=(const Literal& ) const;
  virtual const Literal* opLesEql(float ) const  ;
  virtual const Literal* opLesEql(int ) const  ;
  virtual const Literal* opLesEql(const std::string& ) const ;

  virtual const Literal* operator>=(const Literal& ) const  ;
  virtual const Literal* opGrtEql(float ) const ;
  virtual const Literal* opGrtEql(int ) const ;
  virtual const Literal* opGrtEql(const std::string& ) const;

  virtual const Literal* operator<(const Literal& ) const ;
  virtual const Literal* opLes(float ) const ;
  virtual const Literal* opLes(int ) const ;
  virtual const Literal* opLes(const std::string& ) const;
 
 virtual const Literal* operator>(const Literal& ) const;
  virtual const Literal* opGrt(float ) const ;
  virtual const Literal* opGrt(int ) const ;
  virtual const Literal* opGrt(const std::string& ) const;

  virtual const Literal* operator==(const Literal& ) const ;
  virtual const Literal* opEqlEql(float ) const ;
  virtual const Literal* opEqlEql(int ) const ;
  virtual const Literal* opEqlEql(const std::string& ) const;
 
 virtual const Literal* operator!=(const Literal& ) const ;
  virtual const Literal* opNotEql(float ) const ;
  virtual const Literal* opNotEql(int ) const ;
  virtual const Literal* opNotEql(const std::string& ) const;
  
  virtual bool isTrue() const;

  virtual const Literal* eval(int ) const;
  virtual void print() const;
};
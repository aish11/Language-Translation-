// Generated by transforming |cwd:///work-in-progress/2.7.2-bisonified.y| on 2016-11-23 at 15:46:56 +0000
%{
	#include<iostream>
	#include<cstring>
	//#include <vector>
	#include "includes/ast.h"
	#include "includes/literal.h"
	#include "includes/poolOfNodes.h"
	
	
	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
	Node * PerformBinaryOperation(int operation , Node *lhs, Node *rhs);

	PoolOfNodes& pool = PoolOfNodes::getInstance();
	Node* first;
	int indexcount=0;
	//int startind=0;
	//int stopind=0;

	//Node* last;
	//Node* oneindex;
%}

%union
{
	
	Node* node;
	int intNumber;
	char* id;
	int TokenType;
	float fltNumber;
	char* str;
	std::vector<Node*>* vec;
}


// 83 tokens, in alphabetical order:
%token AMPEREQUAL AMPERSAND AND AS ASSERT AT BACKQUOTE BAR BREAK CIRCUMFLEX
%token CIRCUMFLEXEQUAL CLASS COLON COMMA CONTINUE DEDENT DEF DEL DOT DOUBLESLASH
%token DOUBLESLASHEQUAL DOUBLESTAR DOUBLESTAREQUAL ELIF ELSE ENDMARKER EQEQUAL
%token EQUAL EXCEPT EXEC FINALLY FLOATNUM FOR FROM GLOBAL GREATER GREATEREQUAL GRLT
%token IF IMPORT IN INDENT INTNUM IS LAMBDA LBRACE LEFTSHIFT LEFTSHIFTEQUAL LESS
%token LESSEQUAL LPAR LSQB MINEQUAL MINUS NAME NEWLINE NOT NOTEQUAL NUMBER
%token OR PASS PERCENT PERCENTEQUAL PLUS PLUSEQUAL PRINT RAISE RBRACE RETURN
%token RIGHTSHIFT RIGHTSHIFTEQUAL RPAR RSQB SEMI SLASH SLASHEQUAL STAR STAREQUAL
%token STRING TILDE TRY VBAREQUAL WHILE WITH YIELD 

%start start

%locations


%type<vec> plus_stmt parameters arglist varargslist star_argument_COMMA star_fpdef_COMMA opt_arglist trailer star_trailer
%type<id> NAME STRING 
%type<intNumber> NUMBER MINUS PLUS TILDE INTNUM augassign
%type<intNumber> pick_PLUS_MINUS pick_multop pick_unop comp_op
%type<fltNumber> FLOATNUM 
%type<node> print_stmt star_EQUAL pick_yield_expr_testlist yield_expr testlist
%type<node> opt_test_2 plus_STRING subscript suite
%type<node> expr_stmt opt_yield_test decorated
%type<node> atom test opt_test_only pick_yield_expr_testlist_comp testlist_comp funcdef
%type<node> opt_test plus_COMMA_test opt_IF_ELSE or_test and_test not_test comparison expr xor_expr and_expr shift_expr arith_expr term factor power
%type<node> stmt compound_stmt simple_stmt pick_NEWLINE_stmt star_NEWLINE_stmt classdef small_stmt argument opt_testlist flow_stmt break_stmt continue_stmt return_stmt yield_stmt import_name import_from raise_stmt if_stmt star_ELIF opt_EQUAL_test fpdef pick_argument

//opt_COMMA star_COMMA_test varargslist star_fpdef_COMMA arglist opt_EQUAL_test fpdef fplist subscriptlist 
%%

start
	: file_input
	;
file_input // Used in: start
	: star_NEWLINE_stmt ENDMARKER 
	;
pick_NEWLINE_stmt // Used in: star_NEWLINE_stmt
	: NEWLINE {$$=nullptr;}
	| stmt 
	{ 
		if($1)
		{
		//const IntLiteral *il = static_cast<const IntLiteral*>($1->eval());
		const Literal *res = $1->eval();
		//$$ = $1->eval();
		if(res != nullptr)
			pool.add(res);
		//pool.add($$);
		}
	}
	;
star_NEWLINE_stmt // Used in: file_input, star_NEWLINE_stmt
	: star_NEWLINE_stmt pick_NEWLINE_stmt {$$=$2;}
	| %empty {$$=nullptr;}
	;
decorator // Used in: decorators
	: AT dotted_name LPAR opt_arglist RPAR NEWLINE
	| AT dotted_name NEWLINE
	;
opt_arglist // Used in: decorator, trailer
	: arglist
	{
	//std::cout<<"opt_arglist"<<std::endl;
	$$=$1;
	}
	| %empty {$$ = new std::vector<Node*>();}
	;
decorators // Used in: decorators, decorated
	: decorators decorator
	| decorator
	;
decorated // Used in: compound_stmt
	: decorators classdef {$$=nullptr;}
	| decorators funcdef {$$=$2;}
	;
funcdef // Used in: decorated, compound_stmt
	: DEF NAME parameters COLON suite 
	{
	SuiteNode *parameter = new SuiteNode($3);
	$$ = new FunctionNode ($2,parameter,$5);
	//std::cout<<"funcdef second"<<std::endl;
	pool.add ($$);
	delete [] $2;
	}
	;
parameters // Used in: funcdef
	: LPAR varargslist RPAR {$$=$2;}
	| LPAR RPAR {$$ = new std::vector<Node*>();}
	;
varargslist // Used in: parameters, old_lambdef, lambdef
	: star_fpdef_COMMA pick_STAR_DOUBLESTAR
	| star_fpdef_COMMA fpdef opt_EQUAL_test opt_COMMA 
	{
	//std::cout<<"vararglist2"<<std::endl;
	$$= $1; 
	Node *arg = new AsgBinaryNode($2,$3);
	$$->push_back(arg);
	}
	;
opt_EQUAL_test // Used in: varargslist, star_fpdef_COMMA
	: EQUAL test {$$ = $2;} 
	| %empty{$$=nullptr;}
	;
star_fpdef_COMMA // Used in: varargslist, star_fpdef_COMMA
	: star_fpdef_COMMA fpdef opt_EQUAL_test COMMA 
	{$$ = $1; Node *arg = new AsgBinaryNode($2,$3); $$->push_back(arg); }
	| %empty {$$ = new std::vector<Node*>();}
	;
opt_DOUBLESTAR_NAME // Used in: pick_STAR_DOUBLESTAR
	: COMMA DOUBLESTAR NAME
	| %empty
	;
pick_STAR_DOUBLESTAR // Used in: varargslist
	: STAR NAME opt_DOUBLESTAR_NAME
	| DOUBLESTAR NAME
	;
opt_COMMA // Used in: varargslist, opt_test, opt_test_2, testlist_safe, listmaker, testlist_comp, pick_for_test_test, pick_for_test, pick_argument
	: COMMA //{$$=nullptr;}
	| %empty //{$$=nullptr;}
	;
fpdef // Used in: varargslist, star_fpdef_COMMA, fplist, star_fpdef_notest
	: NAME {$$ = new IdentNode($1);delete [] $1;pool.add($$);}
	| LPAR fplist RPAR {$$=nullptr;}
	;
fplist // Used in: fpdef
	: fpdef star_fpdef_notest COMMA
	| fpdef star_fpdef_notest
	;
star_fpdef_notest // Used in: fplist, star_fpdef_notest
	: star_fpdef_notest COMMA fpdef
	| %empty
	;
stmt // Used in: pick_NEWLINE_stmt, plus_stmt
	: simple_stmt //{std::cout<<"simple"<<std::endl;$$=$1;}
	| compound_stmt {
	//std::cout<<"compound"<<std::endl;
	$$=$1;}
	;
simple_stmt // Used in: stmt, suite
	: small_stmt star_SEMI_small_stmt SEMI NEWLINE 
	| small_stmt star_SEMI_small_stmt NEWLINE 
	;
star_SEMI_small_stmt // Used in: simple_stmt, star_SEMI_small_stmt
	: star_SEMI_small_stmt SEMI small_stmt
	| %empty
	;
small_stmt // Used in: simple_stmt, star_SEMI_small_stmt
	: expr_stmt {$$=$1;}
	| print_stmt {$$=$1;}
	| del_stmt {$$=nullptr;}
	| pass_stmt {$$=nullptr;}
	| flow_stmt {$$=$1;}
	| import_stmt {$$=nullptr;}
	| global_stmt {$$=nullptr;}
	| exec_stmt {$$=nullptr;}
	| assert_stmt {$$=nullptr;}
	;
expr_stmt // Used in: small_stmt
	: testlist augassign pick_yield_expr_testlist
	{Node *rhs = PerformBinaryOperation($2,$1,$3);
						       $$ = new AsgBinaryNode($1, rhs);
						       pool.add($$);
						       pool.add(rhs);
						      }
	| testlist star_EQUAL 
					{
					if($2)
					{
					$$ = new AsgBinaryNode($1, $2);
					pool.add($$);
					}
					}
	;
pick_yield_expr_testlist // Used in: expr_stmt, star_EQUAL
	: yield_expr
	| testlist {$$=$1;}
	;
star_EQUAL // Used in: expr_stmt, star_EQUAL
	: star_EQUAL EQUAL pick_yield_expr_testlist
	{
	//if ($1 == 0)
	//{ 
	$$ = $3;
	//}
	//if ($1!=0 && $3!=0)
	//{ 
	//$$ = new AsgBinaryNode($1,$3); 
	//  pool.add($$);
	//}
	}
	| %empty {$$=0;}
	;
augassign // Used in: expr_stmt
	: PLUSEQUAL {$$ = 1;}
	| MINEQUAL {$$ = 2;}
	| STAREQUAL {$$ = 3;}
	| SLASHEQUAL{$$ = 4;}
	| PERCENTEQUAL{$$ = 5;}
	| AMPEREQUAL {$$ = 0;}
	| VBAREQUAL {$$ = 0;}
	| CIRCUMFLEXEQUAL {$$ = 0;}
	| LEFTSHIFTEQUAL {$$ = 0;}
	| RIGHTSHIFTEQUAL{$$ = 0;}
	| DOUBLESTAREQUAL{$$ = 6;}
	| DOUBLESLASHEQUAL{$$ = 7;}
	;
print_stmt // Used in: small_stmt
	: PRINT opt_test 
	{
	//Node const *res = ($2)->eval();
	//			res->print();
	//			pool.add(res);
	//try{	$2->eval()->print();}
	//catch(std::string& msg)
	//{std::cout<<msg<<std::endl;}
	 $$ = new PrintNode($2);
	 pool.add($$);

	}
	| PRINT RIGHTSHIFT test opt_test_2 {$$=nullptr;}
	;
star_COMMA_test // Used in: star_COMMA_test, opt_test, listmaker, testlist_comp, testlist, pick_for_test
	: star_COMMA_test COMMA test
	| %empty // {$$=nullptr;}
	;
opt_test // Used in: print_stmt
	: test star_COMMA_test opt_COMMA {$$=$1;}
	| %empty {$$=nullptr;}
	;
plus_COMMA_test // Used in: plus_COMMA_test, opt_test_2
	: plus_COMMA_test COMMA test 
	| COMMA test{$$=nullptr;}
	;
opt_test_2 // Used in: print_stmt
	: plus_COMMA_test opt_COMMA 
	| %empty {$$=nullptr;}
	;
del_stmt // Used in: small_stmt
	: DEL exprlist
	;
pass_stmt // Used in: small_stmt
	: PASS
	;
flow_stmt // Used in: small_stmt
	: break_stmt {$$=nullptr;}
	| continue_stmt {$$=nullptr;}
	| return_stmt {$$=$1;}
	| raise_stmt {$$=nullptr;}
	| yield_stmt {$$=nullptr;}
	;
break_stmt // Used in: flow_stmt
	: BREAK {$$=nullptr;}
	;
continue_stmt // Used in: flow_stmt
	: CONTINUE {$$=nullptr;}
	;
return_stmt // Used in: flow_stmt
	: RETURN testlist {$$= new ReturnNode($2); pool.add($$);}
	| RETURN {
				 //Node *none = new IntLiteral(0);
				 Node *none = new NoneLiteral();
				$$= new ReturnNode (none);
				pool.add($$);
				pool.add(none);	
				}
	;
yield_stmt // Used in: flow_stmt
	: yield_expr
	;
raise_stmt // Used in: flow_stmt
	: RAISE test opt_test_3 {$$=nullptr;}
	| RAISE {$$=nullptr;}
	;
opt_COMMA_test // Used in: opt_test_3, exec_stmt
	: COMMA test
	| %empty
	;
opt_test_3 // Used in: raise_stmt
	: COMMA test opt_COMMA_test
	| %empty
	;
import_stmt // Used in: small_stmt
	: import_name
	| import_from
	;
import_name // Used in: import_stmt
	: IMPORT dotted_as_names {$$=nullptr;}
	;
import_from // Used in: import_stmt
	: FROM pick_dotted_name IMPORT pick_STAR_import {$$=nullptr;}
	;
pick_dotted_name // Used in: import_from
	: star_DOT dotted_name
	| star_DOT DOT
	;
pick_STAR_import // Used in: import_from
	: STAR
	| LPAR import_as_names RPAR
	| import_as_names
	;
import_as_name // Used in: import_as_names, star_COMMA_import_as_name
	: NAME AS NAME
	| NAME
	;
dotted_as_name // Used in: dotted_as_names
	: dotted_name AS NAME
	| dotted_name
	;
import_as_names // Used in: pick_STAR_import
	: import_as_name star_COMMA_import_as_name COMMA
	| import_as_name star_COMMA_import_as_name
	;
star_COMMA_import_as_name // Used in: import_as_names, star_COMMA_import_as_name
	: star_COMMA_import_as_name COMMA import_as_name
	| %empty
	;
dotted_as_names // Used in: import_name, dotted_as_names
	: dotted_as_name
	| dotted_as_names COMMA dotted_as_name
	;
dotted_name // Used in: decorator, pick_dotted_name, dotted_as_name, dotted_name
	: NAME
	| dotted_name DOT NAME
	;
global_stmt // Used in: small_stmt
	: GLOBAL NAME star_COMMA_NAME
	;
star_COMMA_NAME // Used in: global_stmt, star_COMMA_NAME
	: star_COMMA_NAME COMMA NAME
	| %empty
	;
exec_stmt // Used in: small_stmt
	: EXEC expr IN test opt_COMMA_test
	| EXEC expr
	;
assert_stmt // Used in: small_stmt
	: ASSERT test COMMA test
	| ASSERT test
	;
compound_stmt // Used in: stmt
	: if_stmt {$$=$1;}
	| while_stmt {$$=nullptr;}
	| for_stmt {$$=nullptr;}
	| try_stmt {$$=nullptr;}
	| with_stmt {$$=nullptr;}
	| funcdef {
	$$=$1;
	//std::cout<<"compound::funcdef"<<std::endl;
	}
	| classdef {$$=nullptr;}
	| decorated {$$=$1;} 
	;
if_stmt // Used in: compound_stmt
	: IF test COLON suite star_ELIF ELSE COLON suite
	{ 
	//std::cout<<"if_stmt: one"<<std::endl;
	$$ = new IfElseNode ($2,$4,$8); pool.add($$);
	}
	| IF test COLON suite star_ELIF 
	{
	$$ = new IfElseNode ($2,$4,nullptr); pool.add($$);
	//std::cout<<"if_stmt: two"<<std::endl;
	//$$ = nullptr;
	}
	;
star_ELIF // Used in: if_stmt, star_ELIF
	: star_ELIF ELIF test COLON suite
	{
	//std::cout<<"1star_ELIF"<<std::endl;
	}
	| %empty
	{
	$$ = nullptr;
	//std::cout<<"2star_ELIF"<<std::endl;
	}
	;
while_stmt // Used in: compound_stmt
	: WHILE test COLON suite ELSE COLON suite
	| WHILE test COLON suite
	;
for_stmt // Used in: compound_stmt
	: FOR exprlist IN testlist COLON suite ELSE COLON suite
	| FOR exprlist IN testlist COLON suite
	;
try_stmt // Used in: compound_stmt
	: TRY COLON suite plus_except opt_ELSE opt_FINALLY
	| TRY COLON suite FINALLY COLON suite
	;
plus_except // Used in: try_stmt, plus_except
	: plus_except except_clause COLON suite
	| except_clause COLON suite
	;
opt_ELSE // Used in: try_stmt
	: ELSE COLON suite
	| %empty
	;
opt_FINALLY // Used in: try_stmt
	: FINALLY COLON suite
	| %empty
	;
with_stmt // Used in: compound_stmt
	: WITH with_item star_COMMA_with_item COLON suite
	;
star_COMMA_with_item // Used in: with_stmt, star_COMMA_with_item
	: star_COMMA_with_item COMMA with_item
	| %empty
	;
with_item // Used in: with_stmt, star_COMMA_with_item
	: test AS expr
	| test
	;
except_clause // Used in: plus_except
	: EXCEPT test opt_AS_COMMA
	| EXCEPT
	;
pick_AS_COMMA // Used in: opt_AS_COMMA
	: AS
	| COMMA
	;
opt_AS_COMMA // Used in: except_clause
	: pick_AS_COMMA test
	| %empty
	;
suite // Used in: funcdef, if_stmt, star_ELIF, while_stmt, for_stmt, try_stmt, plus_except, opt_ELSE, opt_FINALLY, with_stmt, classdef
	: simple_stmt
	| NEWLINE INDENT plus_stmt DEDENT 
	{
	$$=new SuiteNode($3);
	pool.add($$);
	}
	;
plus_stmt // Used in: suite, plus_stmt
	: plus_stmt stmt { $$=$1; $$->push_back($2); }
	| stmt 
	{ 
	$$ = new std::vector<Node*>();
	$$->push_back($1);
	}
	;
testlist_safe // Used in: list_for
	: old_test plus_COMMA_old_test opt_COMMA
	| old_test
	;
plus_COMMA_old_test // Used in: testlist_safe, plus_COMMA_old_test
	: plus_COMMA_old_test COMMA old_test
	| COMMA old_test
	;
old_test // Used in: testlist_safe, plus_COMMA_old_test, old_lambdef, list_if, comp_if
	: or_test
	| old_lambdef
	;
old_lambdef // Used in: old_test
	: LAMBDA varargslist COLON old_test
	| LAMBDA COLON old_test
	;
test // Used in: opt_EQUAL_test, print_stmt, star_COMMA_test, opt_test, plus_COMMA_test, raise_stmt, opt_COMMA_test, opt_test_3, exec_stmt, assert_stmt, if_stmt, star_ELIF, while_stmt, with_item, except_clause, opt_AS_COMMA, opt_IF_ELSE, listmaker, testlist_comp, lambdef, subscript, opt_test_only, sliceop, testlist, dictorsetmaker, star_test_COLON_test, opt_DOUBLESTAR_test, pick_argument, argument, testlist1
	: or_test opt_IF_ELSE {$$=$1;}
	| lambdef {$$=nullptr;}
	;
opt_IF_ELSE // Used in: test
	: IF or_test ELSE test {$$=nullptr;}
	| %empty {$$=nullptr;}
	;
or_test // Used in: old_test, test, opt_IF_ELSE, or_test, comp_for
	: and_test {$$=$1;}
	| or_test OR and_test
	;
and_test // Used in: or_test, and_test
	: not_test {$$=$1;}
	| and_test AND not_test
	;
not_test // Used in: and_test, not_test
	: NOT not_test {$$=nullptr;}
	| comparison {$$=$1;}
	;
comparison // Used in: not_test, comparison
	: expr {$$=$1;}
	| comparison comp_op expr {$$ = new ComparisonBinaryOperation ($1, $3,$2); pool.add($$);}
	;
comp_op // Used in: comparison
	: LESS {$$ = 1;}
	| GREATER  {$$ = 2;}
	| EQEQUAL  {$$ = 3;}
	| GREATEREQUAL {$$ = 4;}
	| LESSEQUAL {$$ = 5;}
	| GRLT {$$=0;}
	| NOTEQUAL {$$ = 6;}
	| IN {$$=0;}
	| NOT IN {$$=0;}
	| IS {$$=0;}
	| IS NOT {$$=0;}
	;
expr // Used in: exec_stmt, with_item, comparison, expr, exprlist, star_COMMA_expr
	: xor_expr {$$=$1;}
	| expr BAR xor_expr
	;
xor_expr // Used in: expr, xor_expr
	: and_expr {$$=$1;}
	| xor_expr CIRCUMFLEX and_expr
	;
and_expr // Used in: xor_expr, and_expr
	: shift_expr {$$=$1;}
	| and_expr AMPERSAND shift_expr
	;
shift_expr // Used in: and_expr, shift_expr
	: arith_expr {$$=$1;}
	| shift_expr pick_LEFTSHIFT_RIGHTSHIFT arith_expr
	;
pick_LEFTSHIFT_RIGHTSHIFT // Used in: shift_expr
	: LEFTSHIFT
	| RIGHTSHIFT
	;
arith_expr // Used in: shift_expr, arith_expr
	: term {$$=$1;}
	| arith_expr pick_PLUS_MINUS term {
	if ($2 == PLUS)
	{ $$= new AddBinaryNode($1, $3); pool.add($$);}
	if ($2 == MINUS)
	{ $$= new SubBinaryNode($1, $3); pool.add($$);} 
	}
	;
pick_PLUS_MINUS // Used in: arith_expr
	: PLUS {$$ = PLUS;}
	| MINUS {$$ = MINUS;}
	;
term // Used in: arith_expr, term
	: factor {$$=$1;}
	| term pick_multop factor
	{
	if ($2 == STAR)
	{ $$= new MulBinaryNode($1, $3); pool.add($$);}
	if ($2 == SLASH)
	{ $$= new DivBinaryNode($1, $3); pool.add($$);}
	if ($2 == PERCENT)
	{ $$= new ModBinaryNode($1, $3); pool.add($$);}
    if ($2 == DOUBLESLASH)
	{ $$= new DoubleDivBinaryNode($1, $3); pool.add($$);}
	}
	;
pick_multop // Used in: term
	: STAR {$$ = STAR;}
	| SLASH {$$ = SLASH;}
	| PERCENT {$$ = PERCENT;}
	| DOUBLESLASH {$$ = DOUBLESLASH;}
	;
factor // Used in: term, factor, power
	: pick_unop factor {
		if ($1 == MINUS)
			{ $$ = new UnaryMinusNode($2); pool.add($$); }
		if ($1 == PLUS)
			{ $$ = new UnaryPlusNode($2); pool.add($$); }
	}
	| power {$$=$1;}
	;
pick_unop // Used in: factor
	: PLUS { $$=PLUS;}
	| MINUS { $$ = MINUS;}
	| TILDE { }
	;
power // Used in: factor
	: atom star_trailer DOUBLESTAR factor {$$= new PowBinaryNode($1, $4); pool.add($$);}
	| atom star_trailer {	

		//$$ = new IndexTernaryNode($1, $2); pool.add($$);
		
		//if($2==nullptr)
		//	{$$=$1;}

		if($2)
							{  
								//std::cout<<"power not null"<<std::endl;
								Node *argsuite = new SuiteNode($2);
								std::string name = static_cast<IdentNode*>($1)->getIdent();
						    	$$ = new CallFunctionNode(name,argsuite);
						    	pool.add($$);
							}
							else
							{
								//std::cout<<"power null"<<std::endl;
								$$ = $1;
							}

		}
	;
star_trailer // Used in: power, star_trailer
	: star_trailer trailer {$$=$2;}
	| %empty {$$=nullptr;}
	;
atom // Used in: power
	: LPAR opt_yield_test RPAR {$$=$2;}
	| LSQB opt_listmaker RSQB {$$=nullptr;}
	| LBRACE opt_dictorsetmaker RBRACE {$$=nullptr;}
	| BACKQUOTE testlist1 BACKQUOTE {$$=nullptr;}
	| NAME {	
			//std::cout<<"atom first"<<std::endl;
			$$ = new IdentNode($1);                                                                                                                      
			//std::cout<<"name"<<$$<<std::endl;
			//first = $$;       
            delete [] $1;
            pool.add($$);
            }
	| INTNUM {$$=new IntLiteral($1); pool.add($$);}
	| FLOATNUM {$$=new FloatLiteral($1); pool.add($$);}
	| NUMBER { $$=nullptr;}
	| plus_STRING {
	//std::cout<<"str"<<std::endl;
	//$$=new StringLiteral($1); pool.add($$);
	$$=$1;
	}
	;
pick_yield_expr_testlist_comp // Used in: opt_yield_test
	: yield_expr{$$=$1;}
	| testlist_comp{$$=$1;}
	;
opt_yield_test // Used in: atom
	: pick_yield_expr_testlist_comp {$$=$1;}
	| %empty {$$=nullptr;}
	;
opt_listmaker // Used in: atom
	: listmaker
	| %empty
	;
opt_dictorsetmaker // Used in: atom
	: dictorsetmaker
	| %empty
	;
plus_STRING // Used in: atom, plus_STRING
	: plus_STRING STRING
	{

	$$=new StringLiteral($2);
	pool.add($$);
	}
	| STRING 
	{

	$$=new StringLiteral($1);
	pool.add($$);
	}
	;
listmaker // Used in: opt_listmaker
	: test list_for
	| test star_COMMA_test opt_COMMA
	;
testlist_comp // Used in: pick_yield_expr_testlist_comp
	: test comp_for
	| test star_COMMA_test opt_COMMA
	;
lambdef // Used in: test
	: LAMBDA varargslist COLON test
	| LAMBDA COLON test
	;
trailer // Used in: star_trailer
	: LPAR opt_arglist RPAR {$$=$2;}
	| LSQB subscriptlist RSQB {$$=nullptr;}
	| DOT NAME {$$=nullptr;}
	;
subscriptlist // Used in: trailer
	: subscript star_COMMA_subscript COMMA
	| subscript star_COMMA_subscript
	;
star_COMMA_subscript // Used in: subscriptlist, star_COMMA_subscript
	: star_COMMA_subscript COMMA subscript
	| %empty
	;
subscript // Used in: subscriptlist, star_COMMA_subscript
	: DOT DOT DOT {$$=nullptr;}
	| test {$$=nullptr;}
	| opt_test_only COLON opt_test_only opt_sliceop {$$=nullptr;}
	;
opt_test_only // Used in: subscript
	: test
	| %empty {$$=nullptr;}
	;
opt_sliceop // Used in: subscript
	: sliceop
	| %empty
	;
sliceop // Used in: opt_sliceop
	: COLON test
	| COLON
	;
exprlist // Used in: del_stmt, for_stmt, list_for, comp_for
	: expr star_COMMA_expr COMMA
	| expr star_COMMA_expr
	;
star_COMMA_expr // Used in: exprlist, star_COMMA_expr
	: star_COMMA_expr COMMA expr
	| %empty
	;
testlist // Used in: expr_stmt, pick_yield_expr_testlist, return_stmt, for_stmt, opt_testlist, yield_expr
	: test star_COMMA_test COMMA {$$=$1;}
	| test star_COMMA_test {$$=$1;}
	;
dictorsetmaker // Used in: opt_dictorsetmaker
	: test COLON test pick_for_test_test
	| test pick_for_test
	;
star_test_COLON_test // Used in: star_test_COLON_test, pick_for_test_test
	: star_test_COLON_test COMMA test COLON test
	| %empty
	;
pick_for_test_test // Used in: dictorsetmaker
	: comp_for
	| star_test_COLON_test opt_COMMA
	;
pick_for_test // Used in: dictorsetmaker
	: comp_for
	| star_COMMA_test opt_COMMA
	;
classdef // Used in: decorated, compound_stmt
	: CLASS NAME LPAR opt_testlist RPAR COLON suite {$$=nullptr;}
	| CLASS NAME COLON suite {$$=nullptr;}
	;
opt_testlist // Used in: classdef
	: testlist {$$=$1;}
	| %empty {$$=nullptr;}
	;
arglist // Used in: opt_arglist
	: star_argument_COMMA pick_argument
	{ 
	//std::cout<<"arglist"<<std::endl;
	$$ = $1 ; 
	$$->push_back($2);
	}
	;
star_argument_COMMA // Used in: arglist, star_argument_COMMA
	: star_argument_COMMA argument COMMA 
	{
	//std::cout<<"star_argumnet"<<std::endl;
	$$ = $1;
	$$->push_back($2);
	}
	| %empty {
	$$ = new std::vector<Node *>(); 
	//$$=nullptr;
	}
	;
star_COMMA_argument // Used in: star_COMMA_argument, pick_argument
	: star_COMMA_argument COMMA argument
	| %empty
	;
opt_DOUBLESTAR_test // Used in: pick_argument
	: COMMA DOUBLESTAR test
	| %empty
	;
pick_argument // Used in: arglist
	: argument opt_COMMA { $$ = $1;}
	| STAR test star_COMMA_argument opt_DOUBLESTAR_test {$$=nullptr;}
	| DOUBLESTAR test {$$=nullptr;}
	;
argument // Used in: star_argument_COMMA, star_COMMA_argument, pick_argument
	: test opt_comp_for
	| test EQUAL test // {$$ = new AsgBinaryNode($1,$3);}
	;
opt_comp_for // Used in: argument
	: comp_for
	| %empty
	;
list_iter // Used in: list_for, list_if
	: list_for
	| list_if
	;
list_for // Used in: listmaker, list_iter
	: FOR exprlist IN testlist_safe list_iter
	| FOR exprlist IN testlist_safe
	;
list_if // Used in: list_iter
	: IF old_test list_iter
	| IF old_test
	;
comp_iter // Used in: comp_for, comp_if
	: comp_for
	| comp_if
	;
comp_for // Used in: testlist_comp, pick_for_test_test, pick_for_test, opt_comp_for, comp_iter
	: FOR exprlist IN or_test comp_iter
	| FOR exprlist IN or_test
	;
comp_if // Used in: comp_iter
	: IF old_test comp_iter
	| IF old_test
	;
testlist1 // Used in: atom, testlist1
	: test
	| testlist1 COMMA test
	;
yield_expr // Used in: pick_yield_expr_testlist, yield_stmt, pick_yield_expr_testlist_comp
	: YIELD testlist {$$=$2;}
	| YIELD {$$=nullptr;}
	;
star_DOT // Used in: pick_dotted_name, star_DOT
	: star_DOT DOT
	| %empty
	;

%%

#include <stdio.h>
#include <string.h>
Node* PerformBinaryOperation(int operation , Node *lhs, Node *rhs) 
{
 
  Node *res=NULL;
  switch(operation)
  {
    case 1:
    		res = new AddBinaryNode(lhs,rhs);
    		break;
    case 2:
    		res = new SubBinaryNode(lhs,rhs);
    		break;
    case 3:
    		res = new MulBinaryNode(lhs,rhs);
    		break;
    case 4:
    		res = new DivBinaryNode(lhs,rhs);
    		break;
    case 5:
   		res = new ModBinaryNode(lhs,rhs);
   		break;
    case 6:
	    	res = new PowBinaryNode(lhs,rhs);
	    	break;
    case 7:
    		res = new DoubleDivBinaryNode(lhs,rhs);
    		break;
    default:
    		break;
    }
  if(res!=NULL)
   pool.add(res);
  return res;
}


void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}

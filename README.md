# Language-Translation
Translation of Programming Languages  
Computer Science Division, Clemson University  
Brian Malloy, PhD  

## Design and implement an Abstract Syntax Tree (AST) to interpret Python 2.7

Most language translators use a scanner and parser to build an abstract syntax tree (AST) to represent the
program. Python also builds an AST representation of the program and makes this available through a module called ast.py. This project builds an Python 2.7 interpreter in C++ using Flex and Bison.  

1. The interpreter handles three types: *integer*, *float*, *string*.
2. A symbol table that handles all types of assignment, arithematic and logical operations.
3. Solution translate Python if/else constructs, functions, including scope resolution, and return value propogation.
4. It translates actual and formal parameters, including pass by value parameter transmission, default parameters in functions and recursion.
5. Directory /cases/ contains test cases that adequately test the interpreter.
6. test.py runs the test cases in /cases/.

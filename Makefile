CCC = g++
LEX = flex
YACC = bison
CFLAGS = -g -std=c++11 -W -Wall -Weffc++ -Wextra -pedantic -O0
LEXFLAGS = -Wno-unused -Wno-sign-compare -Wno-deprecated-register

OBJS = main.o parse.tab.o lex.yy.o ast.o literal.o symbolTable.o poolOfNodes.o

run: $(OBJS)
	$(CCC) $(CFLAGS) -o run $(OBJS)

main.o: main.cpp parse.y scan.l parse.tab.c lex.yy.c
	$(CCC) $(CFLAGS) -c main.cpp

parse.tab.c: parse.y
	$(YACC) -d parse.y

parse.tab.o: parse.tab.c
	$(CCC) $(CFLAGS) -c parse.tab.c

lex.yy.c: scan.l parse.tab.o
	$(LEX) scan.l

lex.yy.o: lex.yy.c
	$(CCC) $(CFLAGS) $(LEXFLAGS) -c lex.yy.c

ast.o: includes/ast.cpp includes/ast.h includes/literal.h includes/literal.cpp
	$(CCC) $(CFLAGS) -c includes/ast.cpp

literal.o: includes/literal.cpp includes/literal.h
	$(CCC) $(CFLAGS) -c includes/literal.cpp

symbolTable.o: includes/symbolTable.cpp includes/symbolTable.h
	$(CCC) $(CFLAGS) -c includes/symbolTable.cpp

poolOfNodes.o: includes/poolOfNodes.cpp includes/poolOfNodes.h includes/node.h
	$(CCC) $(CFLAGS) -c includes/poolOfNodes.cpp
	
clean:
	rm -f run *.o parse.tab.c lex.yy.c
	rm -f parse.tab.h

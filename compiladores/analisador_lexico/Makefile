all: generate build

generate:
	flex parser.flex
	
build:
	gcc lex.yy.c -lfl -o parser
	
clean:
	rm -f parser
	rm -f lex.yy.c

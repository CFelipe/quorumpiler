parser: lex.out
	gcc -ll parser.c -o parser

lex.out: lex.yy.c
	gcc -ll lex.yy.c

lex.yy.c: quorum.lex
	lex quorum.lex

lalr: yacc
	gcc -ll lex.yy.c y.tab.c -o lalr
 
yacc: lex
	yacc -dvt quorum.y

lex: quorum.lex
	lex quorum.lex

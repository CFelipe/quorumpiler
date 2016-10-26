lalr: yacc
	gcc -ll lex.yy.c y.tab.c -o lalr
 
yacc: lex
	yacc -dv quorum.yacc

lex: quorum.lex
	lex quorum.lex

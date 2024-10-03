all : backend

backend:
	flex structbe.l
	bison -d structbe.y
	gcc lex.yy.c structbe.tab.c -o analyseurbe -lfl

		

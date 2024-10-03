all : frontend

frontend:
	flex structfe.lex
	bison -d structfe.y
	gcc -g lex.yy.c table_hachage.c generation_code.c structfe.tab.c -o analyseurfe -lfl
	
test:
	./analyseurfe < ~/Bureau/Projet-Compilation-2022\ \(copie\)/Tests/variables.c	


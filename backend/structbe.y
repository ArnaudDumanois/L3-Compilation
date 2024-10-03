%{
 
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
        
int yylex(void);
int yyerror(char*);
extern int yylineno;
%}


%token IDENTIFIER CONSTANT 
%token LE_OP GE_OP EQ_OP NE_OP
%token EXTERN
%token INT VOID
%token IF RETURN GOTO

%right '='
%left '<' '>'
%left '-' '+'
%left '*' '/'
%nonassoc MOINS

 
%start program 
%%

primary_expression
        : IDENTIFIER
        | CONSTANT
        ;

postfix_expression
        : primary_expression
        | postfix_expression '(' ')'
        | postfix_expression '(' argument_expression_list ')'
        ;

argument_expression_list
        : primary_expression
        | argument_expression_list ',' primary_expression
        ;

unary_expression
        : postfix_expression
        | unary_operator primary_expression
        ;

unary_operator
        : '&'
        | '*'
        | '-' %prec MOINS
        ;

multiplicative_expression
        : unary_expression
        | primary_expression '*' primary_expression
        | primary_expression '/' primary_expression
        ;

additive_expression
        : multiplicative_expression
        | primary_expression '+' primary_expression
        | primary_expression '-' primary_expression
        ;

relational_expression
        : additive_expression
        | primary_expression '<' primary_expression
        | primary_expression '>' primary_expression
        | primary_expression LE_OP primary_expression
        | primary_expression GE_OP primary_expression
        ;

equality_expression
        : relational_expression
        | primary_expression EQ_OP primary_expression
        | primary_expression NE_OP primary_expression
        ;

expression
        : equality_expression
        | unary_operator primary_expression '=' primary_expression
        | primary_expression '=' relational_expression
        ;

declaration
        : declaration_specifiers declarator ';'
        ;

declaration_specifiers
        : EXTERN type_specifier
        | type_specifier
        ;

type_specifier
        : VOID
        | INT
        ;

declarator
        : '*' direct_declarator
        | direct_declarator
        ;

direct_declarator
        : IDENTIFIER
        | direct_declarator '(' parameter_list ')'
        | direct_declarator '(' ')'
        ;

parameter_list
        : parameter_declaration
        | parameter_list ',' parameter_declaration
        ;

parameter_declaration
        : declaration_specifiers declarator
        ;

statement
        : compound_statement
        | labeled_statement
        | expression_statement
        | selection_statement
        | jump_statement 
        ;

compound_statement
        : '{' '}'
        | '{' statement_list '}'
        | '{' declaration_list '}'
        | '{' declaration_list statement_list '}'
        ;

declaration_list
        : declaration
        | declaration_list declaration
        ;

statement_list
        : statement
        | statement_list statement
        ;

labeled_statement
        : IDENTIFIER ':' statement
        ;

expression_statement
        : ';'
        | expression ';'
        ;

selection_statement
        : IF '(' equality_expression ')' GOTO IDENTIFIER ';'
        ;
jump_statement
        : RETURN ';'
        | RETURN expression ';'
        | GOTO IDENTIFIER ';'
        ;

program
        : external_declaration
        | program external_declaration
        ;

external_declaration
        : function_definition
        | declaration
        ;

function_definition
        : declaration_specifiers declarator compound_statement
        ;

%%

int yyerror(char *s) {
        fprintf(stderr, "erreur de syntaxe a la ligne %d: %s\n", yylineno, s);
        exit(1);
}


int main(){
	yyparse();
	printf("Analyse réussi\n");
	return 0;
}







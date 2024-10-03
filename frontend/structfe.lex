
%option yylineno
%option noyywrap

C [0-9]
L [A-Za-z]
SLC ([A-Za-z0-9]|_)*

%{

#include <stdio.h>
#include "type.h"
#include "structfe.tab.h"

%}


%%

"int" 		{return INT;}
"if"		{return IF;}
"extern"	{return EXTERN;}
"void"		{return VOID;}
"for"		{return FOR;} 
"while"	    {return WHILE;} 
"else"		{return ELSE;} 
"return"	{return RETURN;} 
"struct"	{return STRUCT;} 
"sizeof"	{return SIZEOF;} 
"=="		{return EQ_OP;} 
"&&"		{return AND_OP;} 
"||"		{return OR_OP;} 
"<="		{return LE_OP;} 
">="		{return GE_OP;} 
"!="		{return NE_OP;} 

{C}+		{yylval.nombre = strdup(yytext); return CONSTANT;}
{L}{SLC}	{yylval.nom=strdup(yytext); return IDENTIFIER;}
"->" 		{return PTR_OP;}

"/*"([^*]|"*"[^/])*"*/"   	;
[\n\t\r\v\f ]		;
.		{return yytext[0];} 


%%




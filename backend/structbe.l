%option noyywrap
%option yylineno

D                       [0-9]
L                       [a-zA-Z]

%{
#include <stdio.h>
#include "structbe.tab.h"

%}


%%

"extern"                {return EXTERN;}
"goto"                  {return GOTO;}
"if"                    {return IF;}
"int"                   {return INT;}
"return"                {return RETURN;}
"void"                  {return VOID;}

({L}|_)({L}|_|{D})*     {return IDENTIFIER;}
{D}+                    {return CONSTANT;}


"<="                    {return LE_OP;}
">="                    {return GE_OP;}
"=="                    {return EQ_OP;}
"!="                    {return NE_OP;}

"/*"([^*]|"*"[^/])*"*/" 	;


[\n\t\r\v\f ]			;

.                       {return yytext[0];}

%%
 

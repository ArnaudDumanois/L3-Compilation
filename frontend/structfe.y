%{
	

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "generation_code.h"

#include "structfe.tab.h"

#include <assert.h> 

int yylex(void);
int yyerror(char*);
extern int yylineno;
table_t *table_sym;
const char* filename = "out.c";
FILE* output_file;

%} 

%union {
	char *nom;
	all_types all;
	char *nombre;
}
 
%token<all> SIZEOF
%token<all> PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token<all> AND_OP OR_OP
%token<all> EXTERN
%token<all> INT VOID
%token<all> STRUCT 
%token<all> IF ELSE WHILE FOR RETURN
%token<all> '(' ')' '&' '*' '-' '{' '}' ';'

%token<nom> IDENTIFIER 			
%token<nombre> CONSTANT

%right '='
%left '<' '>'
%left '-' '+'
%left '*' '/'
%nonassoc MOINS


%nonassoc THEN
%nonassoc ELSE


%type<all> primary_expression				
%type<all> postfix_expression 			
%type<all> argument_expression_list			
%type<all> unary_expression				
%type<all> unary_operator				
%type<all> multiplicative_expression			
%type<all> additive_expression			
%type<all> relational_expression			
%type<all> equality_expression			
%type<all> logical_and_expression			
%type<all> logical_or_expression			
%type<all> expression					
%type<all> declaration					
%type<all> declaration_specifiers 			
%type<all> type_specifier				
%type<all> struct_specifier
%type<all> struct_declaration_list
%type<all> struct_declaration
%type<all> declarator					
%type<all> direct_declarator
%type<all> parameter_list				
%type<all> parameter_declaration			
%type<all> statement					
%type<all> compound_statement				
%type<all> declaration_list				
%type<all> statement_list				
%type<all> expression_statement			
%type<all> selection_statement			
%type<all> iteration_statement			
%type<all> jump_statement				
%type<all> program					
%type<all> external_declaration			
%type<all> function_definition			


%start program


%%


primary_expression
        : IDENTIFIER 	{ $$.code = init_code();
                          symbole_t *s = recherche(table_sym, $1);   
                          if (s == NULL){
                              fprintf(stderr, "La variable %s a la ligne %d n'a jamais été déclaré.\n",$1, yylineno);
                         }
                         $$.s = s;
                         $$.code = inserer_code($$.code, $1);
                         
                         $$.temp="";
                         $$.decla_tmp = "";
                         
                          }
                          
        | CONSTANT { $$.code = init_code(); 
        	      $$.code = inserer_code($$.code, $1);
                     $$.type = ENTIER;
                     $$.temp="";
                     $$.decla_tmp = "";
                     }	
                     		        	
        | '(' expression ')'    { $$.code = init_code();
        			   $$.temp = $2.temp;
                                  $$.code = inserer_code($$.code, $2.code);
                                  $$.s = $2.s;
                                  $$.type = $2.type;
                                  $$.decla_tmp = $2.decla_tmp;
                                }								
        ;
        
postfix_expression
        : primary_expression { $$.temp = $1.temp;
        			$$.code = $1.code;
                               $$.s = $1.s;
                               $$.type = $1.type;
                               $$.decla_tmp = $1.decla_tmp;
                               }	
                               			
        | postfix_expression '(' ')' 	  {  if (convert_type_t($1.type) != NULL){
                                                        $$.type = $1.type;
                                                } else{
                                                        fprintf(stderr, "le type de la fonction %s est mauvais a la ligne %d\n",convert_type_t($1.type), yylineno);
                                                }
                
                                          $$.code = init_code(); 
        				   $$.code = inserer_code($$.code, $1.code);
        				   $$.code = inserer_code($$.code, "()");
        				   $$.temp=$1.temp; 	
        				   $$.decla_tmp = $1.decla_tmp;
        				  }
        	
        | postfix_expression '(' argument_expression_list ')'   {  if (convert_type_t($1.type) != NULL){
                                                                         $$.type = $1.type;
                                                                   }else{
                                                                        fprintf(stderr, "le type de la fonction %s est mauvais a la ligne %d\n",convert_type_t($1.type), yylineno);
                                                                }

                                                                $$.temp = $3.temp;
                                                                $$.decla_tmp = $3.decla_tmp;
                                                                
                                                              $$.code = init_code(); 
        							$$.code = inserer_code($$.code, $1.code);
        				   			$$.code = inserer_code($$.code, "(");
        				   			$$.code = inserer_code($$.code, $3.code);
        				   			$$.code = inserer_code($$.code, ")"); 
        							}	
        							   
        | postfix_expression '.' IDENTIFIER     { if($1.type != STRUCTURE) {
                                                          fprintf(stderr, "%s n'est pas une structure a la ligne %d\n",$1.code, yylineno);
                                                  } else {
                                                         $$.code = init_code();  
                                                  }
                                                  $$.temp=$1.temp;
                                                  $$.decla_tmp = $1.decla_tmp;
                				 }
                				 	
        | postfix_expression PTR_OP IDENTIFIER   {  $$.code = init_code();
        					      char *var = new_var();
        					      
        					      $$.temp = init_code();
        					      
        					      $$.decla_tmp = init_code();
        					      $$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					      $$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      $$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      
        					      $$.temp = inserer_code($$.temp, var);
        					      $$.temp = inserer_code($$.temp, "=");
        					      $$.temp = inserer_code($$.temp, $1.code);
        					      $$.temp = inserer_code($$.temp, "+");
        					      
        					      int t = sizeof($3);
						      char size[sizeof(int)*8];
					             sprintf(size, "%d", t);
					             char *taille = (char *) malloc(8*sizeof(char *)+4*sizeof(int) + 1);
					             strcpy(taille,size);
					             
        					      $$.temp = inserer_code($$.temp, taille);
        					      $$.code = inserer_code($$.code, var);
        					      
        					      $$.type = $1.type;
                                                 }	
        ;

argument_expression_list
        : expression {  $$.code = $1.code;
                        $$.type = $1.type;
                        $$.temp = $1.temp;
                        $$.decla_tmp = $1.decla_tmp;
                        }	 
                                                          
        | argument_expression_list ',' expression  { $$.code = init_code();
                                                     $$.code = inserer_code($$.code, $1.code);
                                                     $$.code = inserer_code($$.code, ", ");
                                                     $$.code = inserer_code($$.code, $3.code);
                                                     
                                                     $$.temp = init_code();
                                                     $$.temp = inserer_code($$.temp, $1.temp);
                                                     $$.temp = inserer_code($$.temp, ";\n");
                                                     $$.temp = inserer_code($$.temp, $3.temp);
                                                     
                                                     $$.decla_tmp = init_code();
                                                     $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
                                                     $$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
                                                     $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
                                                    
                                                  }   
        ;

unary_expression
        : postfix_expression  {$$.code = $1.code;
                               $$.s = $1.s;
                               $$.type = $1.type;
                               $$.temp = $1.temp;
                               $$.decla_tmp = $1.decla_tmp;
                               } 	
                               			
        | unary_operator unary_expression    { if ($2.type == ENTIER) {
        						$$.type = ENTIER; }
        					else {
        						fprintf(stderr, "l'expression n'est pas de type int, à la ligne %d\n", yylineno); }
        					
        					$$.code = init_code();
        														
        					char *var = new_var();
        					$$.temp = init_code();
        					
        					$$.decla_tmp = init_code();
        					$$.decla_tmp = inserer_code($$.decla_tmp, $2.decla_tmp);
        					$$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					$$.decla_tmp = inserer_code($$.decla_tmp, var);
        					$$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					
        					$$.temp = inserer_code($$.temp, $2.temp);
        					if (strlen($2.temp) != 0) 
        					      	$$.temp = inserer_code($$.temp, ";\n");
        					     
        				        $$.temp = inserer_code($$.temp, var);
        				        $$.temp = inserer_code($$.temp, "=");
        					$$.temp = inserer_code($$.temp, $1.code);
        					$$.temp = inserer_code($$.temp, $2.code);
        					
        					$$.code = inserer_code($$.code, var);
                                               
        					}
        					
						
        | SIZEOF unary_expression    { if ($2.type == ENTIER)
        					$$.type = ENTIER;
        				else
        					fprintf(stderr, "l'opérande n'est pas un entier, ligne %d, mais est de type %s\n.", yylineno, convert_type_t($2.type));         
        				$$.code = init_code();
        				
					int t = sizeof($2.type);
					char size[sizeof(int)*8];
					sprintf(size, "%d", t);
					char *taille = (char *) malloc(8*sizeof(char *)+4*sizeof(int) + 1);
					strcpy(taille,size);
        				$$.code = inserer_code($$.code, taille); 
        				
        				$$.temp=$2.temp;
        				$$.decla_tmp = $2.decla_tmp;
        				
        				 }
        ;
        


unary_operator
        : '&'  { $$.code = init_code(); 
                 $$.code = inserer_code($$.code, "&"); }
        | '*'  { $$.code = init_code(); 
                 $$.code = inserer_code($$.code, "*");}
        | '-' %prec MOINS { $$.code = init_code(); 
                            $$.code = inserer_code($$.code, "-");
                           }
        ;


multiplicative_expression
        : unary_expression { $$.code = $1.code;
                             $$.s = $1.s;
                             $$.type = $1.type;
                             $$.temp = $1.temp;
                             $$.decla_tmp = $1.decla_tmp;
                             }	
                             	
        | multiplicative_expression '*' unary_expression { if ($1.type == ENTIER) {
                                                                if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                } else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                                }} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
                                                        
                                                        $$.code = init_code();
                                                        
                                                    char *var = new_var();
        					      $$.temp = init_code();
        					      
        					      $$.decla_tmp = init_code();
        					      
        					      $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        					      $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					      
        					      $$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					      $$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      $$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      
        					      $$.temp = inserer_code($$.temp, $1.temp);
        					      if (strlen($1.temp) != 0) 
        					      		$$.temp = inserer_code($$.temp, ";\n");
        					      $$.temp = inserer_code($$.temp, $3.temp);
        					      if (strlen($3.temp) != 0)
        					       	$$.temp = inserer_code($$.temp, ";\n");
        					      
        					      $$.temp = inserer_code($$.temp, var);
        					      $$.temp = inserer_code($$.temp, "=");
        					      $$.temp = inserer_code($$.temp, $1.code);
        					      $$.temp = inserer_code($$.temp, "*");
        					      $$.temp = inserer_code($$.temp, $3.code);
        					      
        					      $$.code = inserer_code($$.code, var);
                                                        }
                                                        
                                                        		
        | multiplicative_expression '/' unary_expression { if ($1.type == ENTIER) {
                                                                if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                } else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                          }} else {
                                                                fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
                                                        
                                                    $$.code = init_code();
                                                        
                                                    char *var = new_var();
        					      $$.temp = init_code();
        					      
        					      $$.decla_tmp = init_code();
        					      
        					      $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        					      $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					      
        					      $$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					      $$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      $$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      
        					      $$.temp = inserer_code($$.temp, $1.temp);
        					      if (strlen($1.temp) != 0) 
        					      		$$.temp = inserer_code($$.temp, ";\n");
        					      $$.temp = inserer_code($$.temp, $3.temp);
        					      if (strlen($3.temp) != 0)
        					      	   $$.temp = inserer_code($$.temp, ";\n");
        					      
        					      $$.temp = inserer_code($$.temp, var);
        					      $$.temp = inserer_code($$.temp, "=");
        					      $$.temp = inserer_code($$.temp, $1.code);
        					      $$.temp = inserer_code($$.temp, "/");
        					      $$.temp = inserer_code($$.temp, $3.code);
        					      
        					      $$.code = inserer_code($$.code, var);
                                                         }
        ;

additive_expression
        : multiplicative_expression { $$.code = $1.code;
                                      $$.s = $1.s;
                                      $$.type = $1.type;
                                      $$.temp = $1.temp; 
                                      $$.decla_tmp = $1.decla_tmp;
                                    }	
                                      					
        | additive_expression '+' multiplicative_expression    { if ($1.type == ENTIER) { 
                                                                	if ($3.type == ENTIER)
                                                                        $$.type = ENTIER;
                                                                	else if ($3.type = POINTEUR) 
										$$.type = POINTEUR; 
									else 
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type)); }
                                                               
								else if ($1.type == POINTEUR) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = POINTEUR;
                                                                	} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type)); }
                                                                	
								}
                                                               $$.code = init_code();
                                                        
                                                   		 char *var = new_var();
        					      		 $$.temp = init_code();
        					      		 
        					      		 $$.decla_tmp = init_code();
        					      		 
        					      		 $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        					      		 $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					 
        					      		 $$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					      		 $$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      		 $$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      		 
        					      		 $$.temp = inserer_code($$.temp, $1.temp);
        					      		 if (strlen($1.temp) != 0) 
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      		 $$.temp = inserer_code($$.temp, $3.temp);
        					 
        					      		 if (strlen($3.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");	
        					     		 $$.temp = inserer_code($$.temp, var);
        					   		 $$.temp = inserer_code($$.temp, "=");
        					    		 $$.temp = inserer_code($$.temp, $1.code);
        					    		 $$.temp = inserer_code($$.temp, "+");
        					   		 $$.temp = inserer_code($$.temp, $3.code);
        					   		    
        					     		 $$.code = inserer_code($$.code, var);
        					     		 
         							   }
                                                        	
                                                        	
                                                        
        | additive_expression '-' multiplicative_expression 	{ if ($1.type == ENTIER) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type)); }
								} else if ($1.type == POINTEUR) {
									if ($3.type = ENTIER) {
										$$.type = POINTEUR;
									} else if ($3.type = POINTEUR) {
										$$.type = ENTIER;
									} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
								}
                                                                  $$.code = init_code();
                                                        
                                                    		char *var = new_var();
        					      		$$.temp = init_code();
        					      		
        					      		$$.decla_tmp = init_code();
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					     		$$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      		
        					      		 $$.temp = inserer_code($$.temp, $1.temp);
        					      		 if (strlen($1.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      		 $$.temp = inserer_code($$.temp, $3.temp);
        					      		 if (strlen($3.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      		$$.temp = inserer_code($$.temp, var);
        					      		$$.temp = inserer_code($$.temp, "=");
        					   		$$.temp = inserer_code($$.temp, $1.code);
        					     		$$.temp = inserer_code($$.temp, "-");
        					      		$$.temp = inserer_code($$.temp, $3.code);
        					      
        					      		$$.code = inserer_code($$.code, var);
                                                                }		
        ;



relational_expression
        : additive_expression    {$$.code = $1.code;
        			   $$.type = $1.type;
        			   $$.temp = $1.temp;
        			   $$.decla_tmp = $1.decla_tmp;
        			  }
        			   					
        | relational_expression '<' additive_expression  	{   						    
        							     if ($1.type == ENTIER) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                                }} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
                                                                $$.code = init_code();
                                                        
                                                    		char *var = new_var();
        					      		$$.temp = init_code();
        					      		
        					      		$$.decla_tmp = init_code();
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      		
        					      		 $$.temp = inserer_code($$.temp, $1.temp);
        					      		 if (strlen($1.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      		 $$.temp = inserer_code($$.temp, $3.temp);
        					      		 if (strlen($3.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      
        					      		$$.temp = inserer_code($$.temp, var);
        					      		$$.temp = inserer_code($$.temp, "=");
        					   		$$.temp = inserer_code($$.temp, $1.code);
        					     		$$.temp = inserer_code($$.temp, "<");
        					      		$$.temp = inserer_code($$.temp, $3.code);
        					      
        					      		$$.code = inserer_code($$.code, var);
        							}	
        							
        | relational_expression '>' additive_expression  	{  							    
        							     if ($1.type == ENTIER) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                                }} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s\n.", yylineno, convert_type_t($1.type));
                                                                }
                                                                  $$.code = init_code();
                                                        
                                                    		char *var = new_var();
        					      		$$.temp = init_code();
        					      		
        					      		$$.decla_tmp = init_code();
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      		
        					      		 $$.temp = inserer_code($$.temp, $1.temp);
        					      		 if (strlen($1.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      		 $$.temp = inserer_code($$.temp, $3.temp);
        					      		 if (strlen($3.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      
        					      		$$.temp = inserer_code($$.temp, var);
        					      		$$.temp = inserer_code($$.temp, "=");
        					   		$$.temp = inserer_code($$.temp, $1.code);
        					     		$$.temp = inserer_code($$.temp, ">");
        					      		$$.temp = inserer_code($$.temp, $3.code);
        					      
        					      		$$.code = inserer_code($$.code, var);
        							}
        							
        | relational_expression LE_OP additive_expression  	{   
        							    
        							     if ($1.type == ENTIER) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                                }} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
                                                                $$.code = init_code();
                                                        
                                                    		char *var = new_var();
        					      		$$.temp = init_code();
        					      		
        					      		$$.decla_tmp = init_code();
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					     		$$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      		
        					      		 $$.temp = inserer_code($$.temp, $1.temp);
        					      		 if (strlen($1.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      		 $$.temp = inserer_code($$.temp, $3.temp);
        					      		 if (strlen($3.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      
        					      		$$.temp = inserer_code($$.temp, var);
        					      		$$.temp = inserer_code($$.temp, "=");
        					   		$$.temp = inserer_code($$.temp, $1.code);
        					     		$$.temp = inserer_code($$.temp, "<=");
        					      		$$.temp = inserer_code($$.temp, $3.code);
        					      
        					      		$$.code = inserer_code($$.code, var);
                                                                 
        							}
        							
        							
        | relational_expression GE_OP additive_expression  {        				    
        							     if ($1.type == ENTIER) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                                }} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
                                                                
        					      		    $$.code = init_code();
                                                        
                                                    		char *var = new_var();
        					      		$$.temp = init_code();
        					      		
        					      		$$.decla_tmp = init_code();
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					      		
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, "void ");
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, var);
        					      		$$.decla_tmp = inserer_code($$.decla_tmp, ";\n");
        					      		
        					      		 $$.temp = inserer_code($$.temp, $1.temp);
        					      		 if (strlen($1.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      		 $$.temp = inserer_code($$.temp, $3.temp);
        					      		 if (strlen($3.temp) != 0)
        					      		 	$$.temp = inserer_code($$.temp, ";\n");
        					      
        					      		$$.temp = inserer_code($$.temp, var);
        					      		$$.temp = inserer_code($$.temp, "=");
        					   		$$.temp = inserer_code($$.temp, $1.code);
        					     		$$.temp = inserer_code($$.temp, ">=");
        					      		$$.temp = inserer_code($$.temp, $3.code);
        					      
        					      		$$.code = inserer_code($$.code, var);
        							}	
        ;	

equality_expression
        : relational_expression {$$.type = $1.type;
        			   $$.code = $1.code;
        			   $$.temp = $1.temp;
        			   $$.decla_tmp = $1.decla_tmp;
        			 }
        			   				
        | equality_expression EQ_OP relational_expression   {   
        							     if ($1.type == ENTIER) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                                }} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
                                                                    $$.code = init_code();
        							    $$.code = inserer_code($$.code, $1.code);
        							    $$.code = inserer_code($$.code, "==");
        							    $$.code = inserer_code($$.code, $3.code);
        							    
        							    $$.temp= init_code();
        							
        							    
        							    $$.temp = inserer_code($$.temp, $1.temp);
        							    if ((strlen($1.temp) != 0) && (strlen($3.temp) != 0))
        							    	$$.temp = inserer_code($$.temp, ";\n"); 	
        							    $$.temp = inserer_code($$.temp, $3.temp);
        							    
        							    $$.decla_tmp = init_code();
        							    $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        							    $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        							    
        							}	
        							
        								
        | equality_expression NE_OP relational_expression  {       						    
        							     if ($1.type == ENTIER) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                                }} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
                                                                    $$.code = init_code();
        							    $$.code = inserer_code($$.code, $1.code);
        							    $$.code = inserer_code($$.code, "!=");
        							    $$.code = inserer_code($$.code, $3.code);
        							    
        							    $$.temp= init_code();
        							    $$.temp = inserer_code($$.temp, $1.temp);
        							    if ((strlen($1.temp) != 0) && (strlen($3.temp) != 0))
        							    	$$.temp = inserer_code($$.temp, ";\n"); 	
        							    $$.temp = inserer_code($$.temp, $3.temp);
        							    
        							    $$.decla_tmp = init_code();
        							    $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        							    $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        							}			
        ;

logical_and_expression
        : equality_expression   {$$.type = $1.type;
        			   $$.code = $1.code; 
        			   $$.temp = $1.temp; 
        			   $$.decla_tmp = $1.decla_tmp;
        			  }
        			   						
          | logical_and_expression AND_OP equality_expression  {   
        							     if ($1.type == ENTIER) {
                                                                	if ($3.type == ENTIER) {
                                                                        $$.type = ENTIER;
                                                                	} else {
                                                                        fprintf(stderr, "le 2ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type));
                                                                }} else {
                                                                        fprintf(stderr, "le 1er opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($1.type));
                                                                }
                                                                    $$.code = init_code();
                                                                    char* etiqS = new_label();
                                                                    char* etiqF = new_label();
                                                                    char* etiqT = new_label();
                                                                    char* etiqE = new_label();
                                                                    
        							    $$.code = inserer_code($$.code, "if (");
        							    $$.code = inserer_code($$.code, $1.code);
        							    $$.code = inserer_code($$.code, ") goto ");
                                                                  $$.code = inserer_code($$.code, etiqS);
        							    $$.code = inserer_code($$.code, ";\n");

        							    $$.code = inserer_code($$.code, "goto ");
        							    $$.code = inserer_code($$.code, etiqF);
                                                                  $$.code = inserer_code($$.code, ";\n");

                                                                  $$.code = inserer_code($$.code, "\n");
                                        			    $$.code = inserer_code($$.code, etiqS);
        							    $$.code = inserer_code($$.code, ":\n");

        							    $$.code = inserer_code($$.code, "if (");
        							    $$.code = inserer_code($$.code, $3.code);
                						    $$.code = inserer_code($$.code, ") goto ");
        							    $$.code = inserer_code($$.code, etiqT);
        							    $$.code = inserer_code($$.code, ";\n");

        							    $$.code = inserer_code($$.code, "goto");
        							    $$.code = inserer_code($$.code, etiqF);
                                                                  $$.code = inserer_code($$.code, ";\n");

                                                                  $$.code = inserer_code($$.code, "\n");
        							    $$.code = inserer_code($$.code, etiqT);
                                                    		    $$.code = inserer_code($$.code, ":\n");
                                                    		    
                                                    		    $$.code = inserer_code($$.code, "0");
        							    $$.code = inserer_code($$.code, ";\n");

                                        			    $$.code = inserer_code($$.code, "goto");
        							    $$.code = inserer_code($$.code, etiqE);
        							    $$.code = inserer_code($$.code, ";\n");

                                                                  $$.code = inserer_code($$.code, etiqF);
                                                                  $$.code = inserer_code($$.code, ":\n");
                                                                  
                                                                  $$.code = inserer_code($$.code, "1");
        							    $$.code = inserer_code($$.code, ";\n");
        							    
        							    $$.code = inserer_code($$.code, etiqE);
        							    $$.code = inserer_code($$.code, ":\n");
        							    
        							    $$.temp= init_code();
        							    $$.temp = inserer_code($$.temp, $1.temp);
        							    if ((strlen($1.temp) != 0) && (strlen($3.temp) != 0))
        							    	$$.temp = inserer_code($$.temp, ";\n"); 	
        							    $$.temp = inserer_code($$.temp, $3.temp);
        							    
        							    $$.decla_tmp = init_code();
        							    $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        							    $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
                                                                    
        							}
        ;

logical_or_expression
        : logical_and_expression {$$.type = $1.type;
        			   $$.code = $1.code; 
        			   $$.temp = $1.temp;
        			   $$.decla_tmp = $1.decla_tmp;
        			  }
        			   					
        | logical_or_expression OR_OP logical_and_expression   {   
        							    if ($3.type == $1.type){
        					   						$$.type = $3.type;
												} else  if (($1.type = POINTEUR) && ($1.type = ENTIER)) {
															$$.type = $1.type;
												} else {
        					   						fprintf(stderr, "Ligne %d : le 1er opérande est de type %s alors que le 2ème opérande est de type %s.\n",
													    yylineno, convert_type_t($1.type), convert_type_t($3.type)); 
												}
   					   	
                                                                    $$.code = init_code();
                                                                    char* etiqS = new_label();
                                                                    char* etiqF = new_label();
                                                                    char* etiqT = new_label();
                                                                    char* etiqFin = new_label();
                                                                    
        							    $$.code = inserer_code($$.code, "if (");
        							    $$.code = inserer_code($$.code, $1.code);
        							    $$.code = inserer_code($$.code, ") goto ");
                                                                  $$.code = inserer_code($$.code, etiqT);
        							    $$.code = inserer_code($$.code, ";\n");

        							    $$.code = inserer_code($$.code, "goto ");
        							    $$.code = inserer_code($$.code, etiqS);
                                                                  $$.code = inserer_code($$.code, ";\n");

                                                                  $$.code = inserer_code($$.code, "\n");
                                        			    $$.code = inserer_code($$.code, etiqS);
        							    $$.code = inserer_code($$.code, ":\n");

        							    $$.code = inserer_code($$.code, "if (");
        							    $$.code = inserer_code($$.code, $3.code);
                						    $$.code = inserer_code($$.code, ") goto ");
        							    $$.code = inserer_code($$.code, etiqT);
        							    $$.code = inserer_code($$.code, ";\n");
        							    
        							    $$.code = inserer_code($$.code, "goto ");
        							    $$.code = inserer_code($$.code, etiqF);
                                                                  $$.code = inserer_code($$.code, ";\n");
        							    
        							    $$.code = inserer_code($$.code, etiqT);
        							    $$.code = inserer_code($$.code, ":\n");
        							    $$.code = inserer_code($$.code, "0");
        							    $$.code = inserer_code($$.code, ";\n");
        							    
        							    $$.code = inserer_code($$.code, "goto ");
        							    $$.code = inserer_code($$.code, etiqFin);
                                                                  $$.code = inserer_code($$.code, ";\n");
        							    
        							    $$.code = inserer_code($$.code, etiqF);
        							    $$.code = inserer_code($$.code, ":\n");
        							    $$.code = inserer_code($$.code, "1");
        							    $$.code = inserer_code($$.code, ";\n");
        							    
                                                                  $$.code = inserer_code($$.code, etiqFin);
        							    $$.code = inserer_code($$.code, ":\n");
        							    
        							    $$.temp= init_code();
        							    $$.temp = inserer_code($$.temp, $1.temp);
        							    if ((strlen($1.temp) != 0) && (strlen($3.temp) != 0))
        							    	$$.temp = inserer_code($$.temp, ";\n"); 	
        							    $$.temp = inserer_code($$.temp, $3.temp);
        							    
        							    $$.decla_tmp = init_code();
        							    $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
        							    $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        							    }
        							 
        ;							 
        							 
expression
        : logical_or_expression  {$$.type = $1.type;
        			   $$.code = $1.code; 
        			   $$.temp = $1.temp;
        			   $$.decla_tmp = $$.decla_tmp;
        			  }	
        			   			
        | unary_expression '=' expression 	{ if ($3.type == $1.type){
        					   	$$.type = $3.type;
						} else  if (($1.type = POINTEUR) && ($1.type = ENTIER)) {
							$$.type = $1.type;
						} else {
        					   	fprintf(stderr, "Ligne %d : le 1er opérande est de type %s alors que le 2ème opérande est de type %s.\n", yylineno, convert_type_t($1.type), convert_type_t($3.type)); 
												}
   					   	
        					   	$$.temp = init_code();
        					   	$$.temp = inserer_code($$.temp, $1.temp);
        					   	if (strlen($1.temp) != 0)
        					   		$$.temp = inserer_code($$.temp, ";\n");
        					   	$$.temp = inserer_code($$.temp, $3.temp);
        					   	if (strlen($3.temp) != 0)
        					   		$$.temp = inserer_code($$.temp, ";\n");
        					        $$.temp = inserer_code($$.temp, $1.code);
        					   	$$.temp = inserer_code($$.temp, "=");
        					        $$.temp = inserer_code($$.temp, $3.code);
        					        
        					        $$.decla_tmp = $1.decla_tmp;
        					        $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        					        
        					   	$$.code = init_code();  				        
        					    }    
        ;

declaration
        : declaration_specifiers declarator ';'  	{ 
							 if ($1.type == POINTEUR) {
							  $$.code = init_code();
        						  $$.code = inserer_code($$.code, "void ");
        						  $$.code = inserer_code($$.code, $2.code);
        						  $$.code = inserer_code($$.code, ";\n");

        						  $$.temp = init_code();
        						  $$.temp = inserer_code($$.temp, $1.temp);
        						  $$.temp = inserer_code($$.temp, ";\n");
        						  $$.temp = inserer_code($$.temp, $2.temp);
							} else {
								  $$.code = init_code();
        						  $$.code = inserer_code($$.code, $1.code);
        						  $$.code = inserer_code($$.code, $2.code);
        						  $$.code = inserer_code($$.code, ";\n");

        						  $$.temp = init_code();
        						  $$.temp = inserer_code($$.temp, $1.temp);
        						  $$.temp = inserer_code($$.temp, ";\n");
        						  $$.temp = inserer_code($$.temp, $2.temp);	
								}  
        						}
        						
        						 
        | struct_specifier ';'  			{ $$.code = init_code();
        						  $$.code = inserer_code($$.code, $1.code);
        						  $$.type = STRUCTURE;
        						  $$.temp = "";
        						  $$.decla_tmp = "";
        						}
        ;

declaration_specifiers
        : EXTERN type_specifier  	{ $$.code = init_code();
        			   	  $$.code = inserer_code($$.code, "extern ");
        			   	  $$.code = inserer_code($$.code, $2.code);
        			   	  $$.type = $2.type; 
        			   	  $$.temp = "";
        			   	  $$.decla_tmp = "";
        			   	  }
        			   	  
        			   	  
        | type_specifier 		{ $$.code = $1.code;
        				  $$.type = $1.type;
        				  $$.temp = ""; 
        				  $$.decla_tmp = "";
        				  }					
        ;

type_specifier
        : VOID   { $$.code = "void ";
                   $$.type =  VIDE;
                   $$.temp = "";
                   $$.decla_tmp = "";
                     }                      						
        | INT  	 { $$.code = "int ";
                   $$.type = ENTIER;
                   $$.temp = ""; 
                   $$.decla_tmp = "";
                  }	                							
        | struct_specifier { $$.code = $1.code;
                             $$.type = $1.type; }						
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}'  { $$.code = init_code();
        							 }
        
        | STRUCT '{' struct_declaration_list '}' { $$.code = $3.code; 
        					   }
        
        | STRUCT IDENTIFIER    { $$.type = VIDE;
                                 $$.code = init_code();
                                 $$.code = inserer_code($$.code, "void ");
                                 $$.code = inserer_code($$.code, " ");       
                               }
        
        ;

struct_declaration_list 
        : struct_declaration { $$.code = $1.code;
                               $$.type = $1.type;
                               }
        | struct_declaration_list struct_declaration {$$.code = init_code();
        						$$.code = inserer_code($$.code, $1.code);
        						$$.code = inserer_code($$.code, $2.code);
                                                      $$.type = $2.type; }
        ;

struct_declaration
        : type_specifier declarator ';' { $$.code = init_code();
        			           $$.code = inserer_code($$.code, "void ");
        				   $$.code = inserer_code($$.code, $2.code);
                                          $$.type = $2.type; }
        ;
        
declarator
        : '*' direct_declarator  { 	$$.code = init_code();
        				$$.code = inserer_code($$.code, "*");
        				$$.code = inserer_code($$.code, $2.code);
        				$$.type = POINTEUR; 
                                       $$.temp = "";
                                       $$.decla_tmp = "";
                                     }
        				
        | direct_declarator  	   {	$$.code = $1.code;
        				$$.type = $1.type;
                                        $$.temp = "";
                                        $$.decla_tmp = "";
                                   }
        ;

direct_declarator
        : IDENTIFIER  {   
                      symbole_t *s = recherche(table_sym, strdup($1));
                      if (s == NULL)
                       	inserer(table_sym, $1);
                       else
                      		fprintf(stderr, "Variable \"%s\" a la ligne %d déja déclaré.\n",$1, yylineno);
                      	$$.code = $1;
                      	
                      	$$.temp="";
                      	$$.decla_tmp = "";
                      } 
                      
        | '(' declarator ')'      { $$.code = init_code();
        			     $$.code = inserer_code($$.code, "(");
        			     $$.code = inserer_code($$.code, $2.code);
        			     $$.code = inserer_code($$.code, ")");
        			     $$.temp=""; 
                                   $$.decla_tmp = "";
        			   }  
        	 
        | direct_declarator '(' parameter_list ')'         {	$$.code = init_code();
        							$$.code = inserer_code($$.code, $1.code);
        			     				$$.code = inserer_code($$.code, " (");
        			     				$$.code = inserer_code($$.code, $3.code);
        			     				$$.code = inserer_code($$.code, ")");
                                                                $$.temp = "";
                                                                $$.decla_tmp = "";    
        			   				} 
        			   				
        | direct_declarator '(' ')'  		 {	$$.code = init_code();
        							$$.code = inserer_code($$.code, $1.code);
        			     				$$.code = inserer_code($$.code, " (");
        			     				$$.code = inserer_code($$.code, ")");
                                                                $$.temp = ""; 
                                                                $$.decla_tmp = "";    
        			   				}     	
        ; 

parameter_list
        : parameter_declaration { if (($1.type = ENTIER) || ($1.type = POINTEUR)) {
                                          $$.type = $1.type;
                                  }else {
                                    fprintf(stderr, "Le type %s est mauvais a la ligne %d",convert_type_t($1.type), yylineno);
                                  }
                                  $$.code = $1.code; 
                                  $$.temp = "";
                                  $$.decla_tmp = "";
                                }
                                
        | parameter_list ',' parameter_declaration  { 
                                                      $$.code = init_code();
                                                      $$.code = inserer_code($$.code, $1.code);
                                                      $$.code = inserer_code($$.code, ",");
                                                      $$.code = inserer_code($$.code, $3.code);
                                                      $$.temp = "";
                                                      $$.decla_tmp = "";
                                                      }
        ;

parameter_declaration
        : declaration_specifiers declarator  {  $$.type = $2.type;
                                                	  $$.code = init_code();
                                                        $$.code = inserer_code($$.code, $1.code);
                                                        $$.code = inserer_code($$.code, $2.code);
                                                        $$.temp = "";
                                                        $$.decla_tmp = "";
                                                }
        
        ;

statement
        : compound_statement { $$.code = $1.code;
                               $$.type = $1.type;
                               $$.temp = $1.temp; 
                               $$.decla_tmp = $1.decla_tmp;
                               }
        | expression_statement  { $$.code = $1.code;
                                  $$.type = $1.type;
                                  $$.temp = $1.temp; 
                                  $$.decla_tmp = $1.decla_tmp;
                                 }
        | selection_statement  { $$.code = $1.code;
                                 $$.type = $1.type; 
                                 $$.temp = $1.temp;
                                 $$.decla_tmp = $1.decla_tmp;
                                }
        | iteration_statement { $$.code = $1.code;
                                $$.type = $1.type; 
                                $$.temp = $1.temp;
                                $$.decla_tmp = $1.decla_tmp;
                               }
        | jump_statement { $$.code = $1.code;
                           $$.type = $1.type; 
                           $$.temp = $1.temp;
                           $$.decla_tmp = $1.decla_tmp;
                         }
        ;

compound_statement
        : '{' '}'  {            $$.code = init_code();
                                $$.code = inserer_code($$.code, " { }\n");
                                $$.type = VIDE;
                                $$.temp = "";
                                $$.decla_tmp = "";
                         }
        | '{' statement_list '}'  { $$.code = init_code();
                                    $$.temp = $2.temp;
                                    $$.decla_tmp = $2.decla_tmp;
                                    $$.code = inserer_code($$.code, " {\n");
                                    $$.code = inserer_code($$.code, $$.temp);
                                    $$.code = inserer_code($$.code, $2.code);
                                    $$.code = inserer_code($$.code, "}\n");		
                                    $$.type = $2.type;
                                   
                                    }		
        | '{' declaration_list '}'  { $$.code = init_code(); 
         			       $$.temp = $2.temp;
         			       $$.decla_tmp = $2.decla_tmp;
                                      $$.code = inserer_code($$.code, " {\n");
                                      $$.code = inserer_code($$.code, $2.code);
                                      $$.code = inserer_code($$.code, "}\n");
                                      $$.type = $2.type;
                                      
                                    }			
        | '{' declaration_list statement_list '}' { 
                                                    $$.temp = $3.temp;
                                                    $$.decla_tmp = $2.decla_tmp;
                                                    $$.decla_tmp = $3.decla_tmp;
        					      $$.code = init_code();
                                                    $$.code = inserer_code($$.code, " {\n");
                                                    $$.code = inserer_code($$.code, $$.decla_tmp);
                                                    $$.code = inserer_code($$.code, $2.code);
                                                    $$.code = inserer_code($$.code, $$.temp);
                                                    $$.code = inserer_code($$.code, $3.code); 
                                                    $$.code = inserer_code($$.code, "}\n");
                                                    $$.type = $3.type;
                                                    
                                                 }
        ;

declaration_list
        : declaration { $$.code = $1.code;
                        $$.type = $1.type;
                        $$.temp = $1.temp;
                        $$.decla_tmp = $1.decla_tmp;
                       }                        
        | declaration_list declaration  { $$.code = init_code();
                                          $$.code = inserer_code($$.code, $1.code);
                                          $$.code = inserer_code($$.code, $2.code);
                                          $$.type = $2.type; 
                                          
                                          $$.temp = init_code();
                                          $$.temp = inserer_code($$.temp, $1.temp);
                                          $$.temp = inserer_code($$.temp, ";\n");
                                          $$.temp = inserer_code($$.temp, $2.temp);
                                          
                                          $$.decla_tmp = init_code();
                                          $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
                                          $$.decla_tmp = inserer_code($$.decla_tmp, $2.decla_tmp);
                                        }
        ;

statement_list
        : statement   { $$.code = init_code();
        		if ((strlen($1.temp) != 0) && (voir_dernier_carac($1.temp) == 1))
        			$$.code = inserer_code($$.code, ";\n");  //ici ca gerer le i au saut de ligne
        		$$.code = inserer_code($$.code, $1.code);
                        $$.type = $1.type;
                        $$.temp = $1.temp; 
                        $$.decla_tmp = $1.decla_tmp;
                        } 
                                               
        | statement_list statement { $$.code = init_code();
                                     $$.code = inserer_code($$.code, $1.code);
                                     $$.code = inserer_code($$.code, "  "); 
                                     $$.code = inserer_code($$.code, $2.code);
                                     $$.type = $2.type; 
                                     
                                     $$.temp = init_code();
                                     $$.temp = inserer_code($$.temp, $1.temp);
                                     if ((strlen($2.temp) != 0) && (strlen($1.temp) != 0))
                                     	  $$.temp = inserer_code($$.temp, ";\n");
                                     $$.temp = inserer_code($$.temp, $2.temp);
                                     
                                     $$.decla_tmp = init_code();
                                     $$.decla_tmp = inserer_code($$.decla_tmp, $1.decla_tmp);
                                     $$.decla_tmp = inserer_code($$.decla_tmp, $2.decla_tmp);
                                     
                                    }
        ;

expression_statement
        : ';'  	    {	        $$.code = init_code();
        			$$.code = inserer_code($$.code, ";\n"); 
        			$$.temp = "\n";
        			$$.decla_tmp = "\n";
        			}
        						
        | expression ';'	{ $$.code = init_code();
        			  $$.code = inserer_code($$.code, $1.code);
        			  if (strlen($1.code) != 0)
        			  	$$.code = inserer_code($$.code, ";\n"); 
        			  $$.type = $1.type;
        			  $$.temp = $1.temp;
        			  $$.decla_tmp = $1.decla_tmp; 
                                  }
        			  
        ;

selection_statement
        : IF '(' expression ')' statement %prec THEN  
        			{if ($3.type != ENTIER) {
                                	fprintf(stderr, "le 3ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type)); }
                                	
                                $$.code = init_code();
                                char *etiqIfT = new_label();
                                char *etiqFin = new_label();
                                $$.code = inserer_code($$.code, "if (");
                                $$.code = inserer_code($$.code, $3.code);
                                $$.code = inserer_code($$.code, ") goto ");
                                $$.code = inserer_code($$.code, etiqIfT);
                                $$.code = inserer_code($$.code, ";\n");
                                $$.code = inserer_code($$.code, "  goto ");
                                $$.code = inserer_code($$.code, etiqFin);
                                $$.code = inserer_code($$.code, ";\n");
                                $$.code = inserer_code($$.code, "  ");
                                $$.code = inserer_code($$.code, etiqIfT);
                                $$.code = inserer_code($$.code, ":\n");
                                $$.code = inserer_code($$.code, "  ");
                                $$.code = inserer_code($$.code, $5.code);
                                $$.code = inserer_code($$.code, "  ");
                                $$.code = inserer_code($$.code, etiqFin);
                                $$.code = inserer_code($$.code, ":\n");
                                
                                $$.temp = init_code();
                                
                                $$.decla_tmp = init_code();
                                $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
                                $$.decla_tmp = inserer_code($$.decla_tmp, $5.decla_tmp);
                                
        			$$.temp = inserer_code($$.temp, $3.temp);
        			$$.temp = inserer_code($$.temp, $5.temp);
        			
        			
                                }
                                
        
        | IF '(' expression ')' statement ELSE statement 
        			{if ($3.type != ENTIER) {
                                	fprintf(stderr, "le 3ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type)); }
        			  $$.code = init_code();
        			  char *resIf = retirer_carac($5.code);
        			  char *resElse = retirer_carac($7.code);
        			  char *etiqIF = new_label();
        			  char *etiqFin = new_label();
        			  
        			  char *ret = strstr(resElse, "return");
        			  
        			  if(ret) {
					  $$.code = inserer_code($$.code, "if (");
					  $$.code = inserer_code($$.code, $3.code);
					  $$.code = inserer_code($$.code, ") goto ");
					  $$.code = inserer_code($$.code, etiqIF);
					  $$.code = inserer_code($$.code, ";\n");
					  $$.code = inserer_code($$.code, "  ");
					  $$.code = inserer_code($$.code, resElse);
					  $$.code = inserer_code($$.code, "  ");
					  $$.code = inserer_code($$.code, etiqIF);
					  $$.code = inserer_code($$.code, ":\n");
					  $$.code = inserer_code($$.code, "  ");
					  $$.code = inserer_code($$.code, resIf);
        			  }
        			  
        			  else{
        			  
        			  $$.code = inserer_code($$.code, "if (");
        			  $$.code = inserer_code($$.code, $3.code);
        			  $$.code = inserer_code($$.code, ") goto ");
        			  $$.code = inserer_code($$.code, etiqIF);
        			  $$.code = inserer_code($$.code, ";\n");
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, resElse);
        			  $$.code = inserer_code($$.code, "  goto ");
        			  $$.code = inserer_code($$.code, etiqFin);
        			  $$.code = inserer_code($$.code, ";\n");
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, etiqIF);
        			  $$.code = inserer_code($$.code, ":\n");
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, resIf);
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, etiqFin);
        			  $$.code = inserer_code($$.code, ":\n");
        			  
        			  }
        			 
        			$$.temp = init_code();
        			
                                $$.decla_tmp = init_code();
                                $$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
                                $$.decla_tmp = inserer_code($$.decla_tmp, $5.decla_tmp);
        			
        			$$.temp = inserer_code($$.temp, $3.temp);
        			$$.temp = inserer_code($$.temp, $5.temp);
        			
        			
        			}
        
        ;

iteration_statement
        : WHILE '(' expression ')' statement  
        			{if ($3.type != ENTIER) {
					fprintf(stderr, "le 3ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type)); }
                                
                                $$.code = init_code();
                                char *res = retirer_carac($5.code);
                                char *etiqCond = new_label();
                                char *etiqWhile = new_label();
                                $$.code = inserer_code($$.code, "goto ");
				 $$.code = inserer_code($$.code, etiqCond);
				 $$.code = inserer_code($$.code, ";\n");
				 $$.code = inserer_code($$.code, "  ");
				 $$.code = inserer_code($$.code, etiqWhile);
				 $$.code = inserer_code($$.code, ":\n");
				 $$.code = inserer_code($$.code, "  ");
				 $$.code = inserer_code($$.code, res);
				 $$.code = inserer_code($$.code, "\n");
				 $$.code = inserer_code($$.code, "  ");
				 $$.code = inserer_code($$.code, etiqCond);
				 $$.code = inserer_code($$.code, ":\n  if (");
				 $$.code = inserer_code($$.code, $3.code);
				 $$.code = inserer_code($$.code, ") goto ");
				 $$.code = inserer_code($$.code, etiqWhile);
				 $$.code = inserer_code($$.code, ";\n"); 
				 
				$$.temp = init_code();
        			$$.temp = inserer_code($$.temp, $3.temp);
        			if (strlen($3.temp) != 0)
        				$$.temp = inserer_code($$.temp, ";\n");
        			$$.temp = inserer_code($$.temp, $5.temp);
        			
        			$$.decla_tmp = init_code();
        			$$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        			$$.decla_tmp = inserer_code($$.decla_tmp, $5.decla_tmp);
                                }
        
        
        | FOR '(' expression_statement expression_statement expression ')' statement  
        			{ if ($3.type != ENTIER) {
                                	fprintf(stderr, "le 3ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($3.type)); }
                                	
                                if ($4.type != ENTIER) {
                                	fprintf(stderr, "le 4ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($4.type)); }	
                                	
                                if ($5.type != ENTIER) {
                                	fprintf(stderr, "le 5ème opérande à la ligne %d n'est pas de type int mais de type %s.\n", yylineno, convert_type_t($5.type)); } 
                                	
                                char *test = $4.code;   		
        			  char *res = retirer_carac_fin(test);
        			  char *stat = retirer_carac($7.code);
        			  
        			  $$.code = init_code();
        			  $$.code = inserer_code($$.code, $3.code);
        			  $$.code = inserer_code($$.code, "\n");
        			  char *etiqTest1 = new_label();
        			  char *etiqFor1 = new_label();
        			  $$.code = inserer_code($$.code, "  goto ");
        			  $$.code = inserer_code($$.code, etiqTest1);
        			  $$.code = inserer_code($$.code, ";\n");
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, etiqFor1);
        			  $$.code = inserer_code($$.code, ":\n");
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, stat);
        			  $$.code = inserer_code($$.code, "\n");
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, $5.temp);
				  $$.code = inserer_code($$.code, ";\n");
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, etiqTest1);
        			  $$.code = inserer_code($$.code, ":\n");
        			  $$.code = inserer_code($$.code, "  ");
        			  $$.code = inserer_code($$.code, "if (");
        			  $$.code = inserer_code($$.code, res);
        			  $$.code = inserer_code($$.code, ") goto ");
        			  $$.code = inserer_code($$.code, etiqFor1);
        			  $$.code = inserer_code($$.code, ";\n");  
        			  
				$$.temp = init_code();
        			$$.temp = inserer_code($$.temp, $3.temp);
        			if (strlen($3.temp) != 0)
        				$$.temp = inserer_code($$.temp, ";\n");
				$$.temp = inserer_code($$.temp, $4.temp);
				if (strlen($4.temp) != 0)
					$$.temp = inserer_code($$.temp, ";\n");
				if (strlen($5.temp) != 0)
					$$.temp = inserer_code($$.temp, ";\n");	
		        	$$.temp = inserer_code($$.temp, $7.temp);	
		        	
		        	$$.decla_tmp = init_code();
        			$$.decla_tmp = inserer_code($$.decla_tmp, $3.decla_tmp);
        			$$.decla_tmp = inserer_code($$.decla_tmp, $4.decla_tmp);
        			$$.decla_tmp = inserer_code($$.decla_tmp, $5.decla_tmp);
        			$$.decla_tmp = inserer_code($$.decla_tmp, $7.decla_tmp);		                      	
                                }
        			  
        ;

jump_statement
        : RETURN ';' 	{ $$.code = init_code();
        		  $$.code = inserer_code($$.code, "return;\n");
        		  $$.temp="\n";
        		  $$.decla_tmp ="\n";
        		}
        
        | RETURN expression ';' { $$.code = init_code();
        			   $$.code = inserer_code($$.code, "return ");
        			   $$.code = inserer_code($$.code, $2.code);
        			   $$.code = inserer_code($$.code, ";\n"); 
        			   $$.temp = $2.temp;
        			   $$.decla_tmp = $2.decla_tmp;
        			   
        			 }
        ;

program
        : external_declaration   	    { $$.code = $1.code; 
        				      fwrite($1.code, 1, strlen($1.code), output_file); 
                                              }	
        
        | program external_declaration     {  $$.code = init_code();
        					$$.code = inserer_code($$.code, $1.code);
        					$$.code = inserer_code($$.code, $2.code);
        					fwrite($2.code, 1, strlen($2.code), output_file); 
        					
        				     }
        ;

external_declaration
        : function_definition	{ $$.code = $1.code;
        			  $$.type = $1.type; 
                                 }
        			  	
        | declaration 	    {	$$.code = $1.code;
        			$$.type = $1.type; 
        			$$.temp = $1.temp;
        			$$.decla_tmp = $1.decla_tmp;
        		 }	
        ;

function_definition
        : declaration_specifiers declarator compound_statement 	{ $$.code = init_code();
        							    	$$.code = inserer_code($$.code, "\n");
                                                                  	$$.code = inserer_code($$.code, $1.code);
                                                                  	$$.code = inserer_code($$.code, " ");
                                                                  	$$.code = inserer_code($$.code, $2.code);
                                                                  	$$.code = inserer_code($$.code, $3.code);
                                                                  	$$.code = inserer_code($$.code, "\n");
                                                                  	$$.type = $2.type;  
                                                                        }
        ;

%%


int yyerror(char *s) {
        fprintf(stderr, "Erreur de syntaxe a la ligne %d: %s\n", yylineno, s );
        exit(1);
}



int main(){
	table_sym = new_table();
	output_file = fopen(filename, "w");
        if (!output_file) {
           perror("fopen");
           exit(EXIT_FAILURE);
        }
	
  	yyparse();
  	supprime_table(table_sym);
  	fclose(output_file);
  	printf("Analyse réussi\n");
  	
        printf("Done Writing!\n");


  	return 0;
}










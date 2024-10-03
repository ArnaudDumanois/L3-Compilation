#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "generation_code.h"

int label_number = 0;
int var_number = 0;

char* init_code(){
    char* code = (char *) malloc(1);
    return strcpy(code, "");
}


char* inserer_code(char *code, char *insert){
    char *new_code = (char *) malloc((strlen(code)) + (strlen(insert)) + 1);
    strcpy(new_code, code);
    strcat(new_code, insert);
    return new_code;
}

char* new_label(){
    int num = label_number;
    char number[sizeof(int)*8+1];
    sprintf(number, "%d", num);
    char *label = (char *) malloc(8*sizeof(char *)+4*sizeof(int) + 1);
    strcpy(label, "label");
    strcat(label, number);
    label_number += 1;
    return label;
}


char* retirer_carac_fin(char *code){
	char *res = (char *) malloc(strlen(code)+1);
	int p = 0;
	for(int i = 0; i < strlen(code) - 2; i++){
		res[p] = code[i];
		p++;
	}
	return res;
}

char* retirer_carac(char *code){
	char *res = (char *) malloc(strlen(code)+1);
	char *vide = "\t";
	int p = 0;
	for(int i = 0; i < strlen(code); i++){
		if ((code[i] == '{') || (code[i] == '}')){
			res[p] = vide[0];
		  	p++;
		  	res[p] = vide[0];
		  	p++;}
		else { 
			res[p] = code[i];
			p++; }
	}
	return res;
}


char* new_var(){
    int num = var_number;
    char number[sizeof(int)*8+1];
    sprintf(number, "%d", num);
    char *var = (char *) malloc(8*sizeof(char *)+4*sizeof(int) + 1);
    strcpy(var, "tmp");
    strcat(var, number);
    var_number += 1;
    return var;
}


int voir_dernier_carac(char *code){
	int len = strlen(code) - 1;
	if ((code[len] == '\n') && (code[len-2] == ';'))
		return 0;
	else
		return 1;
}

	

	
	
	
	

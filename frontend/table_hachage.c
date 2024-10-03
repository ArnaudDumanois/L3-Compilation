#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_hachage.h"

#define TAILLE 103


int hash(char *nom){
  int i, r;
  int taille = strlen(nom);
  r = 0;
  for (i = 0; i < taille; i++)
    r = ((r << 8) + nom[i]) % TAILLE;
  return r;
}
  
table_t *new_table(){
  table_t *p = (table_t *) malloc(sizeof(table_t));
  p->suivant = NULL;
  p->precedent = NULL;
  for(int i=0; i<TAILLE; i++){
      p->table[i]=NULL;
    }
  return p;
}

symbole_t *inserer(table_t *tableSymbole, char *nom){
  int h;
  symbole_t *s;
  symbole_t *precedent;
  h = hash(nom);
  s = tableSymbole->table[h];
  precedent = NULL;
  while (s != NULL) {
      if (strcmp(s->nom, nom) == 0)
	return s; 
      precedent = s;
      s = s->suivant;
    }
  if (precedent == NULL) {
      tableSymbole->table[h] = (symbole_t *) malloc(sizeof(symbole_t));
      s = tableSymbole->table[h];
    }
  else {
      precedent->suivant = (symbole_t *) malloc(sizeof(symbole_t));
      s = precedent->suivant;
    }
  s->nom = strdup(nom);
  s->suivant = NULL;
  //s->type= NULL;
  //s->is_arg=0;
  return s;
}

symbole_t *recherche(table_t *tableSymbole, char *nom) {
  int h;
  symbole_t *s;
  h = hash(nom);
  s = tableSymbole->table[h];
  while (s != NULL) {
      if  (strcmp(s->nom, nom) == 0)
	return s;
      s = s->suivant;
    }
  return s;
}

char *convert_type_t(type_t t){
	if (t == 0)
		return "int";
	else if (t == 1)
		return "char";
	else if (t == 2)
		return "void";
	else if (t == 3)
		return "struct";
	else if (t == 4)
		return "extern";
	else if (t == 5)
		return "ptr";
	else
		return "error";
}
		

void supprime_table(table_t *t) {
  for(int i=0; i<100; i++)
    {
      free(t->table[i]);
      t->table[i]=NULL;
    }
  free(t->table); 
}

/*
void table_reset(){
	int i;
	for(i=0; i<TAILLE; i++)
		table[i] = NULL;
}  */



void afficher_table(table_t *t){
	int i;
	int cpt = 0;
	for(i=0; i<TAILLE; i++){
		symbole_t *s = t->table[i];
		if (s != NULL){
			printf("indice de la case tableau : %d\n", i);
			printf("nom de la variable : %s\n\n", s->nom);
		}
		else {
			printf("null\n");
			cpt++;}
	}
	printf("compteur = %d\n", cpt);
	printf("fin\n");
}
			
			




























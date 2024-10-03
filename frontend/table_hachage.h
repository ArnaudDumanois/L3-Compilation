#define TAILLE 103


typedef enum {ENTIER, CHAINE, VIDE, STRUCTURE, EXTERIEUR, POINTEUR } type_t;

typedef struct _symbole_t {
  char *nom;
  type_t type;
  struct _symbole_t *suivant;
} symbole_t;


typedef struct _table_t {
  symbole_t *table[TAILLE];
  struct _table_t *suivant;
  struct _table_t *precedent;
} table_t;

 
int hash(char *nom);
table_t *new_table();
symbole_t *inserer(table_t *tableSymbole, char *nom);
symbole_t *recherche(table_t *tableSymbole, char *nom);
void supprime_table(table_t *t);

char *convert_type_t(type_t t);

void afficher_table(table_t *t);




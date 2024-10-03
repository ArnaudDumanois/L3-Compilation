void k;
int yo;


extern void *malloc(int size);

extern void free(void *ptr);

struct liste {

  int valeur;
  
  struct liste *suivant;

};


struct liste *allouer(struct liste *p) {

  if (p!=0) {

        p->suivant=malloc(sizeof(p));

        return p->suivant;

  } else {

        p=malloc(sizeof(p));

        return p;

  }

}



struct liste *desallouer(struct liste *p) {

  struct liste *q;

  q=p->suivant;

  free(p);

  return q;

}



struct liste *parcours(struct liste *l, struct liste *(*f)(struct liste *p)) {

  int i;

  struct liste *p;

  struct liste *tete;

  tete=p=f(l); 

  for (i=0; i<100; i=i+1) {

    p=f(p);

  }

  return tete;

}



int main() {

  struct liste *tete;

  tete=parcours(0,&allouer);

  parcours(tete,&desallouer);

  return 1;

}

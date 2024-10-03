extern void *malloc(int size);

extern void free(void *ptr);



void *allouer(void *p) {

  if (p==0) goto Lelse1; 

  { 

    void *t1;

    void *_t2;

    _t1=p+4; 

    _t2=malloc(8);

    *_t1=_t2;

    return _t1;

  }

 Lelse1: 

  {

    p=malloc(8);

    return p;

  }

}


void *desallouer(void *p) {

  void *q;

  void *_t1;

  _t1=p+suivant;

  q=*_t1;

  free(p);

  return q;

}


void *parcours(void *l, void *f) {

  int i;

  void *p;

  void *tete;

  p=f(l);

  tete=p;

  i=0;

 

  goto Ltest1;

 Lfor1:

  p=f(p);

  i=i+1;

 Ltest1:

  if (i<100) goto Lfor1;

  return tete;

}


int main() {

  void *tete;

  void *_t1;

  void *_t2;

  _t1=&allouer;

  _t2=&desallouer;

  tete=parcours(0,_t1);

  parcours(tete,_t2);

  return 1;

}

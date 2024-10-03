struct liste {
	int valeur;
	struct liste *valeur;
};


struct liste *desallouer(struct liste *p) {

  struct liste *q;

  q=p->suivant;

  return q;

}

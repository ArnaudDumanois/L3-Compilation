extern int printd( int i );

int main() {
   int *i;
   int *j;
   
   i=malloc(sizeof(i));
   j=malloc(sizeof(j));

   *i=4;
  
   printd(*i);

   *j=6;
   printd(*j);

   *j=*j+(*i);
   printd(*j);
   return 0;
}

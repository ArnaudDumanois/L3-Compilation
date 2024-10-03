extern int printd (int i);

int  main () {
void tmp0;
void tmp1;
void tmp2;
void tmp3;
void tmp4;
void tmp5;
int i;
i=0;
tmp0=i<10;
;
tmp1=-10;
i=tmp1;
tmp2=i<=10;
;
;
i=0;
tmp4=i<=20;
tmp5=i+1;
i=tmp5;
  goto label0;
  label1:
  printd(i);

  label0:
  if (tmp0) goto label1;
  
  goto label2;
  label3:
  printd(i);

  tmp3=i+1;
i=tmp3;
  label2:
  if (tmp2) goto label3;
    goto label4;
  label5:
   		
tmp5=i+1;
i=tmp5printd(i);
  		

  label4:
  if (tmp4) goto label5;
  return 0;
}


#include<stdio.h>
void main()
{
FILE *p;
p=fopen("colab/p14.txt","ra+");

rewind(p);
char c[100];
fgets(c,sizeof(c),p);
fprintf(p,"%s","2nd year COE/CED\n");
fclose(p);



}

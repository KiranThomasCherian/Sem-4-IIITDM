#include<stdio.h>
#include<sys/stat.h>
void main()
{
char *dir="colab";
int a=mkdir(dir,0700);
/*if(!a)
printf("error");*/
FILE *p;
p=fopen("colab/p14.txt","w+");
fprintf(p,"%s","kiran thomas cherian\nced18i028");
fclose(p);
}

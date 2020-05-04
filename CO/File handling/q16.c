#include<stdio.h>
void main()
{
FILE *p;
p=fopen("colab/p14.txt","ra+");
int i=0;
char a[100][100];
while(!feof(p))
{
fgets(a[i],100,p);
i++;
}
fclose(p);
FILE *p1;
p1=fopen("colab/p14.txt","w+");
fputs(a[0],p1);
printf("Enter : ");
char z[100];
gets(z);

fputs(z,p1);
fputc('\n',p1);
for(int j=1;j<i;j++)
fputs(a[j],p1);
fclose(p1);



}

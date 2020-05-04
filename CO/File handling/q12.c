#include<stdio.h>
#include<string.h>
void main()
{
FILE *fp;
fp=fopen("3linetext.txt","r+");
char a[100];
while(fgets(a,sizeof(a),fp)!=NULL)
{
puts(a);
}
fclose(fp);
}

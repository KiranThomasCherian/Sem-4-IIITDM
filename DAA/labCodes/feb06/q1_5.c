#include<stdio.h>
int heap[1000000][2], hsize=0;

int min=0,minindex=0;

void insert(int p,int pi)
{
	hsize++;
	heap[hsize][0] = p;
	heap[hsize][1] = pi;
	int t = hsize;
	while((t/2 >= 1) && (heap[t][0] <= heap[t / 2][0]))
	{
		heap[t][0] = heap[t][0] ^ heap[t/2][0];
		heap[t][1] = heap[t][1] ^ heap[t/2][1];

		heap[t/2][0] = heap[t][0] ^ heap[t/2][0];
		heap[t/2][1] = heap[t][1] ^ heap[t/2][1];

		heap[t][0] = heap[t][0] ^ heap[t/2][0];
		heap[t][1] = heap[t][1] ^ heap[t/2][1];
		t /= 2;
	}
}
void delete()
{
	int x = heap[1][0];
	int xi=heap[1][1];
	heap[1][0] = heap[hsize][0];
	heap[1][1] = heap[hsize][1];
	hsize--;
	int t = 1;
	int mi;
	while(2*t  <= hsize)
	{
		if(hsize >= 2*t+1)
		{
			if(heap[2*t][0] < heap[2*t+1][0])
				mi = 2*t;
			else 
				mi = 2*t+1;
		}
		else 
			mi = 2*t;
		if(heap[t][0] >= heap[mi][0])
		{
			heap[t][0] = heap[t][0] ^ heap[mi][0];
			heap[t][1] = heap[t][1] ^ heap[mi][1];
			
			heap[mi][0] = heap[t][0] ^ heap[mi][0];
			heap[mi][1] = heap[t][1] ^ heap[mi][1];

			heap[t][0] = heap[t][0] ^ heap[mi][0];
			heap[t][1] = heap[t][1] ^ heap[mi][1];
			t = mi;
		}
		else break;
	}
	min=x;
	minindex=xi;
}

void main() 
{	





int k;
int a[100][100];
printf("Enter No of arrays: ");
scanf("%d",&k);
int n[100];
for(int i=0;i<k;i++)
	{
	printf("Enter size of array %d: ",i+1);
	scanf("%d",&n[i]);
	printf("Enter array %d \n", i+1);
	for(int j=0;j<n[i];j++)
	scanf("%d",&a[i][j]);
	}
int ntemp[100];
for(int i=0;i<k;i++)
ntemp[i]=n[i];
for(int i=0;i<k;i++)
insert(a[i][0],i);	//initilaizing heap

/*
while(hsize!=0)
{
delete();
printf(" %d %d \n ",min,minindex);
}*/
//}


int flag=1,i,tempmini,minii,x;


int count=0;//no need
i=0;// no need
while(flag)
{

/*
ii:
if(ntemp[i]==0)
{
i++;
if(i==k)
break;
goto ii;
}
*/

delete();

printf(" %d ",min);
--ntemp[minindex];
x=minindex;
tempmini=n[x]-(ntemp[x]);
if(tempmini!=n[x])
{

//printf("\n %d %d %d\n ",a[x][tempmini],x,tempmini) ;
insert(a[x][tempmini],x);

}
else
{

/*
for(i=0;i<k;i++)
{
if((a[i][n[i]-ntemp[i]])!=n[i])
{
insert(a[x][tempmini],x);
break;
}
}


*/

for(i=0;i<k;i++)
{
if(ntemp[i]!=0)
{
flag=1;
break;
}
else 
flag=0;
}

}
//printf("\n %d %d %d \n",ntemp[minindex],tempmini,x);



//flag=0;
}

}





/*
    int n;
    scanf("%d", &n);
    int i, element;
    hsize=0;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &element);
        Insert(element);
    }
    for (i = 0; i < n; i++) {
        printf("%d ", Delete());
    }
    printf("\n");
    return 0;
}*/

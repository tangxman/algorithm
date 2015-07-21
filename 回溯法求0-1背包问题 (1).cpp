#include <stdio.h>

int w[5]={3,5,2,1,4};
int v[5]={9,10,7,4,3};
int best=0;
int temp=0;
int a[5]={0};
int b[5]={0};
int wt=0;
int n=5;
int c=10;

void fun(int i)
{
	if(i>=n)
	{
		if(temp>best)
		{
			for(int j=0;j<n;j++)
				b[j]=a[j];
			best=temp;
		}
	}
	else
	{
		if(wt+w[i]<=c)
		{
			a[i]=1;
			wt+=w[i];
			temp+=v[i];
			fun(i+1);
			wt-=w[i];
			temp-=v[i];
		}
		a[i]=0;
		fun(i+1);
	}
}



void main()
{
	fun(0);
	for(int i=0;i<n;i++)
		printf("%d ",b[i]);
	printf("\n%d\n",best);
}
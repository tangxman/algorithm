/*设计一个O(n2)时间的算法，找出由n个数组成的序列的最长单调递增子序列。*/
#include <stdio.h>
#define N 100

void prin(int i);
void fun(int n);
int p[N],a[N];

void main()
{
	int i,n;
	printf("input n:");
	scanf("%d",&n);
	printf("input the array.\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	fun(n);

}

void fun(int n)
{
	int m[N];
	int i,k,max;
	m[0]=1;
	p[0]=-1;
	for(i=1;i<n;i++)
	{
		max=0;
		p[i]=-1;
		for(k=0;k<i;k++)
		{
			if(m[k]>max&&a[k]<a[i])
			{
				p[i]=k;
				max=m[k];                   
			}
		}
		m[i]=max+1;
	}
	i=0;
	for(k=1;k<n;k++)
	{
		if(m[k]>m[i])
		{
			i=k;
		}
	}	
	prin(i);
	printf("\nlen=%d\n",m[i]);

}

void prin(int i)
{
	if(p[i]<0)
	{
		printf("%d",a[i]);
		return;
	}
	prin(p[i]);
	printf(",%d",a[i]);
}
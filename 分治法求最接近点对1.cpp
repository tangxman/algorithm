/*4	用分治法输出一个一维数组中的n个不同实数间距离最小的两个实数。
输入：实数数组X, 实数个数n, 输出: 距离最小的两个实数.*/

#include<stdio.h>
#include<math.h>
#define N 10000

int c1=0,c2=1;

int min(int a,int b,int c)
{
	int m;
	m=a<b?a:b;
	return m<c?m:c;
}

int Cpair(int S[],int left,int right)
{
	int l,r,n;
	int d,d1,d2;
	n=right-left+1;
	if(n<2)
	{
		d=100000;
		return d;
	}
	else if(n==2)
	{
		d=S[right]-S[left];
		return d;
	}
	else
	{
		if(n%2==0)
		{
			l=n/2;
			r=n/2-1;
		}
		else
		{
			l=(n+1)/2;
			r=(n-1)/2;
		}
		d1=Cpair(S,0,r);
		d2=Cpair(S,l,n-1);
		if(d2<d1)
		{
			c1=left;
			c2=right;
		}
		d=min(d1,d2,S[l]-S[r]);
		if(d==S[l]-S[r])
		{
			c1=r;
			c2=l;
		}
		return d;
	}
}

void main()
{
	int i,j,n,S[N],dis;	
	printf("请输入数据个数：");
	scanf("%d",&n);
	printf("请输入数据\n");
	for(i=0;i<n;i++)
		scanf("%d",&S[i]);	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(S[j]>S[j+1])
			{
				S[j]^=S[j+1];
				S[j+1]^=S[j];
				S[j]^=S[j+1];
			}
		}
	}
	dis=Cpair(S,0,n-1);
	printf("最短的距离是：%d\n",dis);
	printf("最近的两个数是：%d %d\n",S[c1],S[c2]);
}
/*6	试用动态规划的方法，求解0-1背包问题: 有一背包，能装入物体总重量为C, 
有n个物体，重量为w1,w2,..,wn, 价值分别为v1,v2,…vn。试求一种装载方案，
使得背包装载的物体总价值最大。其中，C, w都是整数。*/
#include<stdio.h>
#define N 50

int max(int a,int b)
{
	return a>b?a:b;
}

void KnapSack(int n,int C,int w[],int m[])
{
	int i,j,V[N][N],x[N];
	for(i=0;i<=n;i++)
		V[i][0]=0;
	for(j=0;j<=C;j++)
		V[0][j]=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=C;j++)
		{
			if(j<w[i])
				V[i][j]=V[i-1][j];
			else
				V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+m[i]);
		}
	}
	j=C;
	for(i=n;i>0;i--)
	{
		if(V[i][j]>V[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		else
			x[i]=0;			
	}

	printf("构成最大价值的物品是:");
	for(i=1;i<=n;i++)
	{
		if(x[i]!=0)
			printf("%d ",i);
	}
	printf("\n最大价值为:%d\n",V[n][C]);
}

void main()
{
	int w[N],m[N];
	int C,i,n;
	printf("请输入背包的容量：");
	scanf("%d",&C);
	printf("请输入物品的个数：");
	scanf("%d",&n);
	printf("请输入每个物品的质量和价值，以分号隔开\n");
	w[0]=m[0]=0;
	for(i=1;i<=n;i++)
	{
		printf("第%d个物品的质量和价值分别为:",i);
		scanf("%d%d",&w[i],&m[i]);
	}
	KnapSack(n,C,w,m);
}
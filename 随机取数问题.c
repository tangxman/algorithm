/*
1从1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20这20个数中随机选择5个数字,这5个数不能重复。
（可以进一步考虑从n个数随即选出m个不重复的数）
*/

#include<stdio.h>
#include<stdlib.h>
#define M 10000

void main()
{
	int a[M];
	int i=1,j=0,n,m,seed=10000;
	double x;
	printf("请输入随机数区间1~");
	scanf("%d",&n);	
	printf("请输入随机数的个数:");
	scanf("%d",&m);
	printf("请输入种子：");
	scanf("%d",&seed);
	srand(seed);
	printf("这%d个随机数分别为：",m);
	for(i=1;i<=n;i++)
		a[i]=0;
	while(j<m)
	{
		x=((double)rand()/((double)(RAND_MAX)+(double)(1)));
	    i=(int)(x*n);
		if(a[i]==0)
		{
			a[i]=1;
			j++;
			printf("%d ",i);
		}
	}
	printf("\n");
}


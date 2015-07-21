/*
随机产生100000个int型正整数，输入k值（100<=k<=500），
要求输出最小的k个整数。
用两种方法实现。

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 100000

int main()
{
	int i,j=0,m,n,k,h=0;
	int a[M];
	double x;
	printf("请输入你要产生随机数的区间1~");
	scanf("%d",&m);
	printf("请输入你要产生随机数的个数n：");
	scanf("%d",&n);
	printf("请输入你要取其中最小数的个数100~500：");
	scanf("%d",&k);
	srand((int)time(0));
	while(j<n)
	{
		x=((double)rand()/((double)(RAND_MAX)+(double)(1)));
		i=(int)(x*m);
		a[j]=i;
		j++;
	}
	printf("这100000个随机数中最小的%d个数为：",k);
	j=0;   
	for(i=1;i<M;i++)
	{
		for(h=0;h<M;h++)
		{
			if(a[h]==i)
			{
				printf("%d ",a[h]);
				j++;
			}
			if(j==k)
			goto loop;
		}
	}
loop:return 0;
}




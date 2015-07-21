/*
随机产生100000个int型正整数，输入k值（100<=k<=500），
要求输出最小的k个整数。
用两种方法实现。

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 10000

void main()
{
	int i,j=0,m,n,k;
	int str[M],a[M];
	double x;
	printf("请输入你要产生随机数的区间1~");
	scanf("%d",&m);
	printf("请输入你要产生随机数的个数n：");
	scanf("%d",&n);
	printf("请输入你要取其中最小数的个数100~500：");
	scanf("%d",&k);
	srand((int)time(0));
	for(i=0;i<m;i++)
		str[i]=0;
	for(i=0;i<m;i++)
		a[i]=1;
	while(j<n)
	{
		
		x=((double)rand()/((double)(RAND_MAX)+(double)(1)));
		i=(int)(x*m);
		if(str[i]==0)
			str[i]=i;
		else	a[i]++;		 
		j++;
	}
	j=0;
	i=1;
	while(j<k)
	{
		if(str[i]!=0)
		{
			while(a[i]!=0)
			{
			    printf("%d ",str[i]);
				j++;
				a[i]--; 		
			}
			i++;        
		}
		else i++;
	}
}





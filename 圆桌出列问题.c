/*
假设有n个人围坐在一张圆桌上，现从某一个人开始报数，数到第m个人出列，
如此下去直到所有的人都出列，求出他们的出列顺序（可以将人转换为相应的数字）
*/

#include<stdio.h>
#define M 100

int main()
{
	int a[M],b[M]={0};
	int i,s,n,m,x;
	printf("请输入个数：");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    printf("请输入第%d个元素",i+1);
	    scanf("%d",&a[i]);
	}
	printf("请输入从第几个元素开始：");
	scanf("%d",&x);
	printf("请输入每隔几个元素出列：");
	scanf("%d",&m);
	i=0;
	printf("出列的顺序为：");
	while(i<n)
	{
		i++;
		s=m*i+x-2;
		while(s>=n)
			s=s-n;
		while(b[s]==1)
			s++;
        if(s>=n)
			s=s-n;
        printf("%d ",a[s]);
		b[s]=1;
	}
	printf("\n");
	return 0;
}



  

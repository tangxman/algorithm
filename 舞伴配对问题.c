/*
在周末舞会上，男士们（m人）和女士们（n人, n<m）进入舞厅时，各自排成一队。
跳舞开始时，依次从男队和女队的队头上各出一人配成舞伴。
若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。
现要求写一算法模拟上述舞伴配对问题。
（1）在第t首曲子时，第x个女生和第几个男生配对跳舞？
（2）在什么条件下，上述题目中第x个（1<=x<=m）男生才有可能和他心仪的第y个（1<=x<=n）女生跳舞，
在第几首曲子时？
*/

#include<stdio.h>
#include<stdlib.h>
#define M 100

int fun1(int m,int n,int x,int t)//在第t首曲子时，第x个女生和第几个男生配对跳舞
{
	int i,j=0,h=1,s,a[M],b[M];
	for(i=0;i<m;i++)
		a[i]=i;
	while(h<t)
	{
		for(i=0;i<m;i++)
			b[i]=a[i];
		for(j=0;j<m;j++)
		{
			if(j<=n-1)
				a[m-n+j]=b[j];
			else a[j-n]=b[j];
		}
		h++;
	}
	s=a[x-1];
	return s+1;
}

int fun2(int m,int n,int A,int B)//判断第x个男生第y个女生是否能跳舞
{
	int i,j=0,h=1,a[M],b[M],c[M];
	for(i=0;i<m;i++)
	{
		a[i]=i;
	    c[i]=i;
	}
	while(a[B-1]!=A-1)
	{
		h++;
        for(i=0;i<m;i++)
			b[i]=a[i];
		for(j=0;j<m;j++)
		{
			if(j<=n-1)
				a[m-n+j]=b[j];
			else a[j-n]=b[j];
		}
		j=0;
		for(i=0;i<m;i++)
		{
			if(a[i]==c[j])
				j++;
			else
				break;
			if(j==m-1)
			{
				printf("他们两没有机会一起跳舞！\n");
				exit(1);
			}
		}						
	}
	return h;
}

void main()
{
	int m,n,t,x,h,A,B,C;
	printf("请分别输入男生和女生的人数m和n(m>n)\n");
	printf("请输入男生的人数m:");
	scanf("%d",&m);
	printf("请输入女生的人数n:");
	scanf("%d",&n);
	/*printf("请输入是第几个女生:");
	scanf("%d",&x);
	printf("请输入是第几首子曲:");
	scanf("%d",&t);	
	h=fun1(m,n,x,t);
	printf("与这个女生配对的是第%d个男生\n",h);*/
	printf("\n");
	printf("请输入是第几个男生和他心仪的是第几个女生\n");
	printf("请输入是第几个男生：");
	scanf("%d",&A);
	printf("请输入是第几个女生：");
	scanf("%d",&B);
	C=fun2(m,n,A,B);
	printf("他们两在第%d首歌曲的时候就可以一起跳舞\n",C);
}

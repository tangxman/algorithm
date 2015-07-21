/*
输入一个10进制正整数，然后输出它所对应的2进制，8进制，16进制数。
*/
#include<stdio.h>
#define M 100

char b[6]={'A','B','C','D','E','F'};

void fun1(int p,int q)
{
	int i=0,j=0,h,x,a[M];
	while(p!=0)
	{
		h=p%q;
		p=p/q;
		a[i]=h;
		i++;
	}
	x=i;
	for(i=x-1;i>=0;i--)
	printf("%d",a[i]);
}

void fun2(int p,int q)
{
	int i=0,j=0,h,x;
	char a[M];
	while(p!=0)
	{
		h=p%q;
		p=p/q;
		if(h>=10)
		    a[i]=b[h-10];
		else
			a[i]=h;
		i++;
	}
    x=i;
	for(i=x-1;i>=0;i--)
		if(a[i]<10)
			printf("%d",a[i]);
		else
	        printf("%c",a[i]);
}

void main()
{
	int p;
	printf("请输入要转换的整数:");
	scanf("%d",&p);
	printf("这个数转换为二进制为");
	fun1(p,2);
	printf("\n");
	printf("这个数转换为八进制为");
	fun1(p,8);
	printf("\n");
	printf("这个数转换为十六进制为");	
	fun2(p,16);
	printf("\n");
}
		




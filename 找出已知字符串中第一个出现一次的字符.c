/*
在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b
注：注意效率，时间复杂度和空间复杂度尽可能低

*/

#include<stdio.h>
#define M 256

int main()
{
	int i,m,h;
	int a[M]={0};
	char str[M];
	printf("请输入字符串：");
	for(i=0;i<M;i++)
	{
		scanf("%c",&str[i]);
		if(str[i]=='$')
			break;
	}
	m=i;
	for(i=0;i<m;i++)
	{
		h=str[i];
		a[h]++;
	}
	for(i=0;i<m;i++)
	{
		h=str[i];
		if(a[h]==1)
		{
			printf("该字符串中第一个只出现一次的字符是%c\n",str[i]);
		    return 0;
		}
	}
	printf("该字符串中没有只出现一次的字符！\n");
	return 0;
}
		




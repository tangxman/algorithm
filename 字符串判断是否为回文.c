/*
请编写函数fun,该函数的功能是：判断字符串是否为回文。若是，则函数返回1，主函数中输出YES，
否则返回0，在主函数中输出NO。回文是指顺读和 倒读都是一样的字符串。
*/
#include<stdio.h>
#include<string.h>
#define M 20

int fun()
{
	int i,j=0,m,h,temp;
	char str2[M],str1[M];
	printf("请输入字符串：");
	scanf("%s",str1);
	m=strlen(str1);
	for(i=m-1;i>=0;i--)
	{
		str2[j]=str1[i];
	    j++;
	}
	i=0;
	while(i<m)
	{
		if(str2[i]>128||str2[i]<0)
		{
			temp=str2[i];
			str2[i]=str2[i+1];
			str2[i+1]=temp;
			i=i+2;
		}
		else i++;
	}
	str2[i]='\0';
	printf("%s\n",str2);
	h=strncmp(str1,str2,m);
	if(h==0)
		return 1;
	else
		return 0;
}

void main()
{
	if(fun()==1)
		printf("YES\n");
	else
		printf("NO\n");
}









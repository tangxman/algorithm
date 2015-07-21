/*
在主函数中输入10个等长的字符串。用另外一函数对他们进行排序（采用字符的升序或降序）。
然后在主函数输出这10个已经排好序的字符串（不允许采用strcmp函数）
*/
#include<stdio.h>
#include<string.h>
#define M 100

void fun(char a[10][M],int n)
{
	char str[10][M];
	int i,j,k,h;
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			k=0;
			while(k<n)
			{
				if(a[i][k]<a[j][k])
					break;
				else if(a[i][k]>a[j][k])
				{
					for(h=0;h<n;h++)
					{
						str[i][h]=a[i][h];
						a[i][h]=a[j][h];
						a[j][h]=str[i][h];
					}
					break;
				}
				else k++;
			}	
		}
	}

}

void main()
{
	char a[10][M],ch;
	int i,j,n;
	printf("请输入字符串的长度:");
	scanf("%d",&n);	
	for(i=0;i<10;i++)
	{
		ch=getchar();
		for(j=0;j<n;j++)
		{
			scanf("%c",&a[i][j]);
		}
	}
	fun(a,n);
	printf("排序之后：\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c",a[i][j]);
		    
		}
		printf("\n");
	}
}
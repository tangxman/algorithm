/*用递归的方法设计全排列输出的算法. 输入：字符数组A，字符个数n，输出：打印全排列。*/

#include<stdio.h>
#define N 10000 
#define M 20

int count=0,j=0;
char str[N][M];

void swap(char *a,char *b)
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;

}

void sort(char list[],int k,int m)
{
	int i,h=0,x;
	if(k==m-1)
	{
		while(h<j)
		{
			x=0;
			for(i=0;i<m;i++)
			{
				if(list[i]==str[h][i])
					x++;
			}
			if(x==m)
				return;
			else
				h++;
		}
		for(i=0;i<m;i++)
		{
			str[j][i]=list[i];
			printf("%c ",list[i]);
		}
		printf("\n");
		j++;
		count++;
	}
	else
	{
		for(i=k;i<m;i++)
		{
			swap(&list[k],&list[i]);
			sort(list,k+1,m);
			swap(&list[k],&list[i]);
		}
	}
}


void main()
{
	int i,n;
	char list[N];
	printf("请输入字符个数：");
	scanf("%d",&n);
	printf("请输入字符：");
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c",&list[i]);
	}
	sort(list,0,n);
	printf("total:%d\n",count);
}

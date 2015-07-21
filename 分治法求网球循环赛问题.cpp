/*5	设有n个运动员进行网球循环赛。设计一个满足下列要求的比赛日程表：
（1）每个选手必须与其他n-1个选手比赛一次；
（2）每个选手一天只能赛1次
（3）当n是偶数时，循环进行n-1天，当n是奇数时，循环赛进行n天
*/
#include<stdio.h>
#define N 1000

void fun(int n);
void copy(int n);
void copy1(int n);
void copy2(int n);

int a[N][N],b[N];

void copy(int n)
{
	if(n/2>1&&n/2%2!=0)
		copy1(n);
	else
		copy2(n);

}

void copy1(int n)
{
	int m,i,j;
	m=n/2;
	for(i=0;i<m;i++)
	{
		b[i]=m+i;
		b[m+i]=b[i];
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m+1;j++)//由左上角小块的值算出相应的左下角小块的值
		{
			if(a[i][j]>=m)
			{
				a[i][j]=b[i];
				a[m+i][j]=(b[i]+m)%n;
			}
			else
				a[m+i][j]=a[i][j]+m;
		}
		for(j=1;j<m;j++)//由左上角小块的值算出相应的右上角和右下角小块的值
		{
			a[i][m+j]=b[i+j];
			a[b[i+j]][m+j]=i;
		}

	}

}

void copy2(int n)
{
	int i,m,j;
    m=n/2;
    for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j+m]=a[i][j]+m;//由左上角小块的值算出对应的右上角小块的值
			a[i+m][j]=a[i][j+m];//由右上角小块的值算出对应的左下角小块的值
			a[i+m][j+m]=a[i][j];//由左上角小块的值算出对应的右下角小块的值

		}
	}
}

void fun(int n)
{
	if(n==1)
	{
		a[0][0]=0;
		return;
	}
	if(n%2==1)
	{
		fun(n+1);
		return;
	}
	fun(n/2);
	copy(n);
}


void main()
{
	int i,num,j;
	printf("参赛队伍数：");
	scanf("%d",&num);
	fun(num);
	if(num%2!=0)
		num++;
	for(i=1;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			printf("%d ",a[i][j]+1);
		}
		printf("\n");
	}
	printf("注：当n为奇数时代号为n+1的球队，当天轮空！\n");
}

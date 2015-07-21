/*
二维矩阵相乘, 输入第一个矩阵 行数、 列数、 数据，输入第二个矩阵行、列、数据 ，
打印结果，若两矩阵不能乘则打印“矩阵不能相乘”。
*/
#include<stdio.h>
#define A 100
#define B 100
#define N 100

void xiangchen(int a[A][B],int b[A][B],int x,int y,int z)
{
    int c[A][N];
	int i,j,s,m=0,n=0;
    for(i=0;i<x;i++)
	{   
		for(n=0;n<y;n++)
		{
		    s=0;
		    for(j=0;j<y;j++)   
			s+=a[i][j]*b[j][n];	
			c[i][n]=s;					
		}
	}
	for(i=0;i<x;i++)
	{	
		for(j=0;j<z;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
}

int main()
{   
	int a[A][B],b[B][N];
	int i,j,m,n;
    int x1,y1,x2,y2;
    printf("请输入第一个矩阵的行：");
    scanf("%d",&x1);
    printf("请输入第一个矩阵的列：");
    scanf("%d",&y1);
    printf("请输入第二个矩阵的行：");
    scanf("%d",&x2);
    printf("请输入第二个矩阵的列：");
    scanf("%d",&y2);
	if(y1!=x2)
	{
       printf("矩阵一不能乘以矩阵二！！！\n");
	   return 0;
	}
    else 
    printf("矩阵一可以乘以矩阵二！！！\n");
	printf("请输入第一个矩阵：\n");
    for(i=0;i<x1;i++)
    for(j=0;j<y1;j++)
	   scanf("%d",&a[i][j]);
	printf("请输入第二个矩阵：\n");
    for(m=0;m<x2;m++)
    for(n=0;n<y2;n++)
	   scanf("%d",&b[m][n]);
    printf("新矩阵为：\n");
	xiangchen(a,b,x1,y1,y2);
    return 0;
}


/**
编写程序，输出两个字符串的最长公共子序列的长度，及其一个子序列。
*/

#include<stdio.h>
#define M 100
int count=0;
char PL[M];

void LCSLength(int m,int n,char *x,char *y,int (*c)[M],int (*b)[M])
{
	int i,j;
	for(i=0;i<=m;i++)c[i][0]=0;
	for(j=0;j<=n;j++)c[0][j]=0;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else{
				if(c[i-1][j]>=c[i][j-1]){
					c[i][j]=c[i-1][j];
					b[i][j]=2;
				}else{
					c[i][j]=c[i][j-1];
					b[i][j]=3;
				}				
			}
		}
	}
}

void LCS(int i,int j,char x[M],int b[M][M])
{
	if(i==0||j==0)return;
	if(b[i][j]==1){
		LCS(i-1,j-1,x,b);
		PL[count]=x[i-1];//
		count++;//计算最长子序列长度

	}
	else if(b[i][j]==2)
		LCS(i-1,j,x,b);
	else
		LCS(i,j-1,x,b);
}

void main()
{
	int i=0,j=0,h;
	int b[M][M],c[M][M];
	char x[M],y[M];
	char t;

	while(1)
	{
		t=getchar();
		if(t=='\n'||t==' ')
		{
			break;			
		}
		x[i]=t;
		i++;
	}

	while(1)
	{
		t=getchar();
		if(t=='\n'||t==' ')
		{
			break;			
		}
		y[j]=t;
		j++;
	}	
	LCSLength(i,j,x,y,c,b);

	LCS(i,j,x,b);

	printf("%d ",count);
	for(h=0;h<count;h++)
	{
		printf("%c",PL[h]);
	}
	printf("\n");
}
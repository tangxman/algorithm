#include <stdio.h>
#define M 100
#define MAXLENGTH 0x7ffff

int tree[M];
int close[M];

int approxTSP(char a[M],int b[M][M],int n)
{
	int h=0,k=0,min,cost=0;
	while(k<n)
	{
		tree[k]=h;
		close[h]=-1;
		for(int i=0;i<n;i++){
			if(b[h][i]<close[i]){
				close[i]=b[h][i];
			}
		}
		min=MAXLENGTH;
		for(int j=0;j<n;j++){
			if(close[j]>0&&close[j]<min){
				min=close[j];
				h=j;
			}
		}
		k++;
	}
	tree[k]=0;
	for(k=0;k<n;k++)
	{
		cost+=b[tree[k]][tree[k+1]];
	}
	printf("最短旅行路径为：\n");
	for(k=0;k<=n;k++){
		printf("%c ",a[tree[k]]);
	}
	printf("\n");
	return cost;
}

void main()
{
	int n,i,cost;
	int c1,c2,d;
	int b[M][M];
	char a[M];
	printf("请输入顶点个数：");
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		a[i]=(char)(i+1+48);
	}	
	printf("请输入顶点序号及其之间的距离：\n");
	for(i=0;i<n;i++)
	{
		b[i][i]=MAXLENGTH;
	}
	for(i=0;i<(n*(n-1))/2;i++)
	{
		scanf("%d%d%d",&c1,&c2,&d);
		b[c1-1][c2-1]=d;
		b[c2-1][c1-1]=d;
	}
	
	for(i=0;i<n;i++){
		close[i]=MAXLENGTH;
	}
	cost=approxTSP(a,b,n);
	printf("最小的旅行费用为：%d\n",cost);
	
}

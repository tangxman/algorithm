/*试用prim算法，输出一个下图的最小生成树。*/

#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100
#define MAXCOST 0x7fffffff
 
int graph[MAX][MAX];
 
int Prim(int graph[][MAX], int n)
{
	int lowcost[MAX];
	int mst[MAX];
	int i, j, min, minid, sum = 0;
	for (i=2;i<=n;i++)
	{
		lowcost[i]=graph[1][i];
		mst[i] = 1;
	}
	mst[1] = 0;
	for (i=2;i<=n;i++)
	{
		min=MAXCOST;
		minid=0;
		for(j=2;j<=n;j++)
		{
			if(lowcost[j]<min&&lowcost[j]!=0)
			{
				min=lowcost[j];
				minid=j;
			}
		}
		printf("%c - %c : %d\n", mst[minid] + 'A' - 1, minid + 'A' - 1, min);
		sum += min;
		lowcost[minid] = 0;
		for(j=2;j<=n;j++)
		{
			if(graph[minid][j]<lowcost[j])
			{
				lowcost[j]=graph[minid][j];
				mst[j]=minid;
			}
		}
	}
	return sum;
}
 
int main()
{
	int i,j,k,m,n;
	int x,y,cost;
	char chx,chy;
	scanf("%d%d", &m, &n);
	getchar();
	for(i=1;i<=m;i++)
	{
		for (j=1;j<=m;j++)
		{
			graph[i][j]=MAXCOST;
		}
	}
	for (k=0;k<n;k++)
	{
		scanf("%c%c%d",&chx,&chy,&cost);
		getchar();
		i=chx-'A'+1;
		j=chy-'A'+1;
		graph[i][j]=cost;
		graph[j][i]=cost;
	}
	cost=Prim(graph,m);
	printf("Total:%d\n",cost);
	return 0;	
} 

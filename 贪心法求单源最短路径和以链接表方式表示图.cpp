/**
求最短路径。用链接表方法定义一个有向图作为输入，计算两个点之间的最短距离。
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 100
#define MAXL 10000

char note[M];
int count=0;

typedef struct ArcList{
	int index;
	int tflen;
	struct ArcList *nextlistnode;
}ArcList;

typedef struct ArcNode{
	char data;
	struct ArcList *arclist;
	struct ArcNode *nextnode;	
}ArcNode;

typedef struct{
	ArcNode *arcGraph;
	int vexnum,arcnum;
}AdjGraph;

int findIndex(char a[M],int n,char p)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==p)
		{
			return i;
		}
	}
}

void CreateChain(AdjGraph *adjGraph,char a[M],char b[M][M],int c[M][M])
{
	int i,j;
	ArcNode *arcNode=NULL;
	ArcNode *nodeHead=NULL;
	ArcNode *nodePre=NULL;
	ArcList *arcList=NULL;
	ArcList *listHead=NULL;
	ArcList *listPre=NULL;
	for(i=0;i<adjGraph->vexnum;i++)
	{
		arcNode=(ArcNode *)malloc(sizeof(ArcNode));
		if(i==0)
		{
			nodeHead=(ArcNode *)malloc(sizeof(ArcNode));
			nodePre=(ArcNode *)malloc(sizeof(ArcNode));
			nodeHead->nextnode=NULL;
			nodePre=nodeHead;
		}
		arcNode->data=a[i];
		for(j=0;j<strlen(b[i]);j++)
		{			
			if(j==0)
			{
				listHead=(ArcList *)malloc(sizeof(ArcList));
				listPre=(ArcList *)malloc(sizeof(ArcList));
				listHead->nextlistnode=NULL;
				listPre=listHead;
			}
			arcList=(ArcList *)malloc(sizeof(ArcList));			
			arcList->index=findIndex(a,adjGraph->vexnum,b[i][j]);
			arcList->tflen=c[i][j];
			listPre->nextlistnode=arcList;
			listPre=arcList;
		}
		listPre->nextlistnode=NULL;
		arcNode->arclist=listHead;
		nodePre->nextnode=arcNode;
		nodePre=arcNode;
	}
	nodePre->nextnode=NULL;
	adjGraph->arcGraph=nodeHead;
}

ArcList *searchNode(ArcNode *arcNode,char p)
{
	
	for(arcNode=arcNode->nextnode;arcNode!=NULL;arcNode=arcNode->nextnode)
	{
		if(p==arcNode->data)
		{
			return arcNode->arclist;
		}
	}

	return NULL;
}

void updateDist(int dist[M],int n,ArcList *arcList,int qDex,char up,int minL)
{
	for(arcList=arcList->nextlistnode;arcList!=NULL;arcList=arcList->nextlistnode)
	{
		if(arcList->tflen+minL<dist[arcList->index])
		{
			if(arcList->index==qDex)
			{
				note[count++]=up;
			}
			dist[arcList->index]=arcList->tflen+minL;		
		}
	}

}

int findMinDist(int dist[M],int n)
{
	int index,temp=MAXL;
	for(int i=0;i<n;i++)
	{
		if(dist[i]!=-1&&dist[i]<temp)
		{
			temp=dist[i];
			index=i;
		}
	}
	return index;
}

void fun(AdjGraph *adjGraph,char a[M],char p,char q)
{
	int i,j,dist[M];
	int minIndex,minle,temp;
//	int	minLen[M]={0};
	int qDex=findIndex(a,adjGraph->vexnum,q);
	ArcNode *head=adjGraph->arcGraph;
	ArcList *arcList=NULL;
	for(i=0;i<adjGraph->vexnum;i++)
	{
		dist[i]=MAXL;
	}
	dist[findIndex(a,adjGraph->vexnum,p)]=-1;
	arcList=searchNode(head,p);
	updateDist(dist,adjGraph->vexnum,arcList,qDex,p,0);
	for(j=1;j<adjGraph->vexnum;j++)
	{		
		minIndex=findMinDist(dist,adjGraph->vexnum);
//		minLen[minIndex]=dist[minIndex];
		temp=dist[minIndex];
		if(minIndex==qDex)
		{
			minle=dist[minIndex];
			break;
		}
		dist[minIndex]=-1;
		arcList=searchNode(head,a[minIndex]);
		updateDist(dist,adjGraph->vexnum,arcList,qDex,a[minIndex],temp);
	}
	printf("%d\n",minle);

}

void main()
{
	int i,j,h,m,n,arcn=0;
	char t,p,q;
	char a[M];
	char b[M][M];
	int c[M][M];
	AdjGraph *adjGraph=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		getchar();
		scanf("%c-(",&a[i]);
		m=0;
		for(j=0;j<2*n;j++)
		{
			t=getchar();
			if(t==',')
			{
				continue;
			}
			else if(t==')')
			{	
				b[i][m]='\0';
				break;
			}else{
				b[i][m]=t;
				m++;
			}
		}
		scanf(",(");
		for(h=0;h<strlen(b[i]);h++)
		{
			if(h==(j+1)/2-1)
			{
				scanf("%d",&c[i][h]);
			}
			else{
				scanf("%d,",&c[i][h]);
			}
		}
		scanf(");");
		arcn+=strlen(b[i]);
	}
	getchar();
	a[i]='\0';
	scanf("%c,%c",&p,&q);
	adjGraph=(AdjGraph *)malloc(sizeof(AdjGraph));
	adjGraph->vexnum=n;
	adjGraph->arcnum=arcn;
	CreateChain(adjGraph,a,b,c);
	fun(adjGraph,a,p,q);
}
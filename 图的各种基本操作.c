/*
用邻接矩阵 或者 邻接表存储结构实现图的基本操作：
InsertVertex(G,v)，InsertArc(G,v,w)，DeleteVertex(G,v)，DeleteArc(G,v,w)
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define Stack_Size 50

typedef struct Arcnode
{
	int data;
	struct Arcnode *next;
}Arcnode,*Arclink;

typedef struct Vnode
{
	int data;
	Arcnode *firstarc;
	int indegree;
}Vnode,Adjlist[MAX+1];

typedef struct ALGraph
{
	Adjlist Vdata;
	int vexnum,arcnum;
}ALGraph;

void CreateGraph(ALGraph *G)
{
	Arcnode *p;
	int e,u,v,i,n;
	printf("请输入图中顶点个数:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		G->Vdata[i].data=i;
		G->Vdata[i].firstarc=NULL;
		G->Vdata[i].indegree=0;
	}
	printf("请输入AOV-网中弧的个数:");
	scanf("%d",&e);
	for(i=1;i<=e;i++)
	{
		printf("请输入一条弧依附的两个的顶点：(u,v)");
		scanf("%d,%d",&u,&v);
		p=(Arclink)malloc(sizeof(Arcnode));
		p->data=v;
		p->next=G->Vdata[u].firstarc;
		G->Vdata[u].firstarc=p;
		G->Vdata[v].indegree++;
		G->vexnum=n;
		G->arcnum=e;
	}
	printf("\nAOV-网的邻接表结构为:\n");
	for(i=1;i<=G->vexnum;i++)
	{
		p=G->Vdata[i].firstarc;
		printf("(%d) %d ",i,G->Vdata[i].data);
		while(p)
		{
			printf("%2d",p->data);
			p=p->next;
		}
		printf("\n");
	}
	return;
}

void InsertVertex(ALGraph *G,int x)
{
	int i;
	Arcnode *p;
	if(G->vexnum>=MAX)
	{
		printf("该图顶点已满！！");
		return;
	}
	G->Vdata[G->vexnum].data=x;
	G->Vdata[G->vexnum].firstarc=NULL;
	G->vexnum++;
	printf("插入后的AOV-网的邻接表结构为:\n");
	for(i=1;i<=G->vexnum;i++)
	{
		p=G->Vdata[i].firstarc;
		printf("(%d) %d ",i,G->Vdata[i].data);
		while(p)
		{
			printf("%2d",p->data);
			p=p->next;
		}
		printf("\n");
	}
}

void InsertArc(ALGraph *G,int x,int y)
{
	int i=-1,j=-1,k;
	Arcnode *s;
	s=(Arcnode *)malloc(sizeof(Arcnode));
	for(k=0;k<G->vexnum;k++)
	{
		if(G->Vdata[k].data==x)
			i=k;
		if(G->Vdata[k].data==y)
			j=k;
	}
	if(i==-1||j==-1)
	{
		printf("input Error");
		return;
	}
	else
	{
		s=G->Vdata[i].firstarc;
		while((s!=NULL)&&(s->data!=j))
			s=s->next;
		if(!s)
		{
			s=(Arcnode *)malloc(sizeof(Arcnode));
			s->data=j;
			s->next=G->Vdata[i].firstarc;
			G->Vdata[i].firstarc=s;
			s=(Arcnode *)malloc(sizeof(Arcnode));
			s->data=i;
			s->next=G->Vdata[j].firstarc;
			G->Vdata[j].firstarc=s;
			G->arcnum++;
		}
	}
}

void DeleteVertex(ALGraph *G,int x)
{
	int i=-1,k,j;
	Arcnode *s,*p,*q;
	for(k=0;k<G->vexnum;k++)
	{
		if(G->Vdata[k].data==x)
			i=k;
		else
		{
			s=G->Vdata[i].firstarc;
			while(s)
			{
				p=G->Vdata[s->data].firstarc;
				if((p)&&(p->data==i))
				{
					G->Vdata[s->data].firstarc=p->next;
					free(p);
				}
				else
				{
					while((p)&&(p->next)&&(p->next->data==i))
						p=p->next;
					q=p->next;
					p->next=q->next;
					free(q);
				}
				q=s;
				s=s->next;
				free(q);
				G->arcnum--;
			}
			for(j=i;j<G->vexnum-1;j++)
			{
				G->Vdata[j].firstarc=G->Vdata[j+1].firstarc;
				G->Vdata[j].data=G->Vdata[j+1].data;
			}
			G->vexnum;
		}
	}
}

void DeleteArc(ALGraph *G,int x,int y)
{
	int i=-1,j=-1,k;
	Arcnode *s,*p;
	s=(Arcnode *)malloc(sizeof(Arcnode));
	p=(Arcnode *)malloc(sizeof(Arcnode));
	for(k=0;k<G->vexnum;k++)
	{
		
		if(G->Vdata[k].data==x)
			i=k;
		if(G->Vdata[k].data==y)
			j=k;

	}
	if(i==-1||j==-1)
	{
		printf("input Error\n");
		return;
	}
	else
	{
		s=G->Vdata[i].firstarc;
		if((s)&&(s->data==j))
		{
			G->Vdata[i].firstarc=s->next;
			free(s);
		}
		else
		{
			while((s)&&(s->next)&&(s->next->data)!=j)
				s=s->next;
		}
		if(!s->next)
		{
			printf("Error\n");
			return;
		}
		else
		{
			p=s->next;
			s=p->next;
			free(p);
		}
		s=G->Vdata[j].firstarc;
		if((s)&&(s->data==i))
		{
			G->Vdata[j].firstarc=s->next;
			free(s);
		}
		else
		{
			while((s)&&(s->next)&&(s->next->data)!=j)
				s=s->next;
			p=s->next;
			s=p->next;
			free(p);
		}
		G->arcnum--;		
	}
}

void screen()
{
	ALGraph *G;
	int i,x,y;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	CreateGraph(G);
	printf("图的插入和删除\n");
	while(1)
	{
		printf("1.插入一个顶点\n");
		printf("2.插入一条边\n");
		printf("3.删除一个顶点\n");
		printf("4.删除一条边\n");
		printf("5.退出\n");
		printf("1--5请选择:");
		scanf("%d",&i);
		getchar();
		switch(i)
		{
		    case 1:printf("请输入你要插入的顶点：");
				   scanf("%d",&x);
				   InsertVertex(G,x);
				   break;
			case 2:printf("请分别输入你要插入边上的两个顶点：");
				   scanf("%d%d",&x,&y);
				   InsertArc(G,x,y);
				   break;
			case 3:printf("请输入你要删除的顶点的值：");
				   scanf("%d",&x);
				   DeleteVertex(G,x); 
				   break;
			case 4:printf("请输入你要删除边的两个顶点的值：");
				   scanf("%d%d",&x,&y);
				   DeleteArc(G,x,y); 
				   break;
			case 5:exit(0);break;
			default:printf("input Error");break;
		}
	}
	return;
}

void main()
{
	screen();
}

				    









	







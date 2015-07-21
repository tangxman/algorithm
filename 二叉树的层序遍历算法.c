/*
应用辅助数据结构队列编写二叉树的层序遍历算法
*/

#include<stdio.h>
#include<stdlib.h>
#define M 50

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *Lchild;
	struct Node *Rchild;
}Bitree;

Bitree *Create()
{
	char ch;
	Bitree *root;	
    scanf("%c",&ch);
	if(ch=='#')
		root=NULL;
	else
	{
		root=(Bitree *)malloc(sizeof(struct Node));
		root->data=ch;
		root->Lchild=Create();
		root->Rchild=Create();
	}
	return root;
}

void main()
{
	Bitree *root,*p;
	Bitree *q[M];
	int front,rear;
	front=rear=-1; 
	rear++;
	p=(Bitree *)malloc(sizeof(struct Node));
	root=NULL;
	printf("请输入二叉树：");
	root=Create();
	if(root==NULL)
		return;       
    q[rear]=root;
	printf("该树按层次遍历为：");
    while(front!=rear)
    {
        front=(front+1)%M;
        p=q[front];
        printf("%c ",p->data);
        if(p->Lchild!=NULL)
        {
            rear=(rear+1)%M;
            q[rear]=p->Lchild;
        }   
        if(p->Rchild!=NULL)
        {
            rear=(rear+1)%M;
            q[rear]=p->Rchild;
        }     
    }  
	printf("\n");
}




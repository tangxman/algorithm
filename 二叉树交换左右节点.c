/*
编写一个程序，建立二叉树，
并交换二叉树每个节点的左右儿子节点
*/
#include<stdio.h>
#include<stdlib.h>
#define M 100

int i=0;

typedef char Datatype;

typedef struct Node
{
	Datatype data;
	struct Node *Lchild;
	struct Node *Rchild;
}Bitree;

Bitree *Create()
{
	Bitree *root;
	char ch;
	scanf("%c",&ch);
	if(ch=='*')
		root=NULL;
	else
	{
        root=(Bitree *)malloc(sizeof(struct Node));
		root->data=ch;
		root->Lchild=Create();
		root->Rchild=Create();
	}
	return (root);
}

void Preorder(Bitree *root)
{
	if(root!=NULL)
	{
		printf("%2c",root->data);
        Preorder(root->Lchild);
		Preorder(root->Rchild);
	}
}

Bitree *change(Bitree *root)
{
	char temp[M],str[M];
	if(root!=NULL&&root->Lchild!=NULL&&root->Rchild!=NULL)
	{
	      if(root->Lchild!=NULL&&root->Rchild!=NULL)
		  {
		       temp[i]=root->Rchild->data;
		       str[i]=root->Lchild->data;
		       root->Lchild->data=temp[i];
		       root->Rchild->data=str[i];
		       i++;
		  }
	      else if(root->Lchild!=NULL&&root->Rchild==NULL)
		  {
			  root->Rchild=(Bitree *)malloc(sizeof(struct Node));
			  temp[i]=root->Lchild->data;
			  root->Lchild=NULL;
			  root->Rchild->data=temp[i];
			  i++;
		  }
		  else 
		  {
			  root->Lchild=(Bitree *)malloc(sizeof(struct Node));
			  str[i]=root->Rchild->data;
			  root->Rchild=NULL;
			  root->Lchild->data=str[i];
			  i++;
		  }	
		  change(root->Lchild);
		  change(root->Rchild);
	}
	return root;
}


int main()
{
	Bitree *root;
	root=NULL;
	root=Create();
	printf("该二叉树先序遍历得到序列如下：\n");
	Preorder(root);
	printf("\n");	
	change(root);
	printf("左右子节点交换得到后的序列为：\n");
	Preorder(root);
	printf("\n");
}



/*
判断树是否完全二叉树的算法
*/

#include<stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
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

/*判断是否完全二叉树*/
int is_sheer(Bitree *root)
{
       Bitree *queue[M],*p;            /*定义队列*/
       int rear=0,front=0;
       if(root!=NULL)
       {
           queue[rear]=root;
           rear=(rear+1)%M;
       }       
       while(rear!=front)                   /*此while的作用是在根节点在队内的初始情况下开始*/
	   {                                    /*按层次遍历二叉树只遍历左右子树都有的节点 while结束时 p指向第一个例外节点*/       
          p=queue[front];
          front=(front+1)%M;
          if((rear+1)%M!=front&&p->Lchild!=NULL&&p->Rchild!=NULL)              /*当队不满，*/
          {
            queue[rear]=p->Lchild;
            rear=(rear+1)%M;
            queue[rear]=p->Rchild;
            rear=(rear+1)%M;
           }
           else break;
	   }                                                                    /*经前面的while，p肯定指向第一个没有双子的节点，此时又分四种情况*/
        if(p->Lchild==NULL&&p->Rchild!=NULL)                                 /*第一种:有右无左 肯定不是完全二叉树*/
			return FALSE;                                              
        else if(p->Lchild!=NULL&&(p->Lchild->Lchild!=NULL||p->Lchild->Rchild!=NULL))      /*第二种:有左无右但左子树还有子树 排除*/
        return FALSE;                      
        else                                                         /*第三种:有左无右 左也无子*/
        {
              while(rear!=front)                                     /*但在继续按层次遍历过程中，发现后来的某个节点有子树,排除*/
              {
                 p=queue[front];
                 front=(front+1)%20;
                 if(p->Lchild!=NULL||p->Rchild!=NULL) 
					 return FALSE;
              }
         }
         return TRUE;
}                                                           

void main()
{
      
	  Bitree *root;
	  printf("请创建二叉树：");
      root=Create();
	  if(is_sheer(root)==1)
      printf("这个数是完全二叉树！");
	  else
	  printf("这个树不是完全二叉树！");
      printf("\n");
}


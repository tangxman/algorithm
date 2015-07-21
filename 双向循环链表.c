/*
编写一个程序，建立双向循环链表，并实现它的插入操作、删除操作
*/
#include<stdio.h>
#include<stdlib.h>

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *prior,*next;
}Dnode;

Dnode *Create()
{
	Dnode *head,*p=NULL,*t;
	char ch;
	int flag=1;
	head=(Dnode *)malloc(sizeof(struct Node));
	if(head)
	{
	    head->next=head;
		head->prior=head;	    
	}
	t=head;
	while(flag)
	{
	    ch=getchar();	
	    if(ch!='\n')
		{
			p=(Dnode *)malloc(sizeof(struct Node));
	        p->data=ch;
			p->next=head->next;
			p->prior=head;
			head->next->prior=p;
			head->next=p;	
		}
		else flag=0;
	}
	printf("建立的双向循环链表为:");
	while(head->next!=t)
	{	
		head=head->next;	
		printf("%c",head->data);		
	}
	printf("\n");
	return head;
}
	
void DlinkIns(Dnode *head)
{
	int j=0,i;
	char ch;
	Dnode *s,*q=NULL,*t;
	head=head->next;
	t=head;
	q=(Dnode *)malloc(sizeof(struct Node));
	q=head;	   
	printf("请输入要插入的位置：");
	scanf("%d",&i);
	getchar();
	printf("请输入要插入的元素：");
	scanf("%c",&ch);
	while(j<i&&q->next!=NULL)
	{
		q=q->next;
		j++;
	}
	s=(Dnode *)malloc(sizeof(struct Node));
	if(s)
	{	   
			s->data=ch;
			s->prior=q->prior;
			q->prior->next=s;
			s->next=q;
			q->prior=s;			
	}	
	printf("插入后的链表为:");
	while(head->next!=t)
	{	
		head=head->next;	
		printf("%c",head->data);				
	}
	printf("\n");
}

int DlinkDel(Dnode *head)
{
	int j=0,i;	
    Dnode *q=NULL,*t;
    head=head->next;
	q=(Dnode *)malloc(sizeof (struct Node));
	q=head;
	t=head;
	printf("请输入要删除的位置：");
	scanf("%d",&i);	
	getchar();
	while(j<i&&q->next!=t)
	{
		q=q->next;
		j++;
	}
	printf("删除的元素是%c\n",q->data);
    if(q->next!=NULL)
	{
		q->next->prior=q->prior;
		q->prior->next=q->next;	
		free(q);
		printf("删除成功！\n");	
	}
	else 
	{
		printf("输入错误！");
	    return 0;
	}
     printf("删除后的链表为：");
     while(head->next!=t)
	 {	 		 
		 head=head->next;
		 printf("%c",head->data);				 
	 }
	 printf("\n");
	 return 0;
}
void screen()
{
	int a;	
	Dnode *head;
	printf("双向循环链表演示程序！！\n");
	while(1)
	{
	printf("1.创建");
    printf("2.插入");
	printf("3.删除");
	printf("4.退出\n");
	printf("请选择:");
	scanf("%d",&a);
    getchar();
	switch(a)
	{
	    case 1:printf("please input:");
			   head=Create();break;
		case 2:DlinkIns(head);break;
		case 3:DlinkDel(head);break;
        case 4:exit(0);break;
		default:printf("输入错误！！");
	}
	}
}


void main()
{	
    Dnode *head;
	head=NULL;
	screen();
}


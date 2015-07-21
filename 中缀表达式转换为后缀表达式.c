/*
中缀表达式转换为后缀表达式
步骤如下：
开始扫描中缀表达式；
如果为数字时，加入后缀表达式；
如果为运算符：
a. 若为 '('，入栈；
b. 若为 ')'，则依次把栈中的的运算符加入后缀表达式中，直到出现'('，从栈中删除'(' ；
c. 若为 除括号外的其他运算符， 当其优先级高于栈顶运算符时，直接入栈。否则从栈顶开始，
依次弹出比当前处理的运算符优先级高和优先级相等的运算符，直到一个比它优先级低的或者遇到了一个左括号为止。
当扫描的中缀表达式结束时，栈中的的所有运算符出栈。
*/

#include<stdio.h>
#include<string.h> 
#define Stack_Size 50
#define M 50

typedef struct Node
{
	char elem[Stack_Size];
	int top;
}SeqStack;

void InitStack(SeqStack *S)
{
	S->top=-1;
}

int Push(SeqStack *S,char x)
{
	if(S->top==Stack_Size-1)
		return 0;
	S->top++;
	S->elem[S->top]=x;
	return 1;
}

char *Pop(SeqStack *S)
{
	char *x;
	x=(SeqStack *)malloc(sizeof (struct Node));
	if(S->top==-1)
		return 0;
	else
	{
		*x=S->elem[S->top];
		S->top--;
		return *x;
	}
	return 0;
}

char *GetTop(SeqStack *S)
{
	char *x;
	x=(SeqStack *)malloc(sizeof (struct Node));
	if(S->top==-1)
		return -1;
	else 
	{
		*x=S->elem[S->top];
		return *x;
	}
}

int priority(char op)
{
    if(op=='+'||op=='-')
        return 1;
    else if(op=='/'||op=='%')
        return 2;
	else if(op=='*')
		return 3;
    else if(op=='^')
        return 4;
    else
        return 0;
}

int compare(char ch1,char ch2)
{
	if(priority(ch1)>priority(ch2)||priority(ch1)==priority(ch2))
		return 2;
	else return 1;
}

void main()
{
	int i=0,j=0,k=0,m=0;
	char str[M],hou[M],ch='@';
	SeqStack *OPTR;
	InitStack(&OPTR);
	printf("请输入要转换的中缀表达式(以#结束)：");
	for(i=0;i<M;i++)
	{
	     scanf("%c",&str[i]);
		 if(str[i]=='#')
			 break;
	}
	while(str[k]!='#')
	{
		if(str[k]>='0'&&str[k]<='9')  //如果是数字或字母时进后缀表达式hou[M]
		{
			hou[m]=str[k];
			m++;
		}
		else if(str[k]>='a'&&str[k]<='z')
		{
			hou[m]=str[k];
			m++;
		}
		else if(str[k]>='A'&&str[k]<='Z')
		{
			hou[m]=str[k];
			m++;
		}
		else if(str[k]=='(')                      //如果是左括号直接进操作符栈OPTR
			Push(&OPTR,str[k]);
		else if(str[k]==')')                      //如果是右括号，将与第一个左括号之间的操作符全部压入后缀表达式中，且左括号出栈
		{
			while(1)
			{
				ch=Pop(&OPTR);
				if(ch=='(')
					break;
				hou[m]=ch;
				m++;
			}
		}
		else if(GetTop(&OPTR)==-1)                //如果是运算符,但是栈顶元素为空时		
			Push(&OPTR,str[k]);
		else if(GetTop(&OPTR)=='(')				  //如果是运算符，但是栈顶元素为'('时
			Push(&OPTR,str[k]);
		else
			    switch(compare(str[k],GetTop(&OPTR)))
		{
			    case 2:Push(&OPTR,str[k]);        //如果优先级比栈顶运算符优先级高  直接入栈
				       break;				     
			    case 1:while(compare(GetTop(&OPTR),str[k])!=1&&GetTop(&OPTR)!='(')
					   {
									hou[m]=Pop(&OPTR);             // 若为不是最高级的运算符，则将从栈顶到第一个优先级不大于它的运算符或 '('之间的运算符加入数栈中，该运算符再入栈； 									
									m++;
					   }
					   if(GetTop(&OPTR)=='(')
						   Pop(&OPTR);
					   Push(&OPTR,str[k]);
					   break;
		}
		k++;
	}
	while(GetTop(&OPTR)!=-1)
	{
		hou[m]=Pop(&OPTR);
		m++;
	}
	printf("将该中缀表达式转换为后缀表达式为：");
	for(i=0;i<m;i++)                                              //输出该后缀表达式
		printf("%c ",hou[i]);
	printf("\n");
}



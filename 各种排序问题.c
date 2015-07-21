/*
编写一个C语言程序，实现希尔排序；快速排序；堆排序；归并排序。测设数据自行设定
*/

#include<stdio.h>
#include<stdlib.h>
#define M 30
#define TRUE 1
#define FALSE 0

typedef int KeyType;

typedef struct
{
	KeyType key;
}RecordType;


void shellinsert(RecordType r[],int length,int delta)
{
	int i,j;
	for(i=1+delta;i<=length;i++)
	{
		if(r[i].key<r[i-delta].key)
		{
			r[0]=r[i];
			for(j=i-delta;j>0&&r[0].key<r[j].key;j-=delta)
				r[j+delta]=r[j];
			r[j+delta]=r[0];
		}
	}
}	

/*--------------------希尔排序---------------------------*/
void shellsort(RecordType r[],int length,int delta[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		shellinsert(r,length,delta[i]);	
	printf("希尔排序后的顺序为:");
	for(i=1;i<=length;i++)
	printf("%d ",r[i].key);
	printf("\n");
}

int Qkpass(RecordType r[],int left,int right)
{
	int x,low,high;
	x=r[left].key;
	low=left;
	high=right;
	while(low<high)
	{
		while(low<high&&r[high].key>=x)
			high--;
		if(low<high)
		{
			r[low]=r[high];
			low++;
		}
		while(low<high&&r[low].key<x)
			low++;
		if(low<high)
		{
			r[high]=r[low];
			high--;
		}
	}
	r[low].key=x;
	return low;
}

/*------------------快速排序-----------------------*/
void Qksort(RecordType r[],int low,int high)
{
	int pos;
	if(low<high)
	{
		pos=Qkpass(r,low,high);
		Qksort(r,low,pos-1);
		Qksort(r,pos+1,high);
	}
}

void sift(RecordType r[],int k,int m)
{
	int t,x,i,j,finished;
	t=r[k].key;
	x=r[k].key;
	i=k;
	j=2*i;
	finished=FALSE;
	while(j<=m&&!finished)
	{
		if(j<m&&r[j].key<r[j+1].key)
			j=j+1;
		if(x>=r[j].key)
			finished=TRUE;
		else
		{
			r[i]=r[j];
			i=j;
			j=2*i;
		}
	}
	r[i].key=t;
}

void crt_heap(RecordType r[],int length)
{
	int n,i;
	n=length;
	for(i=n/2;i>=1;i--)
		sift(r,i,n);
}

/*-----------------堆排序----------------------*/
void Heapsort(RecordType r[],int length)
{
	int n,b,i;
	crt_heap(r,length);
	n=length;
	for(i=n;i>=2;i--)
	{
		b=r[1].key;
		r[1]=r[i];
		r[i].key=b;
		sift(r,1,i-1);
	}
	printf("堆排序后的顺序为：");
	for(i=1;i<=length;i++)
	printf("%d ",r[i].key);
	printf("\n");
}

/*-----------------归并排序----------------------*/
void Merge(RecordType r1[],int low,int mid,int high,RecordType r2[])
{
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	while((i<=mid)&&(j<=high))
	{
		if(r1[i].key<=r1[j].key)
		{
			r2[k]=r1[i];
			i++;
		}
		else
		{
			r2[k]=r1[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		r2[k]=r1[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		r2[k]=r1[j];
		k++;
		j++;
	}
	printf("归并排序后的顺序为：");
	for(i=1;i<=high;i++)
	printf("%d ",r2[i].key);
	printf("\n");
}

void main()
{	
	int k,i,j=4;
	int delta[]={4,3,2,1};
	RecordType str[50];
	RecordType ch[50];
	printf("请输入要排序的元素个数:");
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		printf("输入的第%d个数是:",i);
		scanf("%d",&str[i].key);
	}
	printf("初始顺序为:");
    for(i=1;i<=k;i++)		
	    printf("%d ",str[i].key);
	printf("\n");
	shellsort(str,k,delta,j);
	Qksort(str,1,k);
	printf("快速排序后的顺序为：");
	for(i=1;i<=k;i++)
	printf("%d ",str[i].key);
	printf("\n");
	Heapsort(str,k);
	Merge(str,1,(k+1)/2,k,ch);
}







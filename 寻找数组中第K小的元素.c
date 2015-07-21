/**
有一个n个元素的数组，设计复杂性为O(n)的算法，寻找其中大小排第k个元素。k<=n.
*/

#include<stdio.h>
#include<stdlib.h>
#define N 1000

int random(int p,int r)
{
	int k;
	k=(int)(rand()%(r-p+1)+p);
	return k;

}

void swap(int *a,int *b){
	
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int part(int a[],int p,int r)
{
	int i=p,j=r+1;
	int x=a[p];
	while(1)
	{	
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j)
			break;
		swap(&a[i],&a[j]);
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}

int randpart(int a[],int p,int r)
{
	int i=random(p,r);
	swap(&a[i],&a[p]);
	return part(a,p,r);
}

int select(int a[],int p,int r,int k)
{
	int i,j;
	if(p==r)
		return a[p];
	i= randpart(a,p,r);
	j=i-p+1;
	if(k<=j)
		return select(a,p,i,k);
	else 
		return select(a,i+1,r,k-j);
}


void main(){

	int a[N];
	int n,k,i,result;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	result=select(a,0,n-1,k);
	printf("%d\n",result);

}
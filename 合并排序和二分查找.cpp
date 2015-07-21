#include<iostream>
using namespace std;

int b[7];

void Merge(int a[],int b[],int left,int middle,int right)
{
	int i=left,j=middle+1,k=left;
	while(i<=middle&&j<=right)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	if(i>middle)
	{
		for(i=j;j<=right;j++)
		{
			b[k++]=a[i];
		}
	}
	else
	{
		for(j=i;j<=middle;j++)
		{
			b[k++]=a[j];
		}
	}
}

void Copy(int a[],int b[],int left,int right)
{
	for(int i=left;i<=right;i++)
	{
		a[i]=b[i];
	}
}

void mergeSort(int a[],int left,int right)
{
	if(left<right)
	{
		int middle=(left+right)/2;
		mergeSort(a,left,middle);
		mergeSort(a,middle+1,right);
		Merge(a,b,left,middle,right);
		Copy(a,b,left,right);
	}
}

int binarySearch(int a[],int x,int n)
{
	int left=0,right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(x==a[middle])
		{
			return middle;
		}
		else if(x<a[middle])
		{
			right=middle-1;

		}else{
			left=middle+1;
		}
	}
	return -1;
}


void main()
{
	int a[]={2,5,8,4,6,9,1};
	int index;
	mergeSort(a,0,6);
	for(int i=0;i<7;i++)
		cout<<a[i]<<",";
	cout<<endl;
	index=binarySearch(a,6,7);
	if(index<0)
		cout<<"没有找到该元素"<<endl;
	else
		cout<<"这是第"<<index+1<<"个元素";
}
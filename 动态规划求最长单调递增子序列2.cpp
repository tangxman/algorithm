/*设计一个O(n2)时间的算法，找出由n个数组成的序列的最长单调递增子序列。*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100

void fun(int n);

vector< int > a,b;

void main()
{
	int i,n,temp;
	printf("input n:");
	scanf("%d",&n);
	printf("input the array.\n");
	for(i=0;i<n&&cin>>temp;i++)
		a.push_back(temp);
	b=a;
	sort(b.begin(),b.end());
	fun(n);

}

void fun(int n)
{
	int m[N][N],flag[N];
	if(a[0]!=b[0])
		m[0][0]=0;
	else
		m[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0&&j==0)
			{
				continue;
			}
			if(a[i]==b[j])
			{
				if(i==0)
					m[i][j]=m[0][j-1]+1;
				else if(j==0)
					m[i][j]=m[i-1][0]+1;
				else
				    m[i][j]=m[i-1][j-1]+1;
			}
			else
			{
				if(i==0)
					m[i][j]=m[i][j-1];
				else if(j==0)
					m[i][j]=m[i-1][j];
				else
					m[i][j]=(m[i-1][j]>m[i][j-1]?m[i-1][j]:m[i][j-1]);
			}
		}
	}
	for(int k=n-1;k>=0;k--)
	{
		if(k==0&&m[0][0]!=0)
			flag[k]=1;
		else if(m[k][k]>m[k-1][k-1])
			flag[k]=1;
		else
			flag[k]=0;
	}
	cout<<"len="<<m[n-1][n-1]<<endl;
	cout<<"the number are:";
	for(int h=0;h<n;h++)
	{
		if(flag[h])
		{
			cout<<a[h]<<" ";
		}
	}
	cout<<endl;
		
}


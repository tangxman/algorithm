/*试用prim算法，输出一个下图的最小生成树。*/
#include<iostream>
#include<vector>
using namespace std;
#define N 100
#define MAXSIZE 1000

vector<int> close(N,MAXSIZE);
int b[N];
int c[N];
int j=0,h=1;

void fun(int a[N][N],int m);


void main()
{
	int m,n,x,y;
	float len;
	int a[N][N];
	cout<<"input m and n:";
	cin>>m>>n;
	for(int h=1;h<=m;h++)
		b[h]=h;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=MAXSIZE;
		}
	}
	cout<<"input the graph"<<endl;
	for(int k=0;k<n;k++)
	{
		cin>>x>>y>>len;
		a[x][y]=len;
		a[y][x]=len;
	}  
	fun(a,m);
}

void fun(int a[N][N],int m)
{
	
	int n=1;
	while(n<=m)
	{
		c[j]=b[h];
		close[h]=-1;
		for(int i=1;i<=m;i++)
	    {							
			if(a[h][i]<close[i])
			{
				close[i]=a[h][i];
			}
		}
		int min=MAXSIZE;
		for(int k=1;k<=m;k++)
		{
			if(close[k]>0&&close[k]<min)
			{
				min=close[k];
				h=k;
			}			
		}
		j++;
		n++;		
	}
	cout<<"The result is:";
	for(n=0;n<m;n++)
		cout<<c[n]<<" ";
	cout<<endl;
}
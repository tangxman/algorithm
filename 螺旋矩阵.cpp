#include <iostream>
#include<iomanip>
using namespace std;
#define M 100

int num=1;

void prin(int a[M][M],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			cout<<setw(4)<<a[i][j];
		}
		cout<<endl;
	}
}

void fun(int a[M][M],int m,int n)
{
	int i=m,j=m; 
	if(num>(n*(n+1))/2)
		return;
/*	do
	{		                       //∫·œÚ∏≥÷µ
		a[m][i]=num++;
		i++;
	}while(i<=n-2-2*m);
*/	for(i=m;i<=n-2-2*m;i++)
	{
		a[m][i]=num++;
	}

	do{
		a[j][n-1-m-j]=num++;
		j++;
	}while(j<=n-2-2*m);

/*	for(int j=m;j<=n-2-2*m;j++)
	{ 
		a[j][n-1-m-j]=num++;
	}
*/
	for(int k=i;k>=m+1;k--)
	{
		a[k][m]=num++;
	}
	fun(a,m+1,n);
}

void main()
{
	int a[M][M];
	int n;
	cout<<"input n:";
	cin>>n;
	fun(a,0,n);
	prin(a,n);
}
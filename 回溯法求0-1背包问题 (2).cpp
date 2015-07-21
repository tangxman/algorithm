#include<iostream>
#include<vector>
using namespace std;

int best=0;
vector<int > flag(5,0),temp(5,0);

void fun(vector<int > w,vector<int > v,int n,int i,int c,int p);

void main()
{
	int a,b,n,c;
	vector<int > w,v;
	cout<<"input n,c:";
	cin>>n>>c;
	cout<<"w and v:"<<endl;
	for(int i=0;i<n&&cin>>a&&cin>>b;i++)
	{
		w.push_back(a);
		v.push_back(b);
	}
	fun(w,v,n,0,c,0);
	cout<<"best="<<best<<endl;
	cout<<"the number are:";
	for(int j=0;j<n;j++)
	{
		if(temp[j])
			cout<<w[j]<<" ";
	}
}

void fun(vector<int > w,vector<int > v,int n,int i,int c,int p)
{
	if(i==n)
	{
		if(p>best)
		{
			for(int j=0;j<n;j++)
				temp[j]=flag[j];
			best=p;
		}
	}
	else
	{
		if(w[i]<=c)
		{
			flag[i]=1;
			fun(w,v,n,i+1,c-w[i],p+v[i]);
		}
			flag[i]=0;
			fun(w,v,n,i+1,c,p);
		
	}
}
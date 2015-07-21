/*	设有n个顾客等待一项服务，顾客i需要服务的时间为ti 
应如何安排顾客的服务次序才能使平均等待时间达到最小？
平均等待时间是n个顾客的等待时间之和除以n. 设计算法，
并证明算法的正确性。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,i ;

double fun(vector<int> x)
{ 
	int n=x.size(); 
	sort(x.begin(),x.end());
	for (i=1;i<n;i++)
		x[i]+=x[i-1]; 
	double t=0;
	for (i=0;i<n;i++) 
		t+=x[i] ;
	t/=n;
	return t;
}

int main()
{  
	int a[1000];    
	cin>>n ; 
	vector<int> x; 
	for(i=0;i<n;i++ )  
	{  
		cin>>a[i];   
		x.push_back(a[i]);
	}
	printf("%.2f\n",fun(x)); 
	return 0;
}
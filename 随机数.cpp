#include<iostream>
#include<stdlib.h>
#include<windows.h>

double AverageRandom(double min,double max)
{
	int minInteger=(int)(min*100);
	int maxInteger=(int)(max*100);
	int randInteger=rand()*rand();
	int diffInteger=maxInteger-minInteger;
	int result=randInteger%diffInteger+minInteger;
	return result/100.0;//产生两位精度的随机数

}

void main()
{
	srand(GetTickCount());
	int k=0;
	for(int i=1;i<=50;i++)
	{
		cout<<AverageRandom(1,10)<<" ";
		k++;
		if(k==5)
		{
			cout<<endl;
			k=0;
		}
	}
	cout<<endl;
}
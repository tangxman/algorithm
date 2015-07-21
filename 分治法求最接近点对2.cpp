/*4	用分治法输出一个一维数组中的n个不同实数间距离最小的两个实数。
输入：实数数组X, 实数个数n, 输出: 距离最小的两个实数.*/
#include<stdio.h>
#include<math.h>
#define N 1000
#define MAXNUM 10000

struct dis Cpair(int a[],int p,int q);

struct dis
{
	int d;
	int x;
	int y;
};
struct dis minlen;

void main()
{
	int a[]={12,25,65,46,34,19,29,91,73,59};
    minlen=Cpair(a,0,9);
	printf("最小距离是：%d\n",minlen.d);
	printf("最近的两个数是：%d %d\n",minlen.x,minlen.y);
}

struct dis Cpair(int a[],int p,int q)
{
	int j=0,k=0,min=100000,max=0;
	int b[N],c[N];
	struct dis tom,man,cat;
	if(p==q)
	{
		tom.x=a[p];
		tom.y=a[q];
		tom.d=MAXNUM;
		return tom;
	}
	if(q-p==1)
	{
		tom.x=a[p];
		tom.y=a[q];
		tom.d=abs(a[q]-a[p]);
		return tom;
	}
	double temp=(a[p]+a[q])/2.0;
	for(int i=0;i<=q;i++)
	{
		if(a[i]<temp)
		{
			b[j]=a[i];
			if(b[j]>max)
				max=b[j];
			j++;
		}
		else
		{
			c[k]=a[i];
			if(c[k]<min)
				min=c[k];
			k++;
		}
	}
	man=Cpair(b,0,j-1);
	cat=Cpair(c,0,k-1);
	minlen.x=max;
	minlen.y=min;
	minlen.d=min-max;
	if(man.d<cat.d)
	{
		tom=man;
	}
	else
	{
		tom=cat;
	}
	if(tom.d<minlen.d)
	{
		minlen=tom;
	}
	return minlen;
}

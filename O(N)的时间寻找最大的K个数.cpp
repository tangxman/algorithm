#include <iostream>
using namespace std;

//快速排序的划分函数
int partition(int a[],int l,int r)
{
    int i,j,x,temp;
    i = l;
    j = r+1;
    x = a[l];
    //将>=x的元素换到左边区域
    //将<=x的元素换到右边区域
    while (1)
    {
        while(a[++i] > x);
        while(a[--j] < x);
        if(i >= j) break;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[l] = a[j];
    a[j] = x;
    return j;
}

//随机划分函数
int random_partition(int a[],int l,int r)
{
    int i = l+rand()%(r-l+1);//生产随机数
    int temp = a[i];
    a[i] = a[l];
    a[l] = temp;
    return partition(a,l,r);//调用划分函数
}

//线性寻找第k大的数
int random_select(int a[],int l,int r,int k)
{
    int i,j;
    if (l == r) //递归结束
    {
        return a[l];
    }
    i = random_partition(a,l,r);//划分
    j = i-l+1;
    if(k == j) //递归结束，找到第K大的数
        return a[i];
    if(k < j)
    {
        return random_select(a,l,i-1,k);//递归调用，在前面部分查找第K大的数
    }
    else
        return random_select(a,i+1,r,k-j);//递归调用，在后面部分查找第K大的数
}

int main()
{
    int a[]={1,2,3,4,6,6,7,8,10,10};

    cout<<random_select(a,0,9,1)<<endl;
    cout<<random_select(a,0,9,5)<<endl;
    return 0;
}
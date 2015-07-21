/*
对4个数字全排列有4!=24种排列。

4个数字共需要3个运算符，同一个运算符可以重复出现，则有4x4x4=64种情况。

对于4个数字而言，共有以下5中加括号的方式：

(A(B(CD)))，(A((BC)D))，((AB)(CD))，((A(BC))D)，(((AB)C)D)。

所以遍历的表达式最多有24*64*5=7680种。即使采用逆波兰表达式，总数不变。

/*24点游戏算法，穷举法： 
f(Array)
{
   if(Array.Length<2)
   {
     if(得到的最终结果是24) 输出表达式
     else 输出无符合要求的表达式
   }
   foreach(从数组中取任意两个数的组合)
   {
      foreach(运算符(+ - * /))
      {
         1、计算该组合在此运算符下的结果
         2、将该组合中的两个数从原数组中删除，并将步骤1的结果放入数组
         3、对新数组递归调用f。如果找到一个表达式就返回
         4、将步骤1的计算结果移除，并将该组合中的两个数重新放回数组中对应的位置
      } 
   }
}     
*/
*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const double Threshold=1E-6;
const int CardsNumber=4;
const int ResultValue=24;
double number[CardsNumber];
string result[CardsNumber];

bool PointsGame(int n)
{
    if(n==1)
    {
        //浮点数的比较使用差值与阈值的比较
        if(fabs(number[0]-ResultValue)<Threshold)
        {
            cout<<result[0]<<endl;
            return true;
        }
        else return false;
    }
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n; ++j)
        {
            double a,b;
            string expa,expb;

            a=number[i];
            b=number[j];
            number[j]=number[n-1];

            expa=result[i];
            expb=result[j];
            result[j]=result[n-1];

            result[i]='('+expa+'+'+expb+')';
            number[i]=a+b;
            if(PointsGame(n-1)) return true;

            result[i]='('+expa+'-'+expb+')';
            number[i]=a-b;
            if(PointsGame(n-1)) return true;

            result[i]='('+expb+'-'+expa+')';
            number[i]=b-a;
            if(PointsGame(n-1)) return true;

            result[i]='('+expa+'*'+expb+')';
            number[i]=a*b;
            if(PointsGame(n-1)) return true;

            if(b!=0)
            {
                result[i]='('+expa+'/'+expb+')';
                number[i]=a/b;
                if(PointsGame(n-1)) return true;
            }
            if(a!=0)
            {
                result[i]='('+expb+'/'+expa+')';
                number[i]=b/a;
                if(PointsGame(n-1)) return true;
            }

            number[i]=a;
            number[j]=b;
            result[i]=expa;
            result[j]=expb;
        }
        return false;
}

int main()
{
    int x;
    for(int i=0; i<4; ++i)
    {
       char buffer[20];
       cout<<"the "<<i+1<<"th number:";
       cin>>x;
       number[i]=x;
       itoa(x,buffer,10);
       result[i]=buffer;
    }
    if(PointsGame(CardsNumber))
      cout<<"Success."<<endl;
    else cout<<"Fail."<<endl;

    return 0;
}
/*
正整数划分问题 
将一个正整数n表示成一系列正整数的和，如：
N=n1+n2+…+nk （其中n1≥n2≥…≥nk≥1， k≥1)
正整数n的一个这种表示成为正整数n的一个划分。
现在给出一个正整数n（80≥n≥1），求n的不同划分一共有多少种

*/

#include <stdio.h>

int huafen(int n, int m)
{
      if(n < 1 || m < 1) 
		  return 0;
      if(n == 1 || m == 1) 
		  return 1;
      if(n < m) 
		  return huafen(n, n);
      if(n == m) 
		  return (huafen(n, m - 1) + 1);
      if(n > m) 
		  return (huafen(n, m - 1) + huafen((n - m), m));
}

int main()
{
	int m;
	printf("请输入要划分的数:");
	scanf("%d",&m);
    printf("%d的划分数: %d\n", m,huafen(m, m));
    return 0;
}



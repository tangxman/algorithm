/*
求7的34次方的值 (注意整型表示长度范围)
*/
#include<stdio.h>
#define M 50

void main()
{ 
	static int a[M];
    int i,j,k=0,c=0;
    a[0]=1;
    for(i=1;i<=34;i++)
    { 
		for (j=0;j<=k;j++)
		{ 
			a[j]=a[j]*7+c;
            c=a[j]/10;
            a[j]%=10;
		}
        if(c) 
		{
			k++;
			a[k]=c;
			c=0;
		}
    }
	i=k;
    for(k=i;k>=0;k--) 
	   printf("%d",a[k]);
  printf("\n");
}

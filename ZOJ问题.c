/*
ZOJ，读入一个字符串，字符串中包含ZOJ三个字符，个数不一定相等，
按ZOJ的顺序输出，当某个字符用完时，剩下的仍然安装ZOJ的顺序输出。当读入的字符串为E时，结束。
Input：
ZZOOOJJJ
ZZZZOOOOOJJJ
E
Output:
ZOJZOJOJ
ZOJZOJZOJZOO

*/
#include<stdio.h>
#define M 100

int main()
{
	int countZ[M]={0};
	int countO[M]={0};
	int countJ[M]={0};
	int i=0,j,h,k,totalcount;
	int b[M];
	char a[M][M];
	printf("请输入字符串：\n");
	while(i<M)
	{
		for(j=0;j<M;j++)
		{
			scanf("%c",&a[i][j]);
			if(a[i][j]=='\n')
			{
				b[i]=j;
				break;
			}
			else if(a[i][j]=='E')
				goto loop;
		    else if(a[i][j]=='Z')
			    countZ[i]++;
			else if(a[i][j]=='O')
			    countO[i]++;
			else 
				countJ[i]++;
		}
		i++;
	}
    loop:h=i;
	printf("排好的序列依次为：\n");
	for(i=0;i<h;i++)
	{		
	         totalcount=countZ[i]+countO[i]+countJ[i];
	         for(k=0;k<totalcount;k++)
			 {
		          if(countZ[i]>0)
				  {
			           printf("Z");
		               countZ[i]--;
				  }
		          if(countO[i]>0)
				  {
			           printf("O");
		               countO[i]--;
				  }
		          if(countJ[i]>0)
				  {	
					   printf("J");
		               countJ[i]--;
				  }   
			 }
			 printf("\n");		
	}
	return 0;
}
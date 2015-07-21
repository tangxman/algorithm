/*ababc的返回ab*/
#include<stdlib.h>
#include<stdio.h>

void main()
{
	int count=0,k=0,x=1,i;//记录连续出现的字符串是长度
	char *a, *s,*star,*snew,*r,*p=0;
	a=(char*)malloc(sizeof(char)*80);
	s=(char*)malloc(sizeof(char)*80);
	while(x)
   {
	
	puts("请输入字符串!\n");
	gets(s);
	star=snew=s;
	while(*s)
	{
		
		while(*snew!='\0')
		{
			
			if(*star==*(++snew))
			{
				
				r=snew;//记下snew的位置
				while(((*star)==(*snew))&&(star!=r))
				{
					star++;
					snew++;
					count++;}
	            
				if((count>k)&&(star==r))
				{
					k=count;//记下字符串的长度
					p=r;//记下字符串的返回地址
					
				}
				
				count=0;
				star=s;
			    snew=r;
			}
		}
		s++;
		star=snew=s;
	}
	
	if(p)
	{
		for(i=0;i<k;i++)
			a[i]=*p++;
	}
	a[i]='\0';
	printf("字符串是%s,长度是%d\n",a,k);
	printf("countine press 1\n");
	printf("exit press 0\n");
	scanf("%d",&x);
	getchar();
	}
}
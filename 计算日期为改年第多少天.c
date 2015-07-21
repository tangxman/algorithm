/*
给出年、月、日，计算改日是该年的第几天。
*/

#include<stdio.h>

int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int sum(int month,int day)
{
	int i;
	for(i=1;i<month;i++)
		day=day+a[i];
	return day;
}


void main()
{
	int year,month,day;
	printf("请输入年：");
	scanf("%d",&year);
	printf("请输入月：");
	scanf(" %d",&month);
	if(month<1||month>12)
		printf("input error!!!");
	else
		printf("请输入日：");
		scanf("%d",&day);
	    day=sum(month,day);
        printf("这是该年的第%d天",year%4==0&&month>2?day+1:day);
}



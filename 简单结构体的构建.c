/*
有10个学生，每个学生的数据包括姓名、学号、3门课程成绩，从键盘输入10个学生的数据，要求输出3门课程的总平均成绩，
以及最高分的学生数据（包括姓名、学号、3门课程平均成绩、平均分数）
*/
#include<stdio.h>
#include<stdlib.h>
#define M 10

struct student
{
	char name[20];
	long num;
	float score[3];
};

int main()
{
	struct student stu[M];
	int i,j,k,m;
	float s=0.0,num=0.0,n=0.0;
	char a[20];
	for(i=0;i<M;i++)
	{
		printf("请输入第%d个学生的姓名",i+1);
	    gets(stu[i].name);
		printf("请输入第%d个学生的学号",i+1);
		gets(a);
		stu[i].num=atol(a);
		printf("请输入第%d个学生的三门分数\n",i+1);
		for(j=0;j<3;j++)
		{
		   gets(a);
		   stu[i].score[j]=atof(a);
		}
	}

	for(j=0;j<3;j++)//求总平均成绩
	{
		printf("第%d门的总平均成绩为:",j+1);
        for(i=0;i<M;i++)
			s+=stu[i].score[j];
			printf("%.1f\n",s/M);
	}

	printf("                                    姓名      学号    平均成绩\n");

	for(j=0;j<3;j++)//求最高分学生数据
	{
	   printf("第%d门科目最高分学生的数据是：",j+1);
	   for(i=0;i<M;i++)
	   {
		   if(stu[i].score[j]>num)
		   {
			   num=stu[i].score[j];
		       k=i;
		   }
	   }
	   for(m=0;m<3;m++)
		   n+=stu[k].score[m];		   
	   printf("%10s%10d%10.1f",stu[k].name,stu[k].num,n/3);
	   n=0;
	   printf("\n");
	}

	return 0;
}


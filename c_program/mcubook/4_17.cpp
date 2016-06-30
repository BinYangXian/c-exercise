#include<stdio.h>

main()
{
	unsigned char i,j=0;

struct student            //结构名忘了
{unsigned char name[10];unsigned int result;}dl[3];  //字符串定义忘了，变量名
	printf("input everyone's name and result:\n");
	for(i=0;i<3;i++)
	{
		printf("input name:\n");
		scanf("%s",dl[i].name);
		printf("input result:\n");
		scanf("%d",&dl[i].result);
	}
	for(i=1;i<3;i++)
	{
		if(dl[i].result>dl[j].result)
			j=i;	
	}
	printf("成绩最高的学生是:%s，成绩是：%d\n",dl[j].name,dl[j].result);
}
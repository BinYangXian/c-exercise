#include<stdio.h>

main()
{
	unsigned char i,j=0;

struct student            //�ṹ������
{unsigned char name[10];unsigned int result;}dl[3];  //�ַ����������ˣ�������
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
	printf("�ɼ���ߵ�ѧ����:%s���ɼ��ǣ�%d\n",dl[j].name,dl[j].result);
}
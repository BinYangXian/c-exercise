#include<stdio.h>
int main()
{
	int month;
	const char *change[]={"jan","feb","mar","apr","may"};
	printf("�������·ݣ�");
	scanf("%d",&month);
	printf("%s",change[month-1]);
	return 0; 
}

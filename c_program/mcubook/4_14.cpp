#include<stdio.h>
main()
{
	unsigned int sum;
	unsigned char x;
	sum=0;
	for(x=1;x<11;x++)
	{
		sum=sum+x*x;
	}
	printf("1��10��ƽ��֮��Ϊ:%d\n",sum);
}

#include<reg52.h>
sbit p1_1=P1^0;
unsigned int a;
void main()
{
	while(1)
	{
		a=51000;//a���ֵ����65535��ֵΪx-65535
		p1_1=0;
		while(a--);
		a=51000;
		while(a--);
		a=51000;
		p1_1=1;
		while(a--);
		a=51000;
		while(a--);
	}
}
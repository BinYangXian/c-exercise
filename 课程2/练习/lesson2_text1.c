#include<reg52.h>
#define uint unsigned int
sbit A=P1^0;//sbit A;
//A=P1^0;
void delay(uint);//uint����z���ӷֺ�
void main()
{
	while(1)
	{
		A=0;
		delay(180);
		A=1;
		delay(180);	
	}
}
void	delay(uint z)//uintҪ��z
{
	uint x,y;
	for(x=100;x>0;x--)
		for(y=z;y>0;y--);	//Ҫ�ӷֺ�
}

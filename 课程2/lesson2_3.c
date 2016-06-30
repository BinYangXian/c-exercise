#include<reg52.h>
#include<intrins.h>
#define uint unsigned int 
#define uchar unsigned char
uchar temp; 
sbit beep=P2^3;
void delay(uint);
void main()
{
	temp=0xfe;
	while(1)
	{
		beep=0; 
		P1=temp;
		delay(230);
		P1=0xff;
		beep=1; 
		delay(230);	
		temp=_crol_(temp,1);
	
	}
}
void delay(uint z)
{
	uint x;
	uint y;
	for(x=200;x>0;x--)	  
		for(y=z;y>0;y--);	
}

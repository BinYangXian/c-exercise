#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char 
uchar a,tt;
void main()
{
		a=0xfe;
		TMOD=0X01;
		TH0=(65536-50000)/256;
		TL0=(65536-50000)%256;
		EA=1;
		ET0=1;
		TR0=1;
		while(1);
}
void timer0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt++;
	if(tt==2)
	{	
		tt=0;
		a=_crol_(a,1);
		P1=a;
	}
}
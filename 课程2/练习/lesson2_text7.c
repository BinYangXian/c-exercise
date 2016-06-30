	#include<reg52.h>  //52单片机头文件
#include <intrins.h> //包含有左右循环移位子函数的库
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
void delay(uint z)  //延时函数,z的取值为这个函数的延时ms数，如delay(200);大约延时200ms.
{					//delay(500);大约延时500ms.
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);	
}
void main()		    //主函数
{
	uchar a,i,j;
	for(j=0;j<3;j++)      //寄偶交替
	{
			P1=0x55;       //点亮小灯
			delay(300); //延时300毫秒
			P1=0xaa;
			delay(300); //延时300毫秒
	}
	for(j=0;j<3;j++)    //流水灯
	{
		a=0xfe;
		for(i=0;i<8;i++)
			{
				P1=a;       //点亮小灯
				delay(300); //延时300毫秒
				a=_crol_(a,1);
			}
	}
	P1=0xff;
	a=0xfe;
	i=0x7f;
	for(j=0;j<24;j++)     //从两边往中间流
	{
		P1=~(~a|~i);
		delay(300);
		a=_crol_(a,1);
		i=_cror_(i,1);
	}
	P1=0xff;
	for(j=0;j<3;j++)    //从中间往两边流
	{
			P1=0xe7;       //点亮小灯
			delay(300); //延时300毫秒
			P1=0xdb;
			delay(300); //延时300毫秒
			P1=0xbd;       //点亮小灯
			delay(300); //延时300毫秒
			P1=0x7e;
			delay(300); //延时300毫秒
	}
	P1=0xff;
	for(j=0;j<6;j++)    //全部闪烁
	{
			P1=~P1;       //点亮小灯
			delay(300); //延时300毫秒
	}
	P1=0xff;
	while(1);
}


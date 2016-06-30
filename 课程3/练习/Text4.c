#include<reg52.h>  //52单片机头文件
#include <intrins.h> //包含有左右循环移位子函数的库
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
sbit dula=P2^6;       //数码管段选锁存端
sbit wela=P2^7;       ////数码管位选锁存端
uchar num,tt;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void main()
{
	num=0;
	tt=0;
	TMOD=0x01;//设置定时器0为工作方式1
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;//开总中断
	ET0=1;//开定时器0中断
	TR0=1;//启动定时器0
	dula=1;
	P0=0x3f;  //给段开始送显示0。
	dula=0;//关闭段选锁存端，防止开始时出现乱码。
	wela=1;//11101010
	P0=0xc0; // 打开六个数码管位选
	wela=0;
	while(1)
	{
	
	}
}


void exter0() interrupt 1    // 定时器0中断
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt++;
		if(tt==10)   //每进入10次中断即为500ms,执行一次显示变化。
		   {
				tt=0;
				num++;
				if(num==16)
				num=0;
				dula=1;
				P0=table[num];
				dula=0;	
			}
}
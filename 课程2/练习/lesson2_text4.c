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
	uchar a;
	while(1)        //大循环
	{
		a++;
		P1=~a;
		delay(2000);	
	}
}

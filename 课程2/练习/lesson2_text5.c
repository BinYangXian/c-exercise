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
	while(1)        //大循环
	{
			a=0xfe;     //赋初值
			for(j=0;j<8;j++)
			{
				for(i=0;i<8-j;i++)   //左移
				{
					P1=a;       //点亮小灯
					delay(200); //延时200毫秒
					a=_crol_(a,1); //将a变量循环左移一位
				}
				a=_crol_(a,j);   //补齐，方便下面的左移一位
				P1=0xff; 		//全部关闭
				a=a<<1;			//左移一位让多一个灯点亮
			}
	}
}

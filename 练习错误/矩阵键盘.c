#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;
sbit key1=P3^4;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,0};
uchar num,temp,num1;
void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
uchar keyscan();
void display(uchar aa);
void main()
{
	num=17;  //开始不显数
	dula=1;
	P0=0;
	dula=0;
	wela=1;
	P0=0xc0;
	wela=0;
	
	while(1)
		{
			display(keyscan());
		}
}
void display(uchar aa)
{
			dula=1;
			P0=table[aa-1];
			dula=0;		
}
uchar keyscan()
{
			P3=0xfe;                          //第一排键盘赋值为0
			temp=P3;                          //利用temp变量读取行键值变化
			temp=temp&0xf0;              //屏蔽temp低四位行扫描信号的变化，仅通过temp高四位，读取第一排键盘键值，看是否有键按下。
			while(temp!=0xf0)                //当有第一排有键按下时 
				{
					delay(5);              //用固定delay（5）延时跳过抖动时间t，delay（5）>t。
					temp=P3;                  //利用temp变量存储键值，再次读取第一排键盘键值（去波动杂波干扰等）
					temp=temp&0xf0; //利用temp变量存储键值，再次读取第一排键盘键值（去波动杂波干扰等，如果是杂波，则不会执行下一条语句）
					while(temp!=0xf0)          //真正确定有键按下时
					{
						temp=P3;                //读取P3口，即获得真正键值
					switch(temp)                 //利用temp变量存储键值，用num变量标记键值,以便识别、调用
						{
							case 0xee:num=1;
								break;
							case 0xde:num=2;
								break;
							case 0xbe:num=3;
								break;
							case 0x7e:num=4;
								break;
						}
					while(temp!=0xf0)        //松手检测    
						{
							temp=P3;
							temp=temp&0xf0;
						}
					}
				}

			P3=0xfd;                          //
			temp=P3;                          //
			temp=temp&0xf0;                   //扫描第二排键盘四个键。
			while(temp!=0xf0)
				{
					delay(5);
					temp=P3;
					temp=temp&0xf0;
					while(temp!=0xf0)
					{
						temp=P3;
					switch(temp)
						{
							case 0xed:num=5;
								break;
							case 0xdd:num=6;
								break;
							case 0xbd:num=7;
								break;
							case 0x7d:num=8;
								break;
						}
					while(temp!=0xf0)
						{
							temp=P3;
							temp=temp&0xf0;
						}
					}
				}


			P3=0xfb;                          //
			temp=P3;                          //
			temp=temp&0xf0;                   //扫描第三排键盘四个键。
			while(temp!=0xf0)
				{
					delay(5);
					temp=P3;
					temp=temp&0xf0;
					while(temp!=0xf0)
					{
						temp=P3;
					switch(temp)
						{
							case 0xeb:num=9;
								break;
							case 0xdb:num=10;
								break;
							case 0xbb:num=11;
								break;
							case 0x7b:num=12;
								break;
						}
					while(temp!=0xf0)
						{
							temp=P3;
							temp=temp&0xf0;
						}
					}
				}


			P3=0xf7;                          //
			temp=P3;                          //
			temp=temp&0xf0;                   //扫描第四排键盘四个键。
			while(temp!=0xf0)
				{
					delay(5);
					temp=P3;
					temp=temp&0xf0;
					while(temp!=0xf0)
					{
						temp=P3;
					switch(temp)
						{
							case 0xe7:num=13;
								break;
							case 0xd7:num=14;
								break;
							case 0xb7:num=15;
								break;
							case 0x77:num=16;
								break;
						}
					while(temp!=0xf0)
						{
							temp=P3;
							temp=temp&0xf0;
						}
					}
				}
return num;        //带返回值的函数调用

}


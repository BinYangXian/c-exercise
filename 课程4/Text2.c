#include<reg52.h>
#define uchar unsigned char  //�궨��
#define uint unsigned int  
void display(uchar,uchar,uchar); //��������//void display()	;
sbit wela=P2^7;
sbit dula=P2^6;
uchar ge,shi,bai;
uint x,y,num;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void delay (uint z)
{
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void main()
{
	TMOD=0x10;//��Ȼ���ˣ�������
	num=0;
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	EA=1;
	ET1=1;
	TR1=1;
	while(1)	//���ɼӷֺã���	����
	{
			display(ge,shi,bai);////display();
	}
}
void timer1() interrupt 3//���ȼ��𣡣�����Ϊ1
{
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	num++;
	if(num==1000)
	num=0;
	bai=num/100;
	shi=num%100/10;
	ge=num%10;
	//display(bai,shi,ge)�����ɷ��ڴˣ�Ӱ�춨ʱ��Ƶ��
}
void display(uchar ge,uchar shi,uchar bai)//void display(uint num)
{	

		//bai=num/100;
	//	shi=num%100/10;
		//ge=num%10;	 
		dula=1;
		P0=table[ge];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfb;
		wela=0;
		delay(25);	//baiλ��ʾԼ2.5ms
	
		dula=1;
		P0=table[shi];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfd;
		wela=0;
		delay(25);		//shiλ��ʾԼ2.5ms
	
		dula=1;
		P0=table[bai];
		dula=0;
		P0=0xff;
		wela=1;
		P0=0xfe;
		wela=0;
		delay(25);	 	//geλ��ʾԼ2.5ms
}

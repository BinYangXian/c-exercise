	#include<reg52.h>  //52��Ƭ��ͷ�ļ�
#include <intrins.h> //����������ѭ����λ�Ӻ����Ŀ�
#define uint unsigned int    //�궨��
#define uchar unsigned char  //�궨��
void delay(uint z)  //��ʱ����,z��ȡֵΪ�����������ʱms������delay(200);��Լ��ʱ200ms.
{					//delay(500);��Լ��ʱ500ms.
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);	
}
void main()		    //������
{
	uchar a,i,j;
	for(j=0;j<3;j++)      //��ż����
	{
			P1=0x55;       //����С��
			delay(300); //��ʱ300����
			P1=0xaa;
			delay(300); //��ʱ300����
	}
	for(j=0;j<3;j++)    //��ˮ��
	{
		a=0xfe;
		for(i=0;i<8;i++)
			{
				P1=a;       //����С��
				delay(300); //��ʱ300����
				a=_crol_(a,1);
			}
	}
	P1=0xff;
	a=0xfe;
	i=0x7f;
	for(j=0;j<24;j++)     //���������м���
	{
		P1=~(~a|~i);
		delay(300);
		a=_crol_(a,1);
		i=_cror_(i,1);
	}
	P1=0xff;
	for(j=0;j<3;j++)    //���м���������
	{
			P1=0xe7;       //����С��
			delay(300); //��ʱ300����
			P1=0xdb;
			delay(300); //��ʱ300����
			P1=0xbd;       //����С��
			delay(300); //��ʱ300����
			P1=0x7e;
			delay(300); //��ʱ300����
	}
	P1=0xff;
	for(j=0;j<6;j++)    //ȫ����˸
	{
			P1=~P1;       //����С��
			delay(300); //��ʱ300����
	}
	P1=0xff;
	while(1);
}


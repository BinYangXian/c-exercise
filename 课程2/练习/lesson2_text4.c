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
	uchar a;
	while(1)        //��ѭ��
	{
		a++;
		P1=~a;
		delay(2000);	
	}
}

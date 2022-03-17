#include<reg51.h>
sbit output=P1^0;
void delayms(int times)
{
	int m;
	for(m=0;m<times;m++)
	{
		TH0=0xfc;
		TL0=0x66;
		TR0=1;
		while(TF0==0);
		TF0=0;
		TR0=0;
	}
}
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}
void main()
{
	TMOD=0x01;
	while(1)
	{
		output=1;
		delayms(1);
		output=0;
		delay(1);
	}
}
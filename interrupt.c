#include<reg51.h>
void delay(unsigned int);
void InitINT0(void);
sbit LED=P1^0;
sbit in0=P3^2;
sbit mainled=P2^0;
void main()
{
	LED=1;
	in0=1;
	InitINT0();
	while(1)
	{
		mainled=1;
		delay(200);
		mainled=0;
		delay(200);
	}
}
void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}
void InitINT0()
{
	IT0=1;
	EA=1;
	EX0=1;
}
int0ISR() interrupt 0
{
	while(in0==0)
	{
		LED=~LED;
		delay(200);
	}
}
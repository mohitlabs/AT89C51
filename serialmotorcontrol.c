#include<reg51.h>
#define moveforward 0x06
#define moveleft 0x04
#define moveright 0x02
#define movebackward 0x09
#define stop 0x00
void delay(int);
void main()
{
	TMOD=0x20;
	TH1=0xfd;
	SCON=0x50;
	TR1=1;
	while(1)
	{
		while(RI==0);
		switch(SBUF)
		{
			case 'f':P2=moveforward;break;
			case 'l':P2=moveleft;break;
			case 'r':P2=moveright;break;
			case 'b':P2=movebackward;break;
			case 's':P2=stop;break;
			default:break;
		}
		RI=0;
		delay(500);
	}
}
void delay(int a)
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}
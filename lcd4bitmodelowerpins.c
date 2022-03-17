#include<reg51.h>
void delay(int);
void lcdinit(void);
void lcdcmd(int);
void lcddata(char);
void lcdcmddata(int,char*);
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
void main()
{
	lcdinit();
	while(1)
	{
		lcdcmddata(0x80,"DSPL");
		lcdcmddata(0xc0,"India");
		delay(200);
		lcdcmd(0x01);
		delay(200);
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
void lcdinit()
{
	lcdcmd(0x01);
	lcdcmd(0x02);
	lcdcmd(0x28);
	lcdcmd(0x0c);
}
void lcdcmd(int c)
{
	P2=(c>>4);
	RS=0;
	RW=0;
	EN=1;
	delay(10);
	EN=0;
	P2=(0x0f&c);
	EN=1;
	delay(10);
	EN=0;
}
void lcddata(char d)
{
	P2=(d>>4);
	RS=1;
	RW=0;
	EN=1;
	delay(10);
	EN=0;
	P2=(0x0f&d);
	EN=1;
	delay(10);
	EN=0;
}
void lcdcmddata(int c,char *d)
{
	lcdcmd(c);
	while(*d)
	{
		lcddata(*d++);
	}
}
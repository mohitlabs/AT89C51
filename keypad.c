#include<reg51.h>
void delay(int);
void lcdinit(void);
void lcdcmd(int);
void lcddata(char);
void keypadinit(void);
char getkey(void);
char keypaddata(void);
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
sbit r1=P3^0;
sbit r2=P3^1;
sbit r3=P3^2;
sbit r4=P3^3;
sbit c1=P3^4;
sbit c2=P3^5;
sbit c3=P3^6;
sbit c4=P3^7;
void main()
{
	lcdinit();
	keypadinit();
	while(1)
	{
		lcddata(keypaddata());
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
	lcdcmd(0x38);
	lcdcmd(0x08);
	lcdcmd(0x0c);
	lcdcmd(0x01);
}
void lcdcmd(int c)
{
	P2=c;
	RS=0;
	RW=0;
	EN=1;
	delay(10);
	EN=0;
}
void lcddata(char d)
{
	P2=d;
	RS=1;
	RW=0;
	EN=1;
	delay(10);
	EN=0;
}
void keypadinit()
{
	P3=0xf0;
}
char getkey(void)
{
	r1=0;
	r2=1;
	r3=1;
	r4=1;
	if(c1==0)
	{
		delay(10);
		while(c1==0);
		return'7';
	}
	if(c2==0)
	{
		delay(10);
		while(c2==0);
		return'8';
	}
	if(c3==0)
	{
		delay(10);
		while(c3==0);
		return'9';
	}
	if(c4==0)
	{
		delay(10);
		while(c4==0);
		return'/';
	}
	r1=1;
	r2=0;
	r3=1;
	r4=1;
	if(c1==0)
	{
		delay(10);
		while(c1==0);
		return'4';
	}
	if(c2==0)
	{
		delay(10);
		while(c2==0);
		return'5';
	}
	if(c3==0)
	{
		delay(10);
		while(c3==0);
		return'6';
	}
	if(c4==0)
	{
		delay(10);
		while(c4==0);
		return'X';
	}
	r1=1;
	r2=1;
	r3=0;
	r4=1;
	if(c1==0)
	{
		delay(10);
		while(c1==0);
		return'1';
	}
	if(c2==0)
	{
		delay(10);
		while(c2==0);
		return'2';
	}
	if(c3==0)
	{
		delay(10);
		while(c3==0);
		return'3';
	}
	if(c4==0)
	{
		delay(10);
		while(c4==0);
		return'-';
	}
	r1=1;
	r2=1;
	r3=1;
	r4=0;
	if(c1==0)
	{
		delay(10);
		while(c1==0);
		return'C';
	}
	if(c2==0)
	{
		delay(10);
		while(c2==0);
		return'0';
	}
	if(c3==0)
	{
		delay(10);
		while(c3==0);
		return'=';
	}
	if(c4==0)
	{
		delay(10);
		while(c4==0);
		return'+';
	}
	else
	{
		return 'n';
	}
}
char keypaddata(void)
{
	char key='n';
	while(key=='n')
	{
		key=getkey();
	}
	return key;
}
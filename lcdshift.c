#include<reg51.h>
void delay(int);
void lcdinit(void);
void lcdcmd(int);
void lcddata(char);
void lcdcmddata(int,char*);
char text1[]="Duccadd",text2[]="Solutions";
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
void main()
{
	int k;
	lcdinit();
	for(k=0;1;k++)
	{
		if((sizeof(text1)/sizeof(text1[0]))>(sizeof(text2)/sizeof(text2[0])))
		{
			if(k==16+(sizeof(text1)/sizeof(text1[0])))
			{
				k=0;
				lcdcmd(0x01);
			}
		}
		if((sizeof(text1)/sizeof(text1[0]))<(sizeof(text2)/sizeof(text2[0])))
		{
			if(k==16+(sizeof(text2)/sizeof(text2[0])))
			{
				k=0;
				lcdcmd(0x01);
			}
		}
		lcdcmddata(0x8f,text1);
		lcdcmddata(0xcf,text2);
		delay(10);
		lcdcmd(0x18);
		delay(10);
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
void lcdcmddata(int c,char *d)
{
	lcdcmd(c);
	while(*d)
	{
		lcddata(*d++);
	}
}
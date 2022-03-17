#include<reg51.h>
unsigned int a,i,j,k,length,hex[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay(a)
{
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}
void main()
{
	length=(sizeof(hex)/sizeof(hex[0]))-1;
	P2=0xff;
	for(k=0;1;k++)
	{
		if(k>length)
		{
			k=0;
		}
		P2=hex[k];
		delay(500);
	}
}
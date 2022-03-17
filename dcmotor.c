#include<reg51.h>
unsigned int a,i,j,k,pattern[]={0x0a,0x00,0x05,0x00,0x09,0x00,0x06,0x00};
void delay(a)
{
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}
void main()
{
	for(k=0;k<8;k++)
	{
        if(k>7)
		{
			k=0;
		}
		P0=pattern[k];
		delay(1000);
	}
}
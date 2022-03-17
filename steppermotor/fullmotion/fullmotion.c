#include<reg51.h>
unsigned int a,i,j,k,pattern[]={0x03,0x06,0x0c,0x09};
void delay(a)
{
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}
void main()
{
	for(k=0;k<4;k++)
	{
        if(k>3)
		{
			k=0;
		}
		P0=pattern[k];
		delay(1000);
	}
}
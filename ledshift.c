#include<reg51.h>
unsigned int a,i,j,k;
void delay(a)
{
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}
void main()
{
	P1=~0x00;
	while(1)
	{
		P1=~0x01;
		for(k=0;k<8;k++)
		{
			P1=~(0x01<<k);
			delay(200);
		}
	}
}
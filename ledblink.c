#include<reg51.h>
unsigned int a,i,j,x;
void delay(a)
{
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}
void main()
{
	for(x=1;1;x++)
	{
		switch(x)
		{
			default :break;
			case 3:x=4;break;
			case 5:x=8;break;
			case 9:x=1;
		}
		P1=0x0+x;
		P2=0x0+x;
		delay(200);
	}
}
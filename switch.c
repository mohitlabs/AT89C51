#include<reg51.h>
sbit sw=P1^0;
sbit load=P1^1;
void main()
{
	load=1;
	sw=0;
	while(1)
	{
		if(sw==1)
		{
			load=0;
		}
		else
		{
			load=1;
		}
	}
}
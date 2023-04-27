#include <reg51.h>
#include <stdio.h>

#define uchar unsigned char
void Delay(uchar i)
{
	uchar j = 1940;
	while(i--)
		while(j--);
}

void t1()
{
	uchar arr[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
	uchar i = 0;
		for(i = 0; i < 8; i++)
		{
			P0 = ~arr[i];
			Delay(100);
		}
		for(i = 7; i > 0; i--)
		{
			P0 = ~arr[i];
			Delay(100);
		}
}
void t2()
{
		uchar arr[] = {0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff,0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01};
		uchar len = 15;
		
		uchar j,k = 0;
		for(j = 0;j<len;j++)
			{
				P0 = ~arr[j];
				Delay(100);
			}
		
		for(k = len-1;k>0;k--)
			{
				P0 = ~arr[k];
				Delay(100);
			}
			
		
}
void t3()
{
		
			P0 = 0xFF;
			Delay(100);
			P0 = 0x00;
			Delay(100);
		
}

void main()
{
		while(1)
		{
				uchar cmd = ~P2;
				switch(cmd)
				{
						case 0x0:
							P0 = 0x0;
							break;
						
						case 0x01:
							t1();
							break;
						
						case 0x08:
							t2();
							break;
						
						case 0x80:
							t3();
							break;
						
						case 0x89:
							t1();
							t2();
							t3();
							t3();
							t3();
							break;
						
						default:
							P0 = 0x0;
							break;
				}
		}
}
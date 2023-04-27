#include <reg51.h>
#include <stdio.h>
#include "kb44.h"
#define uchar unsigned char

uchar speed = 50;
uchar index = 0;
uchar s[3] = {200, 100, 80};
uchar seg7[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
uchar time[3] = {1,1,3};
uchar timeIndex = 0;

uchar button()
{
	if(P3^3)
	{
		Delay(500);
		if(~ (P3^3))
			return 1;
	}
	return 0;
}

uchar button2()
{
	if(P3^2)
	{
		Delay(500);
		if(~ (P3^2))
			return 1;
	}
	return 0;
}
uchar button3()
{
	if(P2)
	{
		Delay(500);
		if(~ (P2))
			return 1;
	}
	return 0;
}
void t1()
{
	uchar arr[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
	uchar i = 0;
	uchar tmp = 0;
	timeIndex = 0;
	tmp = time[0];
	P1 = seg7[tmp];
	while(tmp--)
	{
		for(i = 0; i < 8; i++)
		{
			P0 = ~arr[i];
			Delay(speed);
		}
		for(i = 7; i > 0; i--)
		{
			P0 = ~arr[i];
			Delay(speed);
		}
	}
}
void t2()
{
		
		uchar arr[] = {0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff,0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01};
		uchar len = 15;
		uchar tmp = 0;
		timeIndex = 1;
		tmp = time[1];
		P1 = seg7[tmp];		
		while(tmp--)
		{
			uchar j,k = 0;
			for(j = 0;j<len;j++)
				{
					P0 = ~arr[j];
					Delay(speed);
				}
			
			for(k = len-1;k>0;k--)
				{
					P0 = ~arr[k];
					Delay(speed);
				}
		}
		
}
void t3()
{
			uchar tmp = 0;
			timeIndex = 2;
			tmp = time[2];
			P1 = seg7[tmp];
			while(tmp--)
			{
				P0 = 0xFF;
				Delay(speed);
				P0 = 0x00;
				Delay(speed);
			}
}

void main()
{
	uchar tmp = 0;
	TCON = 5;
	IE = 0x85;
		while(1)
		{
			 t1();
			 t2();
			 t3();
		}
}

void EXINT0(void ) interrupt 0
{
	uchar tt = 0;
	button2();
	while(!((tt >= 1) && (tt <= 9)))tt = kbscan();
	time[timeIndex] = tt;
	P1 = seg7[tt];
} 

void EXINT1(void ) interrupt 2
{
	button();
	index %= 3;
	speed = s[index];
	index++;
} 
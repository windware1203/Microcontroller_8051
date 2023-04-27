#include <reg51.h>
#include "seg7.h"
#define uchar unsigned char

sbit SW1 = P2^7;
sbit SW2 = P2^6;
sbit SW3 = P2^5;
sbit SW4 = P2^4;
sbit SW5 = P2^3;
sbit SW6 = P2^2;
sbit SW7 = P2^1;
sbit SW8 = P2^0;

uchar 	valC = 0, valD = 0;
void task1()
{
	valC = 0;
	valC += (~SW5)? 8 : 0;
	valC += (~SW6)? 4 : 0;
	valC += (~SW7)? 2 : 0;
	valC += (~SW8)? 1 : 0;
	digitx1(0, valC);
}
void task2()
{
	uchar a = 0,b = 0;
	a += (~SW3)? 4 : 0;
	a += (~SW4)? 2 : 0;
	a += (~SW5)? 1 : 0;
	
	b += (~SW6)? 4 : 0;
	b += (~SW7)? 2 : 0;
	b += (~SW8)? 1 : 0;
	valD = a + b;
	digitx1(0, valD);
}
void task3()
{
	uchar cur = 0;
	uchar bound = valC + 1;
	uchar cnt = bound;
	while(cnt--)
	{
		
		{
			digitx1(0, cur);
			dalay1ms(1000);
			cur++;
			cur %= bound;
		}
	}
	
}
void task4()
{
	uchar cur = valD;
	uchar cnt = cur+1;
	while(cnt--)
	{
		
		{
			digitx1(0, cur);
			dalay1ms(1000);
			(cur == -1)? cur = valD : cur--;
		}
	}
}

void main()
{
	while(1)
	{
		if(~SW1 == 0)
		{
			if(~SW2 == 0)
			{
				task1();
			}
			else
			{
				task2();
			}
		}
		else
		{
			if(~SW2 == 0)
			{
				task3();
			}
			else
			{
				task4();
			}
		}
	}
}
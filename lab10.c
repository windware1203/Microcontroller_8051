#include <reg51.h>
#include <stdio.h>
#include "kb44.h"
#define uchar unsigned char
uchar seg7[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e,0xf6};

uchar subb(uchar a, uchar b)
{
	return a > b ? a - b : b - a;
}

void main()
{
	uchar cmm = 0, cmd = 0,kk = 0;
	uchar a = 0,b = 0;
	uchar tt = 0xff;
	P0 = seg7[0];
	while(1)
	{
		tt = kbscan();
		while(tt == 11)a = 0, b = 0, tt = kbscan();
		
		a = tt;
		if(tt != 0xff)P0 = seg7[tt];
		
		
		cmm = kbscan() - 12;
		
		kk = kbscan();
		while(kk == 11)a = 0, b = 0,kk = kbscan();
		
		b = kk;
		if(kk != 0xff)P0 = seg7[kk];
		
		cmd = kbscan();
		if(cmd == 10)
		{
			switch(cmm)
			{
				case 0:
					if(a+b > 15)
						P0 = seg7[16];
					else
						P0 = seg7[a+b];
					break;
				case 1:
						P0 = seg7[subb(a,b)];
					break;
				case 2:
					if(a*b > 15)
						P0 = seg7[16];
					else
						P0 = seg7[a*b];
					break;
				case 3:
					if(a/b > 15)
						P0 = seg7[16];
					else
						P0 = seg7[a/b];
					break;
			}
		}
		
	}
}
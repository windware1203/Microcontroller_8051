#include <reg51.h>
#include <stdio.h>
#include <absacc.h>
#define uchar unsigned char
data uchar arr[9] _at_ 0x30;
data uchar cmd _at_ 0x40;
void Delay(uchar i)
{
	while(i--);
}

void init()
{
		char i;
		for(i = 0; i < 8; i++)
			arr[i] = 0x00;
}

void task1(uchar arr1[])
{
		char i;
		for(i = 0; i < 8;i++)
			{
				P0 = arr1[i];
				Delay(1000);
				arr[i] = arr1[i];
			}
}



void task2(uchar arr2[])
{
		arr[0] = arr2[0] + arr2[2];
		arr[1] = arr2[1] + arr2[3] + 1 ;
		arr[2] = arr2[0] - arr2[2];
		arr[3] = arr2[1] - arr2[3] + (CY ? 1 : 0) ;
		*(int*)(arr+4) = arr2[4] * arr2[5];
	
		*(arr+6) = *(arr+4);
		*(arr+4) = *(arr+5);
		*(arr+5) = *(arr+6);
		
		*(arr+6) = 0;
		
	
		*(int*)(arr+9) = arr2[3] * arr2[5];
		*(arr+6) = *(arr+9);
		*(arr+5) = *(arr+10) + *(arr+5);
	
		arr[7] = arr2[4]/arr2[5];
		arr[8] = arr2[4]%arr2[5];
	
}	


void task3(uchar arr1[])
{
		char i = 0, j = 0;
		for(i = 0; i < 7; i++)
		{
			for(j = 0; j < 7-i; j++)
			{
				if(arr1[j] > arr1[j+1])
				{
					uchar t = arr1[j+1];
					arr1[j+1] = arr1[j];
					arr1[j] = t;
				}
			}
		}
}	
	

void main()
{
		 
		uchar arr1[8] = {0x00, 0x81, 0xC3, 0xE7, 0xFF, 0x7E, 0x3C, 0x18};
		uchar arr2[6] = {0x90, 0x34, 0x86, 0x23, 0x57, 0x12};
		
		while(1)
		{
				
				cmd = ~P1;
				switch(cmd)
				{
						case 0x00:
							init();//v
							break;
						case 0x01:
							task1(arr1);//v
							break;
						case 0x02:
							task2(arr2);
							break;
						case 0x03:
							task3(arr1);//v
							break;
				}
				
		}
}
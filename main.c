#include"head.h"

uchar a[8]={1,2,3,4,5,6,7,8};

void main()
{
	//uchar i,j;
	while(1)
	{
		lcdShow(readOneTemp());
		/*
		for(i=0;i<50;i++)
			for(j=0;j<10;j++)
			{
				lcdShow(i);
			}
			//*/
	}
}
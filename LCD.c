#include"head.h"

uchar seg[4]={0x0a,0,0,0};

void calSEG(int n)
{
	bit signFlag=1;
	uchar digit[2];
	uchar lcdCode[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	uchar units,tens;
	if(n<0)
	{
		seg[2]=0x40;
		signFlag=0;
		n=-n;
	}
	if(n>99)
	{
		seg[0]=0x2a;
		seg[2]=0x0;
		seg[3]=0x0;
		seg[4]=0x0;
	}
	else
	{
		digit[0]=n%10;
		digit[1]=(n/10)%10;
		tens=lcdCode[digit[1]];
		units=lcdCode[digit[0]];
		seg[0]|=(tens&0x01)<<2						|	(units&0x01);
		seg[1]|=((tens&0x40)>>3	|	(tens&0x02)<<1)	|	((units&0x40)>>5	|	(units&0x02)>>1);
		seg[2]|=((tens&0x20)>>2	|	(tens&0x04))	|	((units&0x20)>>4	|	(units&0x04)>>2);
		seg[3]|=((tens&0x10)>>1	|	(tens&0x08)>>1)	|	((units&0x10)>>3	|	(units&0x08)>>3);
	}
}



void lcdShow(int n)
{
	uchar i,j;
	uchar highSet[4]={0x01,0x02,0x04,0x08};
	uchar lowSet[4]={0x01,0x02,0x04,0x08};
	j=10;
	calSEG(n);
	while(j--)
	{
		for(i=0;i<4;i++)
		{
			P3M1=0x0f;
			P3M0=0x00;
			P1=seg[i];
			P3M1=highSet[i];
			P3M0=lowSet[i];
			P3=~(0x01<<i);
			DelayNms(2);
			P3=~P3;
			P1=~P1;
			DelayNms(2);
		}	
	}

	
}
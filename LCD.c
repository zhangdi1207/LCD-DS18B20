#include"head.h"

uchar seg[4]={0,0,0,0x0a};

void calSEG(int n)
{
	uchar digit[2];
	uchar i;
	uchar lcdCode[]={0x77,0x14,0x5b,0x5d,0x3c,0x6d,0x6f,0x54,0x7f,0x7d};
	uchar units,tens;
	for(i=0;i<4;i++)
	{
		seg[i]=0;
	}
	seg[3]=0x0a;
	if(n<0)
	{
		seg[1]=0x20;
		n=-n;
	}
	if(n>99)
	{
		seg[0]=0x0;
		seg[1]=0x0;
		seg[2]=0x0;
		seg[3]=0x2a;
	}
	else
	{
		digit[0]=n%10;
		digit[1]=(n/10)%10;
		tens=lcdCode[digit[1]];
		units=lcdCode[digit[0]];
		seg[0]|=(tens&0x03)<<2	|	(units&0x03);
		seg[1]|=(tens&0x0c)		|	(units&0x0c)>>2;
		seg[2]|=(tens&0x30)>>2	|	(units&0x30)>>4;
		seg[3]|=(tens&0xc0)>>4	|	(units&0xc0)>>6;
	}
}


//*
void lcdShow(int n)
{
	uchar i,j;
	uchar highSet[4]={0x0e,0x0d,0x0b,0x07};
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
//*/
/*
void lcdShow(int n)
{
	uchar i,j;
	uchar highSet[4]={0x0e,0x0d,0x0b,0x07};
	uchar lowSet[4]={0x01,0x02,0x04,0x08};
	j=10;
	seg[0]=0x04;
	seg[1]=0x0d;
	seg[2]=0x09;
	seg[3]=0x24;
	
	while(j--)
	{
		for(i=0;i<4;i++)
		{
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
//*/
#include"head.h"

/**************************************
ÑÓÊ±XÎ¢Ãë(STC15F104E@12M)
**************************************/
// *
void DelayXus(uint n)                  //LCALL 6
{
	n>>=2;
    while (n--)                        //DJNZ  4
    {
        _nop_();                       //NOP  1+1=12
        _nop_();                     
    }
}
//*/
/*
void DelayXus(uint n)                  //LCALL 6
{
    while (n--);                        //DJNZ  4
}
//*/
void DelayNms(uint n)
{
	WDT_CONTR = WDT;
	while(n--)
	{
		DelayXus(1000);
	}
}
/*

void DelayXus(unsigned int n)                  //LCALL 6
{
	if(n<=2)
	{
	}
	else if(n<7)
	{
		n-=2;
		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
		nop(); 
	}
	else if(n<20)
	{
		n-=6;
		while(n--);
	}
	else
	{
	n-=10;
    while (n--);
	}
}

void Delay1Ms()
{
	unsigned char i,j;
	i = 6;
	j = 130;
	do
	{
	while(j--);
	} while (--i);
}


void DelayNms(unsigned int n)
{
	while(n--)
	{
		Delay1Ms();
	}
}

	  */


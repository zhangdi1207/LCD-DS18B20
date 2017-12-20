#ifndef _HEAD_H_
#define _HEAD_H_
#include <reg52.h>
#include <intrins.h>
#define nop() _nop_()
#define uchar unsigned char
#define uint unsigned int

#define WDT			0x34			//看门狗初始化@12MHz，1.0485s

sfr CLK_DIV = 0x97;					//时钟命令寄存器
sfr WDT_CONTR = 0xc1;//看门狗
sfr P3M1=0xb1;
sfr P3M0=0xb2;
sfr P5=0xc8;

sbit SEG10=P1^0;
sbit SEG9=P1^1;
sbit SEG8=P1^2;
sbit SEG7=P1^3;
sbit SEG6=P1^4;
sbit SEG5=P1^5;

sbit DQ=P5^5;


void lcdShow(int n);

void DelayXus(uint n);
void DelayNms(uint n);

int readOneTemp();

#endif
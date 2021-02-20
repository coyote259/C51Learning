/*
Lesson3
数码管显示的原理
数码管的静态显示
中断原理
定时器应用

*/
/*申明*/
#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
void delay(uint z);
/*定义*/
sbit dula = P2^6;
sbit wela = P2^7;
uint num;
sbit d1=P1^0; //第一个发光二极管

/*使用code把定义的变量放在ROM中，而不是RAM中*/
uchar code table[]={
    0x3f,0x06,0x5b,0x4f,
    0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,
    0x39,0x5e,0x79,0x71
};

void main()
{  
    EA=1; //打开CPU总中断
    EX0=1; //开外部中断0
    IT0=1; //设置外部中断0的出发方式为低电平触发
    
    wela = 1;
    P0 = 0xc0;
    wela = 0;
    while (1)
    {
        for ( num = 0; num < 16; num++)
        {
            d1=1;
            dula=1;
            P0=table[num];
            //dula=0;
            delay(1000);
        }
        
    }
    
}


/*延时函数，单位是ms*/
void delay(uint z)
{
    uint x,y;
    for ( x = z; x > 0; x--)
    {
        for ( y=110; y>0; y--);
    }
}

/*中断函数，不需要申明*/
void exter0() interrupt 0
{
    d1=0;
}
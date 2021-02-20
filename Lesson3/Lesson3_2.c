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
/*定义*/
sbit dula = P2^6;
sbit wela = P2^7;
uint num;
/*使用code把定义的变量放在ROM中，而不是RAM中*/
uchar code table[]={
    0x3f,0x06,0x5b,0x4f,
    0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,
    0x39,0x5e,0x79,0x71
};
/*延时函数，单位是ms*/
void delay(uint z)
{
    uint x,y;
    for ( x = z; x > 0; x--)
    {
        for ( y=110; y>0; y--);
    }
}

void main()
{  
    wela = 1;
    P0 = 0xc0;
    wela = 0;
    while (1)
    {
        for ( num = 0; num < 16; num++)
        {
            dula=1;
            P0=table[num];
            dula=0;
            delay(1000);
        }
        
    }
    
}



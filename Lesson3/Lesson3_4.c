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
void init();
/*定义*/
sbit dula = P2^6;
sbit wela = P2^7;
uint num=0,tt=0;
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
    init();
    wela = 1;
    P0 = 0xc0;
    wela = 0;
    P0=table[num++];
    while (1)
    {
        if (tt==4)
        {
            tt=0;
            dula=1;
            P0=table[num++];
            num=num%16;            
            //dula=0;
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
void exter0() interrupt 1
{
    TH0=(65536-50000)/256;
    TL0=(65536-50000)%256;
    tt++;
}


/*进行程序初始化*/
void init()
{
    TMOD = 0x01; //设置定时器0为工作方式1
    TH0=(65536-50000)/256;
    TL0=(65536-50000)%256;
    EA=1; //打开CPU总中断
    ET0=1; //打开定时器0中断
    TR0=1; //启动定时器0工作
}
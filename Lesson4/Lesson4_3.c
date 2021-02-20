#include<reg52.h>
#include<intrins.h>

#define uint unsigned int
#define uchar unsigned char
sbit dula = P2^6;
sbit wela = P2^7;
void delay(uint z);
void init();
uchar temp,tt=0,num=0;
uchar code table[]={
    0x3f,0x06,0x5b,0x4f,
    0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,
    0x39,0x5e,0x79,0x71
};
uchar code table_we[]={
    0xfe,0xfd,0xfb,0xf7,0xef,0xdf
};


void main()
{
    init();
    temp = 0xfe;
    P1 = temp;
    wela = 0;
    // dula = 1;
    // P0 = table[16];
    // dula = 0;
    while(1)
    {
        if(tt>=20)
        {
            tt=0;
            temp=_crol_(temp,1);
            P1=temp;
            P0=table_we[num%6];
            wela=1;       
            wela=0;
            P0=table[num%6+1];
            dula=1;
            dula=0;
            num++;
        }
        
    }

}

void delay(uint z)
{
    uint x,y;
    for ( x = z; x > 0; x--)
    {
        for ( y = 110; y > 0; y--)
        {

        }
        
    }
    
}

void init()
{
    TMOD=0x01;
    TH0=(65536-50000)/256;
    TL0=(65536-50000)%256;
    EA=1;
    ET0=1;
    TR0=1; //启动T0定时器
}

void timer0() interrupt 1
{
    TH0=(65536-50000)/256;
    TL0=(65536-50000)%256;
    tt++;
}
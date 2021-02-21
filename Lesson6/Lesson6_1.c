#include <reg52.h>
#include <Utility.h>

sbit csda=P3^2;
sbit wr=P3^6;
sbit wela=P2^7;
uchar count=0;

void main()
{
    wela=0x00;
    csda=0;
    wr=0;
    while(1)
    {
        P0=(++count)%256;
        delay(7);
    }
    
}
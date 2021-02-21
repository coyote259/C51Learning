#include <reg52.h>
#include <Utility.h>

sbit csda=P3^2;
sbit wr=P3^6;
sbit wela=P2^7;
sbit rd=P3^7;

uchar count=0;

void init();
void start();

void main()
{
    init();
    
    while(1)
    {
        start();
        delay(100);
        rd=0;
    }
}

void init()
{
    P0=0x7f;
    wela=1;
}

void start()
{
    wr=1;
    wr=0;
}
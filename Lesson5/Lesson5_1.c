#include <reg52.h>
#include <Utility.h>


sbit d1=P1^0;
sbit key1=P3^4;
sbit dula=P2^6;
sbit wela=P2^7;

uchar num=0;

void main()
{
    wela=1;
    P0=0xfe;
    wela=0;
    P3=0xff;
    while(1)
    {
        if (key1==0)
        {
            d1=0;
            delay(10);
            if (key1==0)
            {
                num=(++num)%9;
                while(!key1); //等待松手
            }        
        }
        else
        {
            d1=1;
        }
        dula=1;
        P0=table[num+1];
        dula=0;
        
    }
}


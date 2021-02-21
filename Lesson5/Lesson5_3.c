#include <reg52.h>
#include <Utility.h>

sbit dula=P2^2;
sbit wela=P2^7;

void main()
{
    uchar temp,num=0;
    wela=1;
    P0=0xc0;
    wela=0;
    while(1)
    {
        P3=0xfe;
        temp=P3;
        temp=temp&0xf0;
        if (temp != 0xf0)
        {
            // delay(10);
            // temp=P3;
            // temp=temp&0xf0;
            
            
                switch (temp)
                {
                case 0xe0:
                    num=1;
                    break;
                case 0xd0:
                    num=2;
                    break;
                case 0xb0:
                    num=3;
                    break;
                case 0x70:
                    num=4;
                    break;
                
                default:num++;
                    break;
                }
            
            
            
        }
        dula=1;
        P0=table[num];
        dula=0;
    }
}
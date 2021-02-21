/*定义申明字符*/
#define uint unsigned int
#define uchar unsigned char

/*定义数码管要显示的字符*/
uchar code table[]={
    0x3f,0x06,0x5b,0x4f,
    0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,
    0x39,0x5e,0x79,0x71
};

/*定义delay函数，延迟z ms*/
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
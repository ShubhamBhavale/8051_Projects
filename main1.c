
#include <reg51.h>

void delay()
{
    unsigned int i, j;

    for(i = 0; i < 100; i++)
    {
        for(j = 0; j < 1275; j++);
    }
}

void main()
{
    unsigned char seg[10] =
    {
        0xC0,  // 0
        0xF9,  // 1
        0xA4,  // 2
        0xB0,  // 3
        0x99,  // 4
        0x92,  // 5
        0x82,  // 6
        0xF8,  // 7
        0x80,  // 8
        0x90   // 9
    };

    unsigned char i;

    while(1)
    {
        for(i = 0; i < 10; i++)
        {
            P2 = seg[i];
            delay();
        }
    }
}


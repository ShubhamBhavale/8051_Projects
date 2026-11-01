
#include <reg51.h>

// Keypad row connections
sbit R1 = P3^0;
sbit R2 = P3^1;
sbit R3 = P3^2;
sbit R4 = P3^3;

// Keypad column connections
sbit C1 = P3^4;
sbit C2 = P3^5;
sbit C3 = P3^6;

// Delay function
void delay()
{
    unsigned int i, j;

    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 1275; j++);
    }
}

// Keypad scanning function
unsigned char keypad()
{
    // Row 1
    R1=0; R2=1; R3=1; R4=1;

    if(C1==0) return 1;
    if(C2==0) return 2;
    if(C3==0) return 3;

    // Row 2
    R1=1; R2=0; R3=1; R4=1;

    if(C1==0) return 4;
    if(C2==0) return 5;
    if(C3==0) return 6;

    // Row 3
    R1=1; R2=1; R3=0; R4=1;

    if(C1==0) return 7;
    if(C2==0) return 8;
    if(C3==0) return 9;

    // Row 4
    R1=1; R2=1; R3=1; R4=0;

    if(C1==0) return 10;  // *
    if(C2==0) return 0;   // 0
    if(C3==0) return 11;  // #

    return 255;           // No key pressed
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

    unsigned char key;

    P2 = 0xFF;
    P3 = 0xFF;

    while(1)
    {
        key = keypad();

        if(key != 255)
        {
            delay();

            if(keypad() == key)
            {
                if(key <= 9)
                {
                    P2 = seg[key];
                }

                // Wait until key is released
                while(keypad() != 255);
                delay();
            }
        }
    }
}

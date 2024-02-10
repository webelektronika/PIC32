#include <p32xxxx.h>

#define LEDs        LATD
#define LEDsOn()    { LEDs = 0xFFFF; }
#define LEDsInc()   { LEDs++; }

void Keses(unsigned int hatar);

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;  // ?
    
    while(1)
    {
        Keses(10000);
        LEDsInc();
    }
}

void Keses(unsigned int hatar)
{
    int k;
    for(k = 0; k < hatar; k++);
}

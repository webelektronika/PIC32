#include <p32xxxx.h>

#define LEDs        LATD
#define LEDsInc()   { LEDs++; }

// számoljunk a D porton
void keses(unsigned int hatar);

main()
{
    TRISD = 0x0000;
    
    while(1)
    {
        LEDsInc();
        keses(10000);
    }
}

void keses(unsigned int hatar)
{
    int a;
    for(a = 0; a < hatar; a++);
}
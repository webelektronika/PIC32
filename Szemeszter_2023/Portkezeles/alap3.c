#include <p32xxxx.h>

#define LEDs        LATD
#define BTN         PORTBbits.RB1
#define LEDsA()       { LEDs = 0xAAAA; }
#define LEDs5()       { LEDs = 0x5555; }

int gA;

main()
{
    int a;
    TRISA = 0x0000;
    //TRISB = 0x0002;
    TRISBbits.TRISB1 = 1;
    TRISD = 0x0000;
    LEDs = 0xAAAA;   // 1010 1010 1010 1010
    
    while(1)
    {
        if (BTN)
        {
            LEDsA();
        }
        else
        {
            LEDs5();
        }
    }
}
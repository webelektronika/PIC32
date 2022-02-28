#include <p32xxxx.h>

// BTN: PORTC1

main()
{
    TRISCbits.TRISC1 = 1;
    TRISD = 0x0000;
    
    while(1)
    {
        if(PORTCbits.RC1)
            LATD = 0xAAAA;
        else
            LATD = 0x5555;
    }
}
#include <p32xxxx.h>

#define BTN         PORTCbits.RC1
#define BTN_Tr      TRISCbits.TRISC1
#define LEDs        LATD

main()
{
    BTN_Tr = 1;
    TRISD = 0x0000;
    
    while(1)
    {
        if(BTN)
            LEDs = 0xAAAA;
        else
            LEDs = 0x5555;
    }
}
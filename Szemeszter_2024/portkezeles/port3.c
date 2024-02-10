#include <p32xxxx.h>

#define LEDs        LATD
#define TRLEDs      TRISD
#define BTN         PORTCbits.RC1
#define TRBTN       TRISCbits.TRISC1

main()
{
    //TRISC = 0xFFFF;
    TRBTN = 1;
    TRLEDs = 0x0000;
    
    while(1)
    {
        if(BTN)
        {
            LEDs = 0xFFFF;
        }
        else
            LEDs = 0x0000;
    }   
}

#include <p32xxxx.h>

#define LEDs        LATD
#define TRLEDs      TRISD
#define BTN         PORTCbits.RC1
#define TRBTN       TRISCbits.TRISC1

// makrók alkalmazása
#define LEDsOn()    { LEDs = 0xFFFF; }
#define LEDsOff()   { LEDs = 0x0000; }

main()
{
    //TRISC = 0xFFFF;
    TRBTN = 1;
    TRLEDs = 0x0000;
    
    while(1)
    {
        if(BTN)
        {
            LEDsOn();
        }
        else
            LEDsOff();
    }   
}

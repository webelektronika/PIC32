#include <p32xxxx.h>


main()
{
    TRISCbits.TRISC2 = 1;
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // Timer3 számláló mód
    PR3 = 0xFFFF;
    T3CON = 0x8002;
    
    while(1)
        LATD = TMR3;
}
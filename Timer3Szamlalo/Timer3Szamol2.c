#include <p32xxxx.h>

void Timer3_Config(unsigned int hatar, unsigned int oszto);

main()
{
    TRISCbits.TRISC2 = 1;
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // Timer3 számláló mód
    Timer3_Config(0xFFFF, 0);
    while(1)
        LATD = TMR3;
}

void Timer3_Config(unsigned int hatar, unsigned int oszto)
{
    PR3 = hatar;
    T3CONbits.TCKPS = oszto;
    T3CONbits.TCS = 1;
    T3CONbits.ON = 1;
}

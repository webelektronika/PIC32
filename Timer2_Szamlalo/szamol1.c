#include <xc.h>

int main()
{
    // T2CK/RC1 bemenet
    TRISCbits.TRISC1 = 1;
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // Timer2 beállítása
    PR2 = 0xFFFF;
    T2CON = 0x8002;
    
    while(1)
        LATD = TMR2;
} 

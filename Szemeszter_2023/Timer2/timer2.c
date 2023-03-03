// A Timer2 számlálóként kerül felhasználásra.
// A T2CK az RC.1-es porton található.
#include <p32xxxx.h>

main()
{
    // portkonfig
    TRISCbits.TRISC1 = 1;
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // Timer2 konfig, számláló
    T2CONbits.TCS = 1;
    T2CONbits.TGATE = 0;
    T2CONbits.TCKPS = 0;
    T2CONbits.T32 = 0;
    PR2 = 0xFFFF;
    T2CONbits.ON = 1;
    
    while(1)
    {
        // egyéb kódrészlet
        LATD = TMR2;
    }
}

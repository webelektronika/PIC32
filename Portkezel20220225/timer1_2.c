#include <p32xxxx.h>
#include "panel.h"


main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // Timer1
    T1CONbits.TGATE = 0;
    T1CONbits.TCS = 0;
    
    T1CONbits.TCKPS = 2;
    PR1 = 0x1234;
    
    T1CONbits.ON = 1;
    
    while(1)
    {
        // egyéb kód
        if(TMR1 <= PR1/2)
        {
            LATDbits.LATD0 = 1;
        }
        else
            LATDbits.LATD0 = 0;
        // egyéb kód
    }
}
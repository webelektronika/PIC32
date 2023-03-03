// Timer1 időzítőként
#include <p32xxxx.h>
#include "panel.h"

main()
{
    // konfig
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // T1 konfig
    T1CONbits.TGATE = 0;
    T1CONbits.TCS = 0;
    T1CONbits.TCKPS = 2;
    PR1 = 0x1234;
    T1CONbits.ON = 1;
    
    while(1)
    {
        if(TMR1 < PR1/2)   
        {
            LEDD0_ON();
        }
        else
        {
            LEDD0_OFF();
        }
    }
    
}

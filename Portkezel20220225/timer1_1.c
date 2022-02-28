#include <p32xxxx.h>
#include "panel.h"
#include "szignatura.h"


main()
{
    TRISD = 0x0000;
    
    // Timer1
    T1CONbits.TGATE = 0;
    T1CONbits.TCS = 0;
    
    T1CONbits.TCKPS = 2;
    PR1 = 0x1234;
    
    T1CONbits.ON = 1;
    
    while(1)
    {
        // egyéb kód
        if(IFS0bits.T1IF)
        {
            LEDsInc();
            IFS0bits.T1IF = 0;
        }
        // egyéb kód
    }
}
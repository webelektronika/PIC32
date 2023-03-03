// Timer1 időítőmódként
#include <p32xxxx.h>
#include "panel.h"

main()
{
    // konfig
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // T1 konfig
    T1CON = 0x0020;
    PR1 = 0x1234;
    T1CONbits.ON = 1;
    
    while(1)
    {
        if(IFS0bits.T1IF)
        {
            IFS0bits.T1IF = 0;
            //LATD++;
            LEDD_INC();
        }    
    }
}

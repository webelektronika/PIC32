// Timer1 számlálóként
// A tesztpanelen nem került implementálásra az RC14-es port 
#include <p32xxxx.h>
#include "panel.h"

main()
{
    //TRISAbits.TRISA1 = 1;
    
    // T1CK/RC14
    TRISCbits.TRISC14 = 1;
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // T1 számláló
    T1CONbits.TCS = 1;
    T1CONbits.TGATE = 0;
    
    // 1:1 osztás
    T1CONbits.TCKPS = 0;
    PR1 = 0xFFFF;
    TMR1 = 0x0000;
    T1CONbits.ON = 1;
    
    while(1)
    {
        /*
        while(!PORTAbits.RA1);
        while(PORTAbits.RA1);
        LATD++;
        */
        
        LATD = TMR1;
    }
}

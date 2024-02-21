#include <xc.h>


main()
{
    TRISB = 0x0000;
    LATB = 0x0000;
    
    if(RCONbits.POR)
    {
        LATBbits.LATB0 = 1;
        RCONbits.POR = 0;
    }

    if(RCONbits.BOR)
    {
        LATBbits.LATB1 = 1;
        RCONbits.BOR = 0;
    }

        if(RCONbits.EXTR)
    {
        LATBbits.LATB2 = 1;
        RCONbits.EXTR = 0;
    }
    
    while(1)
    {
        
    }
}

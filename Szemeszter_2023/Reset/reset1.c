#include <xc.h>

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    
    if(RCONbits.EXTR)
    {
        RCONbits.EXTR = 0;
        LATDbits.LATD0 = 1;
    }
    if(RCONbits.SWR)
    {
        RCONbits.SWR = 0;
        LATDbits.LATD1 = 1;
    }
    if(RCONbits.WDTO)
    {
        RCONbits.WDTO = 0;
        LATDbits.LATD2 = 1;
    }
    if(RCONbits.BOR)
    {
        RCONbits.BOR = 0;
        LATDbits.LATD3 = 1;
    }
    if(RCONbits.POR)
    {
        RCONbits.POR = 0;
        LATDbits.LATD4 = 1;
    }
    
    
    while(1);
}

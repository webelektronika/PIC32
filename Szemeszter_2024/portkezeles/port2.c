#include <p32xxxx.h>

main()
{
    //TRISC = 0xFFFF;
    TRISCbits.TRISC1 = 1;
    TRISD = 0x0000;
    
    while(1)
    {
        if(PORTCbits.RC1)
        {
            LATD = 0xFFFF;
        }
        else
            LATD = 0x0000;
    }  
}

#include <p32xxxx.h>

#define     BTN PORTAbits.RA1

void main()
{
    // A.1 bemenet
    //TRISA = 0xFFFF;
    TRISAbits.TRISA1 = 1;
    
    TRISD = 0x0000;
    
    while(1)
    {
        if(BTN)
            LATD = 0xAAAA;
        else
            LATD = 0x5555;
    }
}
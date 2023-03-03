#include <p32xxxx.h>
int gA;

main()
{
    int a;
    TRISA = 0x0000;
    //TRISB = 0x0002;
    TRISBbits.TRISB1 = 1;
    TRISD = 0x0000;
    LATD = 0xAAAA;   // 1010 1010 1010 1010
    
    while(1)
    {
        if (PORTBbits.RB1)
            LATD = 0xAAAA;
        else
            LATD = 0x5555;
    }
}
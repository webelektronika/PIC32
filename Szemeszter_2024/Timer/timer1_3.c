#include <p32xxxx.h>

#define LEDD0       LATDbits.LATD0
#define LEDD0TG()   { LEDD0 = ~LEDD0; }
#define T1ON()      { T1CONbits.ON = 1; }


main()
{
    TRISD = 0x0000;
    
    // Timer1 beállítása
    T1CONbits.TGATE = 0;
    T1CONbits.TCS = 0;
    T1CONbits.TCKPS = 1;
    
    PR1 = 0x01234;
    T1ON();
    
    while(1)
    {
        // egyéb kód
        
        if(IFS0bits.T1IF)
        {
            LEDD0TG();
            IFS0bits.T1IF = 0;
        }
        
        // egyéb kódrészlet
        
    }
}

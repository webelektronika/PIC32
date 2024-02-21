#include <p32xxxx.h>

#define LEDD0       LATDbits.LATD0
#define LEDD0TG()   { LEDD0 = ~LEDD0; }
#define T1ON()      { T1CONbits.ON = 1; }

void timer1Config(unsigned int config, unsigned int hatar)
{
    T1CON = config;
    PR1 = hatar;
}

main()
{
    int const szerda = 0x1234;
    TRISD = 0x0000;
    
    timer1Config(0x0020, szerda);
    
    T1ON();
    
    while(1)
    {
        // egyéb kód
        
        if(TMR1 < szerda / 2)
            LATDbits.LATD0 = 1;
        else
            LATDbits.LATD0 = 0;
        
        
        // egyéb kódrészlet
        
    }
}

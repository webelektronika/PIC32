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
    TRISD = 0x0000;
    
    timer1Config(0x0020, 0x1234);
    
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

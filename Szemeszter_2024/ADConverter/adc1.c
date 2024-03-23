#include <xc.h>

#define     ADOn()  { AD1CON1bits.ON = 1; }

//szignatúrák
void AD_Konfig();
int AD_Eredmeny();

main()
{
    // port kongig
    TRISD = 0x0000;
    
    // AD konfig
    AD_Konfig();
    ADOn();
    
    while(1)
    {
        LATD = AD_Eredmeny();
    }
    
}

// AD s.függvények
void AD_Konfig()
{
    AD1CON1 = 0x00E0;
    AD1CON2 = 0x0000;
    AD1CON3 = 0x1F3F;
    AD1CSSL = 0x0000;
    AD1PCFG = 0xFFFE;       // 1111... 1110
    AD1CHSbits.CH0SA = 0;
}

int AD_Eredmeny()
{
    AD1CON1bits.SAMP = 1;
    while(!AD1CON1bits.DONE);
    return ADC1BUF0;
}

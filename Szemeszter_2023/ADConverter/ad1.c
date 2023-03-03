#include <xc.h>

#define     AD_On() { AD1CON1bits.ON = 1; }

void ADConfig()
{
    AD1CON1 = 0x00E0;
    AD1CON2 = 0x0000;
    AD1CON3 = 0x1F3F;
    AD1CSSL = 0x0000;
    AD1PCFG = 0xFFFE;
    AD1CHSbits.CH0SA = 0;
}

int ADEredmeny()
{
    AD1CON1bits.SAMP = 1;
    while(!AD1CON1bits.DONE);
    return ADC1BUF0;
} 

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    ADConfig();
    AD_On();
    
    while(1)
    {
        LATD = ADEredmeny();
    }
}

#include <xc.h>

void ADConfig()
{
    AD1PCFG = 0xFFFE;
    AD1CON1 = 0x00E0;
    AD1CSSL = 0x0000;
    AD1CON2 = 0x0000;
    AD1CON3 = 0x1F3F;
    AD1CON1SET = 0x8000;
}

int ADEredmeny()
{
    AD1CON1bits.DONE = 0;
    AD1CHSbits.CH0SA = 0;
    AD1CON1bits.SAMP = 1;
    while(!AD1CON1bits.DONE);
    return ADC1BUF0;
} 

main()
{
    TRISBbits.TRISB0 = 1;
    TRISD = 0x0000;
    LATD = 0x0000;
    ADConfig();
    
    while(1)
    {
        LATD = ADEredmeny();
    }
}

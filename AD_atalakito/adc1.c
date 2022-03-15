#include <xc.h>

#define AD_On()     { AD1CON1bits.ON = 1; }

void ADBeallitas(unsigned int csatorna);
int olvasAD();

int main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // AD beállítása
    ADBeallitas(0);
    AD_On();
    
    while(1)
    {
        LATD = olvasAD();
    }
}

void ADBeallitas(unsigned int csatorna)
{
    AD1CON1 = 0x00E0;
    AD1CON2 = 0x0000;
    AD1CON3 = 0x1FFF;
    AD1CHSbits.CH0SA = csatorna;
    AD1CSSL = 0x0000;
    AD1PCFG = 0xFFFE;
}


int olvasAD()
{
    while(!AD1CON1bits.DONE);
    // várakozunk az AD konverzió végéig
    return ADC1BUF0;
}

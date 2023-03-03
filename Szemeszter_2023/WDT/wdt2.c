#include <xc.h>

#pragma config FWDTEN = ON, WDTPS = PS2048

// A WDT_Clr() makró segítségével lehet törölni a WDT számláló értékét.
#define WDT_Clr()   { WDTCONbits.WDTCLR = 1; WDTCONbits.WDTCLR = 0; }

void Keses(unsigned int szerda)
{
    int k;
    for(k = 0; k < szerda; k++);
}

main()
{
    TRISB = 0x0000;
    TRISD = 0x0000;
    LATB = 0x0000;
    LATD = 0x0000;
    
    if(RCONbits.EXTR)
    {
        RCONbits.EXTR = 0;
        LATBbits.LATB0 = 1;
    }
    
    if(RCONbits.WDTO)
    {
        RCONbits.WDTO = 0;
        LATBbits.LATB3 = 1;
    }
  
    Keses(10000);
    
    LATD = 0xffff;
    while(1)
    {
        // egyéb kód
        
        // WDT törlés
        WDT_Clr();
        // egyéb kódrészlet
    }
}

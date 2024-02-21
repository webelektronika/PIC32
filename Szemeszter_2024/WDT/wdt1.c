#include <xc.h>

// engedélyezzük a WDT-t úgy, hogy kb 1 s-ként 
// resetelje a uC-t, ha a számlálót közben
// nem nullázzuk
#pragma config  FWDTEN = ON, WDTPS = PS1024

void Keses(unsigned int b);
void WDTTorol();

main()
{
    // A B porton figyeljük azt, hogy 
    // a WDT reseteli-e a mikrovezérlőt
    TRISB = 0x0000;
    
    // A D port 0. bitjén lesz az RCON 
    // regiszter WDTO flag-je, amely 
    // jelzi, ha a WDT resetelte a uC-t
    TRISD = 0x0000;
    LATB = 0x0000;
    LATD = 0x0000;
    
    // szoftveresen kell nullázni a flag-et!!!
    if(RCONbits.WDTO)
    {
        LATDbits.LATD0 = 1;
        RCONbits.WDTO = 0;
    }
    
    Keses(10000);
    
    LATB = 0xFFFF;
    
    while(1)
    {
        Keses(200000);
        // egyéb kód
        WDTTorol();
        
        // egyéb kódrészlet
        // WDTTorol();
    }
}

void Keses(unsigned int b)
{
    int k;
    for(k = 0; k < b; k++);
}

// ezzel a függvénnyel töröljük a WDT belső, 25 bites 
// számlálóját, hogy ne legyen normális működés közben 
// reset folyamat
void WDTTorol()
{
    WDTCONbits.WDTCLR = 1;
    WDTCONbits.WDTCLR = 0;
}

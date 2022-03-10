#pragma config FWDTEN = ON, WDTPS = PS1024

#define WDT_Clr()   { WDTCONbits.WDTCLR=1; WDTCONbits.WDTCLR=0; }

void Keses(unsigned int hatar);

main()
{
    TRISB = 0x0000;
    LATB = 0x0000;
    
    Keses(10000);
    
    LATB = 0xFFFF;
    
    while(1)
    {
        // egyéb művelet
      
        // ezzel a makróval töröljük a WDT-t
        WDT_Clr();
        // egyéb művelet
    }
}

void Keses(unsigned int hatar)
{
    int k;
    for(k = 0; k < hatar; k++);
}

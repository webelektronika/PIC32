#include <xc.h>

// SYSCLK = 10 MHz, PBCLK = 5 MHz
#pragma config  FNOSC = FRCPLL, POSCMOD = OFF, FSOSCEN = OFF
#pragma config  FPLLMUL = MUL_20, FPLLIDIV = DIV_4, FPLLODIV = DIV_4
#pragma config  FPBDIV = DIV_2

// WDT beállítása
#pragma config  FWDTEN = ON, WDTPS = PS1024

void resetFigyel();
void WDTTorol();

main()
{
    TRISB = 0x0000;
    LATB = 0x0000;
    
    resetFigyel();
    
    while(1)
    {
        // egyéb kódrészlet
        
        WDTTorol();
    }
}

void resetFigyel()
{
    if(RCONbits.POR)
    {
        LATBbits.LATB0 = 1;
        RCONbits.POR = 0;
    }
    
    if(RCONbits.BOR)
    {
        LATBbits.LATB1 = 1;
        RCONbits.BOR = 0;
    }
    
    if(RCONbits.EXTR)
    {
        LATBbits.LATB2 = 1;
        RCONbits.EXTR = 0;
    }
    
    if(RCONbits.WDTO)
    {
        LATBbits.LATB3 = 1;
        RCONbits.WDTO = 0;
    }
}

void WDTTorol()
{
    WDTCONbits.WDTCLR = 1;
    WDTCONbits.WDTCLR = 0;
}

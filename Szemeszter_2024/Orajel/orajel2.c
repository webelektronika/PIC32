#include <xc.h>

// SYSCLK = 10MHz, PBCLK = 2.5MHz
#pragma config  FNOSC = FRCPLL, FSOSCEN = OFF, POSCMOD = OFF

// PLL beállítása
#pragma config  FPLLMUL = MUL_20, FPLLIDIV = DIV_4, FPLLODIV = DIV_4

// PBCLK
#pragma config  FPBDIV = DIV_4

main()
{
    // konfig
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // T1 időzítő
    T1CON = 0x0000;
    PR1 = 0x1234;
    
    T1CONbits.TCKPS = 1;
    T1CONbits.ON = 1;
    
    while(1)
    {
        if(IFS0bits.T1IF)
        {
            LATD++;
            IFS0bits.T1IF = 0;
        }
    }   
}

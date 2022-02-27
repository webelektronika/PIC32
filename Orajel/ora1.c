#include <p32xxxx.h>

// SYSCLK = 8MHz, PBCLK = 1MHz

#pragma config FNOSC = FRC, FSOSCEN = OFF, POSCMOD = OFF
#pragma config FPBDIV = DIV_8

#define     LED1        LATDbits.LATD1
#define     LED1_TR     TRISDbits.TRISD1
#define     LED1_Tg()   { LED1 = ~LED1; }


void main()
{
    LED1_TR = 0;
    
    // elosztó: 1/64
    // időzítő mód
    T1CON = 0x0020;
    PR1 = 0x1234;
    T1CONbits.ON = 1;
    
    while(1)
    {
        if(IFS0bits.T1IF)
        {
            LED1_Tg();
            IFS0bits.T1IF = 0;
        }
    }
}

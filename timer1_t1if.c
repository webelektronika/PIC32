#include <p32xxxx.h>

#define     LED1        LATDbits.LATD1
#define     LED1_TR     TRISDbits.TRISD1
#define     LED1_Tg()   { LED1 = ~LED1; }


void main()
{
    LED1_TR = 0;
    
    // el?osztó: 1/64
    // id?zít? mód
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


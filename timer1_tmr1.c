#include <p32xxxx.h>

#define     LED1        LATDbits.LATD1
#define     LED1_TR     TRISDbits.TRISD1
#define     LED1_Tg()   { LED1 = ~LED1; }
#define     LED1On()    { LED1 = 1; }
#define     LED1Off()   { LED1 = 0; }


void main()
{
    LED1_TR = 0;
    
    // elosztó: 1/64
    // id?zít? mód
    T1CON = 0x0020;
    PR1 = 0x1234;
    T1CONbits.ON = 1;
    
    while(1)
    {
        if(TMR1 <= PR1/2)
        {
            LED1On();
        }
        else
        {
            LED1Off();
        }

    }
}
#include <p32xxxx.h>
#include <sys/attribs.h>

#define     T1On()      { T1CONbits.ON = 1; }
#define     LED0Tg()    { LATDbits.LATD0 = ~LATDbits.LATD0; }

void __ISR(0, ipl1) ITCsutortok(void)
{
    if(IFS0bits.T1IF)
    {
        LED0Tg();
        IFS0bits.T1IF = 0;
    }
    
}

main()
{
    // port konfig
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // Timer1 konfig
    T1CON = 0x0020;
    PR1 = 0x1234;
    
    // T1 Int konfig
    IEC0bits.T1IE = 1;
    IPC1bits.T1IP = 1;
    IPC1bits.T1IS = 2;
    
    // uC Int konfig, Single
    INTCONbits.MVEC = 0;
    
    // Engedélyezések
    asm volatile("ei");
    T1On();
    
    while(1);
}

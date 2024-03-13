#include <xc.h>
#include <sys/attribs.h>

#define     T1ON()  { T1CONbits.ON = 1; }
#define     T2ON()  { T2CONbits.ON = 1; }

void __ISR(0, ipl1) ITPelda(void)
{
    if(IFS0bits.T1IF)
    {
        IFS0bits.T1IF = 0;
        LATD++;
    }
    
    if(IFS0bits.T2IF)
    {
        IFS0bits.T2IF = 0;
        LATD--;
    }
}



main()
{
    // port konfig
    TRISD = 0x0000;
    
    // Timer1 konfig
    T1CON = 0x0020;
    PR1 = 0x1234;

    // Timer2 konfig
    T2CON = 0x0050;
    PR2 = 0x1234;
    
    // INT T1 konfig
    IEC0bits.T1IE = 1;
    IPC1bits.T1IP = 1;
    IPC1bits.T1IS = 2;
    
    // INT T2 konfig
    IEC0bits.T2IE = 1;
    IPC2bits.T2IP = 2;
    IPC2bits.T2IS = 2;
    
    // INT konfig
    INTCONbits.MVEC = 0;  // Single
    
    // Engedélyezés
    T1ON();
    T2ON();
    asm volatile("ei");
    
    while(1);
}

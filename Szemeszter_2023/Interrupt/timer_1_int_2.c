// Timer1 interrupt kérést adhat, a Timer2 pollingolással kerül vizsgálatra.

#include <p32xxxx.h>
#include "sys/attribs.h"

#define int_multi()         { INTCONbits.MVEC = 1 ; }
#define int_single()        { INTCONbits.MVEC = 0 ; }

#define t1_int_enable()     { IEC0bits.T1IE = 1; }
#define t1_intFlag_clear()  { IFS0bits.T1IF = 0; }
#define t1_ON()             { T1CONbits.ON = 1; }
#define t2_ON()             { T2CONbits.ON = 1; }

void __ISR(0, ipl1) ITFgv(void)
{
    if(IFS0bits.T1IF)
    {
        t1_intFlag_clear();
        LATD++;
    }
}

void T1_Config(unsigned char oszto, unsigned int hatar)
{
    T1CONbits.TCS = 0;
    T1CONbits.TGATE = 0;
    T1CONbits.TCKPS = oszto;
    PR1 = hatar;
    TMR1 = 0x0000;
}

void T2_Config(unsigned char oszto, unsigned int hatar)
{
    T2CONbits.TCS = 0;
    T2CONbits.TGATE = 0;
    T2CONbits.T32 = 0;
    T2CONbits.TCKPS = oszto;
    PR2 = hatar;
    TMR2 = 0x0000;
}

void T1_Int_Config()
{
    t1_intFlag_clear();
    IPC1bits.T1IP = 1;
    IPC1bits.T1IS = 2;
    t1_int_enable();
}

main()
{
    TRISB = 0x0000;
    LATB = 0x0000;
    TRISD = 0x0000;
    LATD = 0x0000;
    T1_Config(0x0002, 0x1234);
    T2_Config(0x0005, 0x1234);

    T1_Int_Config();
    
    int_single();
    asm volatile("ei");
    t1_ON();
    t2_ON();
    
    while(1)
    {
        if(IFS0bits.T2IF)
        {
            IFS0bits.T2IF = 0;
            LATB++;
        }
    }
}

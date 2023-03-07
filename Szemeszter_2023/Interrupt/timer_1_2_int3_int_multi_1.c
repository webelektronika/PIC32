// Timer1 és a Timer2 időzítő.
// INT3 (RA14) lábon történő 0 -> 1 átmeneteket számoljuk,
// az eredmény a LATB porton kerül megjelenítésre.

#include <p32xxxx.h>
#include "sys/attribs.h"

// INT3/RA14

#define int_multi()         { INTCONbits.MVEC = 1 ; }
#define int_single()        { INTCONbits.MVEC = 0 ; }

#define LEDD0_TG()          { LATDbits.LATD0 = ~LATDbits.LATD0; }
#define LEDD1_TG()          { LATDbits.LATD1 = ~LATDbits.LATD1; }

#define t1_int_enable()     { IEC0bits.T1IE = 1; }
#define t1_intFlag_clear()  { IFS0bits.T1IF = 0; }
#define t1_ON()             { T1CONbits.ON = 1; }
#define t2_ON()             { T2CONbits.ON = 1; }

void __ISR (_TIMER_1_VECTOR, IPL1SRS) IntT1(void)
{
    t1_intFlag_clear();
    LEDD0_TG();
}

void __ISR (_TIMER_2_VECTOR, IPL1SRS) IntT2(void)
{
    IFS0bits.T2IF = 0;
    LEDD1_TG();
}

void __ISR (_EXTERNAL_3_VECTOR, IPL1SRS) IntINT3(void)
{
    IFS0bits.INT3IF = 0;
    LATB++;
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

void T2_Int_Config()
{
    IFS0bits.T2IF = 0;
    IPC2bits.T2IP = 1;
    IPC2bits.T2IS = 2;
    IEC0bits.T2IE = 1;
}

void INT3_Int_Config()
{
    IFS0bits.INT3IF = 0;
    IPC3bits.INT3IP = 1;
    IPC3bits.INT3IS = 2;
    IEC0bits.INT3IE = 1;
}

main()
{
    TRISAbits.TRISA14 = 1;
    TRISB = 0x0000;
    LATB = 0x0000;
    TRISD = 0x0000;
    LATD = 0x0000;
    T1_Config(0x0002, 0x1234);
    T2_Config(0x0005, 0x1234);

    T1_Int_Config();
    T2_Int_Config();
    INT3_Int_Config();
    
    int_multi();
    asm volatile("ei");
    t1_ON();
    t2_ON();
    
    while(1)
    {
        
    }
}

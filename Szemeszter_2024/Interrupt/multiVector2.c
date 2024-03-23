#include <xc.h>
#include <sys/attribs.h>

#define     T1On()      { T1CONbits.ON = 1; }
#define     T2On()      { T2CONbits.ON = 1; }

// RA14: int3, RA15: int4

void timer1Config(unsigned int hatar, unsigned int oszto);
void intTimer1Config(unsigned int prior, unsigned int sprior);
void timer2Config(unsigned int hatar, unsigned int oszto);
void intTimer2Config(unsigned int prior, unsigned int sprior);
void intExt3Config(unsigned int prior, unsigned int sprior);

void __ISR(_TIMER_1_VECTOR, IPL1SRS) T1Csutortok()
{
    LATD++;
    IFS0bits.T1IF = 0;
}

// 00000000 00000000 00000000 00000001
void __ISR(_TIMER_2_VECTOR, IPL1SRS) T2Csutortok()
{
    if (LATB <= 0x40)
        LATB *= 2;
    else
        LATB = 0x0001;
    IFS0bits.T2IF = 0;
}

void __ISR(_EXTERNAL_3_VECTOR, IPL1SRS) Ext3Csutortok()
{
    // valami művelet
    IFS0bits.INT3IF = 0;
}

main()
{
    // port konfig, B, D kimenetek
    TRISAbits.TRISA14 = 1;
    TRISB = 0x0000;
    TRISD = 0x0000;
    LATB = 0x0001;
    LATD = 0x0000;
    
    // Timer1, Timer2 konfig
    timer1Config(0x1234, 3);
    timer2Config(0x1234, 5);
    
    // Timer1, Timer2 INT konfig
    intTimer1Config(1, 2);
    intTimer2Config(1, 3);
    
    // INT konfig
    INTCONbits.MVEC = 1;
    
    // Engedélyezések
    asm volatile("ei");
    T1On();
    T2On();
    
    while(1)
    {
        // egyéb kódrészlet
    }
}

void timer1Config(unsigned int hatar, unsigned int oszto)
{
    T1CON = 0x0000;
    T1CONbits.TCKPS = oszto;
    PR1 = hatar;
}

void timer2Config(unsigned int hatar, unsigned int oszto)
{
    T2CON = 0x0000;
    T2CONbits.TCKPS = oszto;
    PR2 = hatar;
}

void intTimer1Config(unsigned int prior, unsigned int sprior)
{
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    IPC1bits.T1IP = prior;
    IPC1bits.T1IS = sprior;
}

void intTimer2Config(unsigned int prior, unsigned int sprior)
{
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 1;
    IPC2bits.T2IP = prior;
    IPC2bits.T2IS = sprior;
}

void intExt3Config(unsigned int prior, unsigned int sprior)
{
    IFS0bits.INT3IF = 0;
    IEC0bits.INT3IE = 1;
    IPC3bits.INT3IP = prior;
    IPC3bits.INT3IS = sprior;
}

// Csak a Timer1 belső periféria adhat megszakításkérést.
// Single mód, az INTCON regiszterben lévő MVEC értéke 0.
// Signle mód, minden IT kérést egy IT függvény "kezel le".

#include <p32xxxx.h>
#include "sys/attribs.h"

#define int_multi()         { INTCONbits.MVEC = 1 ; }
#define int_single()        { INTCONbits.MVEC = 0 ; }

#define t1_int_enable()     { IEC0bits.T1IE = 1; }
#define t1_intFlag_clear()  { IFS0bits.T1IF = 0; }
#define t1_ON()             { T1CONbits.ON = 1; }

// IT függvény
void __ISR(0, ipl1) ITFgv(void)
{
    if(IFS0bits.T1IF)
    {
        t1_intFlag_clear();
        LATD++;
    }
}

// Timer1 időzítómód
void T1_Config(unsigned char oszto, unsigned int hatar)
{
    T1CONbits.TCS = 0;
    T1CONbits.TGATE = 0;
    T1CONbits.TCKPS = oszto;
    PR1 = hatar;
    TMR1 = 0x0000;
}

// Timer1 interrupt beállítása
void T1_Int_Config()
{
    t1_intFlag_clear();
    IPC1bits.T1IP = 1;
    IPC1bits.T1IS = 2;
    t1_int_enable();
}

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    T1_Config(0x0002, 0x1234);
    T1_Int_Config();
    
    int_single();
    asm volatile("ei");
    t1_ON();
    
    while(1)
    {
        
    }
}

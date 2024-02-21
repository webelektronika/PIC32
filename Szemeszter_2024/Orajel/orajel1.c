#include <xc.h>

// SYSCLK = 32MHz, PBCLK = 16MHz
#pragma config POSCMOD = OFF, FSOSCEN = OFF, FNOSC = FRCPLL
#pragma config FPLLIDIV = DIV_5, FPLLMUL = MUL_20, FPLLODIV = DIV_1
#pragma config FPBDIV = DIV_2

#define LEDD0       LATDbits.LATD0
#define LEDD0TG()   { LEDD0 = ~LEDD0; }

void Kesleltetes(unsigned int hatar)
{
    int k;
    for(k = 0; k < hatar; k++);
}

main()
{
    TRISDbits.TRISD0 = 0;
    
    while(1)
    {
        //késleltetés
        Kesleltetes(10000);
        LEDD0TG();
    }
}

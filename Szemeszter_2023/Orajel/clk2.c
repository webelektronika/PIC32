#include <p32xxxx.h>

// FRC PLL, 40MHz, 1:2 PBCLK
#pragma config FNOSC = FRCPLL, FSOSCEN = OFF, POSCMOD = OFF
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_2
#pragma config FPBDIV = DIV_2

#define LEDD0       LATDbits.LATD0
#define LEDD0_TG()  { LEDD0 = ~LEDD0; }

void Villog(unsigned int szerda)
{
    int k;
    for(k = 0; k < szerda; k++);
    LEDD0_TG();
}

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    
    while(1)
        Villog(10000);
}

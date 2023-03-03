#include <p32xxxx.h>

// Belső, LPRC modul (31.25 KHz), 1:4 PBCLK
#pragma config FNOSC = LPRC, POSCMOD = OFF, FSOSCEN = OFF
#pragma config FPBDIV = DIV_4

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

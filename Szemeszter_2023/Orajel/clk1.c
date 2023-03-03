#include <p32xxxx.h>

// FRC (8MHz), 1:1 PBCLK
#pragma config FNOSC = FRC, FSOSCEN = OFF, POSCMOD = OFF
#pragma config FPBDIV = DIV_1

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

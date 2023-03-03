#include <xc.h>

#pragma config FWDTEN = ON, WDTPS = PS2048

void Keses(unsigned int szerda)
{
    int k;
    for(k = 0; k < szerda; k++);
}

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    Keses(10000);
    
    // LATD = 0B1111111111111111;
    LATD = 0xffff;
    while(1);
}

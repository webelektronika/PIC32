#include <p32xxxx.h>

#pragma config FWDTEN = ON, WDTPS = PS1024

void Keses(unsigned int hatar);

main()
{
    TRISB = 0x0000;
    LATB = 0x0000;
    
    Keses(10000);
    
    LATB = 0xFFFF;
    
    while(1);
}

void Keses(unsigned int hatar)
{
    int k;
    for(k = 0; k < hatar; k++);
}
#include <p32xxxx.h>

#define     LED1    LATDbits.LATD1
#define     LED1_TR TRISDbits.TRISD1

void keses(unsigned int hatar);

void main()
{
    LED1_TR = 0;
    
    while(1)
    {
        LED1 = 1;
        keses(1000);
        
        LED1 = 0;
        keses(1000);
    }
}

void keses(unsigned int hatar)
{
    int k;
    for(k= 0; k < hatar; k++);
}
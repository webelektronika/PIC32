#include <p32xxxx.h>

#define     LED1    LATDbits.LATD1
#define     LED1_TR TRISDbits.TRISD1

void main()
{
    int k;
    LED1_TR = 0;
    
    while(1)
    {
        LED1 = 1;
        for(k= 0; k < 1000; k++);
        
        LED1 = 0;
        for(k= 0; k < 1000; k++);
    }
}
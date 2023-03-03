#include <p32xxxx.h>
int gA;

main()
{
    int a;
    TRISA = 0x0000;
    
    TRISD = 0x0000;
    LATD = 0xAAAA;   // 1010 1010 1010 1010
    
    while(1);
}

#include <p32xxxx.h>

// PIC32MX795F512L

void main()
{
    //TRISD = 0B0000 0000 0000 0000;
    TRISD = 0x0000;
    
    LATD = 0x1234;
    
    while(1);
}
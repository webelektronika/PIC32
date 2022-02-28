#include <p32xxxx.h>

main()
{
    TRISD = 0x0000;
    LATD = 0xFFFF;
    
    while(1);
}

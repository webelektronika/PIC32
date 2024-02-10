#include <p32xxxx.h>
#include "panel.h"
#include "fgvs.h"

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;  // ?
    
    while(1)
    {
        Keses(10000);
        LEDsInc();
    }
}

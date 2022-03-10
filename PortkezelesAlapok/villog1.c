#include <p32xxxx.h>
#include "panel.h"
#include "egyeb.h"

main()
{
    TRISD = 0x0000;
    LATD = 0x0000;
    
    while(1)
    {
        LED_D0_TG();
        keses(10000);        
    }
}

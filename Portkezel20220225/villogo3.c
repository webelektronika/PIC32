#include <p32xxxx.h>
#include "panel.h"
#include "szignatura.h"

// sz�moljunk a D porton

main()
{
    TRISD = 0x0000;
    
    while(1)
    {
        LEDsInc();
        keses(10000);
    }
}

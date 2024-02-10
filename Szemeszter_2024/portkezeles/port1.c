#include <p32xxxx.h>

main()
{
    // decimálisan is adható a portregisztereknek érték
    TRISA = 123;

    // bináris értékadás
    //TRISD = 0B1111111100000000;

    // hexa formátum
    TRISD = 0xFF00;

    // ez nem használható, a "D" port felső 8 bitje bemenet
    //LATD = 0x0001;

    // csak a "D0" kap értéket
    LATDbits.LATD0 = 1;
    
    while(1);
}

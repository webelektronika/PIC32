#include <xc.h>

typedef unsigned char byte;
typedef unsigned int Szechenyi;

union
{
    struct
    {
        unsigned cs0:1;
        unsigned cs1:1;
        unsigned cs2:1;
        unsigned cs3:1;
        unsigned cs4:1;
        unsigned cs5:1;
        unsigned cs6:1;
        unsigned cs7:1;
    } Bit;
    unsigned char Byte;
} Erzekelo;

main()
{
    int a = 10, b = 3;
    char ch;
    unsigned char ch2;
    //unsigned char b;
    byte b2;
    Szechenyi qwerty;
    
    int e = a/b;    // 3
    float f = a/b;  // 3.0
    float f2 = (float)a/b; // 3.3333
    
    Erzekelo.Bit.cs1 = 1;
    Erzekelo.Byte = 0x12;
    while(1);
}

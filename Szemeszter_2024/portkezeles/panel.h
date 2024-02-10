#define LEDs        LATD
#define LEDsOn()    { LEDs = 0xFFFF; }
#define LEDsInc()   { LEDs++; }

#define LEDD0       LATDbits.LATD0
#define LEDD0_ON()  { LEDD0 = 1; }
#define LEDD0_OFF() { LEDD0 = 0; }
#define LEDD0_TG()  { LEDD0 = ~LEDD0; }
#define LEDD_INC()  { LATD++; }

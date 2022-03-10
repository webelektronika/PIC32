
#define LED_D0      LATDbits.LATD0
#define LED_D0_TG() { LED_D0 = ~LED_D0; }
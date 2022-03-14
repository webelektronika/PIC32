#include <xc.h>

int g_pelda;

void fgv()
{
    
}

void inc()
{
    g_pelda++;
    fgv();
}

int main()
{
    int k;
    TRISC = 0x0000;
    TRISD = 0x0000;
    LATC = 0xFFFF;
    LATD = 0x0000;
    
    for(k = 0; k < 5; k++)
    {
        LATC--;
    }
    
    while(1)
    {
        inc();
        LATD = g_pelda;
    }
}

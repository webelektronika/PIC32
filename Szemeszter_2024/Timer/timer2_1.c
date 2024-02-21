#include <xc.h>

// A panel kialakítása miatt a Timer2 belső 
// periféria kerül felhasználásra. A T1CK/RC14 
// láb nem került kivezetésre a panelon, ezért 
// a Timer2-t alkalmaztuk számláló módban (T2CK/RC1).

main()
{
    // T2CK/RC1
    TRISCbits.TRISC1 = 1;
    
    TRISD = 0x0000;
    LATD = 0x0000;
    
    // Timer2 -> számláló
    T2CON = 0x0082;
    PR2 = 0xFFFF;
    
    // T2 Engedélyezése
    T2CONbits.ON = 1;
    
    while(1)
    {
        // egyéb kódrészlet
        
        LATD = TMR2;
        
        // egyéb kódrészlet
        
    }
}


// rect signal with 4MHz
/*
    Ich erwarte, dass f_cy halb so groß ist, wie die 4MHz des primären Oszillators, also ist 
    t_cy = 1/f_cy = 1/40MHz = 25ns
    t_Abtast = 1/f_Abtast = 1/4kHz = 250us
    PR3 = t_Abtast/t_cy - 1 = 250us/25ns - 1 = 9999
*/


#include <xc.h>


#include <stdio.h>
#include <stdlib.h>
#include "xc.h"
#include "p33FJ128GP802.h"
#include "config.h"

/*
 * 
 */
int main(int argc, char** argv) {

    // RB15 is output
    TRISBbits.TRISB15 = 0;
    while(1) {
        PORTBbits.RB15 = 0;
        PORTBbits.RB15 = 1;
    }
    return (EXIT_SUCCESS);
}

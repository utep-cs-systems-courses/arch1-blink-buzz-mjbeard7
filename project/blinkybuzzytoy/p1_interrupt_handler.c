#include <msp430.h>
#include "switches.h"

/* Switch on P1 (S2) */
/*void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
//    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
// switch_interrupt_handler();	/* single handler for all switches */
//  }
//}
//switch on P2 (S1 - S4)
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

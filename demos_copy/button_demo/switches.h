#ifndef switches_included
#define switches_included
		
#define S1 BIT0 /* switch1 is p2.0 */
#define S2 BIT1 // switch2 is p2.1
#define S3 BIT2 // switch2 is p2.2
#define S4 BIT3 // switch2 is p2.3

#define SWITCHES  S1, S2, S3, S4		/* only 4 switches on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down_s1,switch_state_down_s2, switch_state_down_s3, switch_state_down_s4 , switch_state_changed; /* effectively boolean */

#endif // included

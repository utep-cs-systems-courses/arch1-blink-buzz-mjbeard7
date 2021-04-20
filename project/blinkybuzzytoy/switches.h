#ifndef switches_included
#define switches_included
		
#define S1 BIT2 /* switch1 is p2.3 */

#define SWITCHES S1//, S2, S3, S4		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included

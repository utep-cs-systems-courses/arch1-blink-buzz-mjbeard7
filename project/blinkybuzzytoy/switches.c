#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense()
{
  // char p1val = P1IN;
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  // P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  // P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  P2IES |= (p2val & SWITCHES);	
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  // P1REN |= SWITCHES;		/* enables resistors for switches */
  // P1IE |= SWITCHES;		/* enable interrupts from switches */
  // P1OUT |= SWITCHES;		/* pull-ups for switches */
  // P1DIR &= ~SWITCHES;		/* set switches' bits for input */

  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= SWITCHES;

  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  // char p1val = switch_update_interrupt_sense();
  char p2val = switch_update_interrupt_sense();
  // switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_down = (p2val & S1) ? 0 : 1;
  switch_state_changed = 1;
  led_update();
}

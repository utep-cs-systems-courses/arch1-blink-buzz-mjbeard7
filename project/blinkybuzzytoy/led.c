#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = 0; //by default switches are off

    ledFlags |= switch_state_down_s1 ? LED_RED : 0;
    ledFlags |= switch_state_down_s2 ? LED_GREEN : 0;
    ledFlags |= switch_state_down_s3 ? LEDS : 0;
    ledFlags |= switch_state_down_s4 ?  redVal[red_on] | greenVal[green_on] : 0;
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
}


#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;


  static char state = 0;

  switch(state){
  case 0: red_on = 0; green_on = 0; state++; break;
  case 1: red_on = 1; green_on = 0; state++; break;
  case 2: red_on = 0; green_on = 0; state++; break;
  case 3: red_on = 1; green_on = 0; state++; break;
  case 4: red_on = 0; green_on = 0; state++; break;  
  case 5: red_on = 0; green_on = 1; state++; break;
  case 6: red_on = 0; green_on = 0; state++; break;
  case 7: red_on = 0; green_on = 1; state++; break;
  case 8: red_on = 0; green_on = 0; state++; break;
  case 9: red_on = 1; green_on = 0; state++; break;
  case 10: red_on = 0; green_on = 1; state++; break;
  case 11: red_on = 1; green_on = 1; state++; break;
  default: state = 0;
  }
  
  led_changed = 1;
  led_update();
}
void buzzer_state_advance(){
  static char buzz_state = 0;
  switch(buzz_state) {
  case 0: buzzer_set_period(4049); buzz_state++;break;
  case 1: buzzer_set_period(4545); buzz_state++;break;
  case 2: buzzer_set_period(4049); buzz_state++;break;
  case 3: buzzer_set_period(3405); buzz_state++;break;
  case 4: buzzer_set_period(4049); buzz_state++;break;
  case 5: buzzer_set_period(5405); buzz_state++;break;
  case 6: buzzer_set_period(4545); buzz_state++;break;
    //second measure
  case 7: buzzer_set_period(4049); buzz_state++;break;
  case 8: buzzer_set_period(4545); buzz_state++;break;
  case 9: buzzer_set_period(4049); buzz_state++;break;
  case 10: buzzer_set_period(2863); buzz_state++;break;
  case 11: buzzer_set_period(3034); buzz_state++;break;
  case 12: buzzer_set_period(3405); buzz_state++;break;
  case 13: buzzer_set_period(4545); buzz_state=0;break;
  default: buzz_state = 0;  
  }//end of switch
}//end of buzz state advance

#include "dio_interface.h"
#include "port_config.h"

void PORT_VoidInit() {
  DDRA_REG = PORTA_DIR;
  DDRB_REG = PORTB_DIR;
  DDRC_REG = PORTC_DIR;
  DDRD_REG = PORTD_DIR;
}

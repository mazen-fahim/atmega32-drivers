#ifndef _HKPD_CONFIG_H_
#define _HKPD_CONFIG_H_

#define KPD_PORT PORTA

/*Options:
 * 0 for first pin
 * 1 for second pin
 * 2 for second pin
 * 3 for third pin
 * .
 * .
 * .
 * */
#define KPD_COLUMN0_PIN 0
#define KPD_COLUMN1_PIN 1
#define KPD_COLUMN2_PIN 2
#define KPD_COLUMN3_PIN 3
#define KPD_ROW0_PIN 4
#define KPD_ROW1_PIN 5
#define KPD_ROW2_PIN 6
#define KPD_ROW3_PIN 7

/* this is application dependent in my app 0xff is not used
 * so i use it as an indication that there is no key pressed
 * so choose a number that you don't use*/
#define KPD_NO_PRESSED_KEY 0xff

#define KPD_ARR_VAL {{7,8,9,'*'},{4,5,6,'/'},{1,2,3,'+'},{'m',0,'=','-'}}




#endif

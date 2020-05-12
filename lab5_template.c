/**
 * lab5_template.c
 *
 * Template file for CprE 288 Lab 5
 *
 * @author Diane Rover, 2/15/2020
 *
 */

#include "Timer.h"
#include "lcd.h"
#include "cyBot_Scan.h"  // For scan sensors
#include "uart.h"

// Uncomment or add any include directives that are needed
// #include "open_interface.h"
// #include "movement.h"
// #include "button.h"


#warning "Possible unimplemented functions"
#define REPLACEME 0


int main(void) {
	timer_init(); // Must be called before lcd_init(), which uses timer functions
	lcd_init();
	uart_init();
    cyBOT_init_Scan();

    char data[21];
    int count = 0;

	while(1)
	{

        data[count] = uart_receive();

        if((data[count] == '\r') || count == sizeof(data) - 1){
           data[count] = '\0';
           lcd_printf("%s", data);
           uart_sendChar(data[count]);
          // timer_waitMillis(500);
           memset(data, 0, sizeof(data));

           count = 0;

        }
        else{
           lcd_printf("%d", count + 1);
           uart_sendChar(data[count]);
           count++;
        }


	}

}

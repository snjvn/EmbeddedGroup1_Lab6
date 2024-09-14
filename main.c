
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
/**
 * main.c
 */


int main(void)
{
    SYSCTL_RCGC2_R |= 0x00000020;       /* enable clock to GPIOF */
    SYSCTL_RCGC0_R |= 0x00100000;       /* enable clock to PWM */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;     /* unlock commit register */
    GPIO_PORTF_CR_R = 0x1F;             /* make PORTF configurable */
    GPIO_PORTF_DEN_R = 0x01F;            /* set PORTF pins 4 : 0 pins */
    GPIO_PORTF_DIR_R = 0x0E;            /*  */
    GPIO_PORTF_PUR_R = 0x11;            /* PORTF0 and PORTF4 are pulled up */
    GPIO_PORTF_AFSEL_R = 0x00;


    return 0;
}




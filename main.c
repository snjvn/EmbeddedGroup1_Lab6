
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
/**
 * main.c
 */


int main(void)
{
    SYSCTL_RCGC2_R |= 0x00000020;       /* enable clock to GPIOF */
    SYSCTL_RCGCPWM_R |= 0x02; // enable clock to PWM module 1
    SYSCTL_RCGCTIMER_R = 0x02;
    SYSCTL_RCGCGPIO_R = 0x20;
//    SYSCTL_RCGC0_R |= 0x00100000;       /* enable clock to PWM */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;     /* unlock commit register */
    GPIO_PORTF_CR_R = 0x1F;             /* make PORTF configurable */
    GPIO_PORTF_DEN_R = 0x01F;            /* set PORTF pins 4 : 0 pins */
    GPIO_PORTF_DIR_R = 0x0E;            /*  */
    GPIO_PORTF_PUR_R = 0x11;            /* PORTF0 and PORTF4 are pulled up */

    GPIO_PORTF_AFSEL_R = 0x08;
    GPIO_PORTF_PCTL_R = 0x00007000;
    GPIO_PORTF_DATA_R = 0x04;

    TIMER1_CTL_R = 0x00;
    TIMER1_CFG_R = 0x04;
    TIMER1_TBMR_R = 0x0A;
    TIMER1_CTL_R = 0x4000;
    TIMER1_TBILR_R= 160;
    TIMER1_TBMATCHR_R = 80;
    TIMER1_CTL_R |= 0x0100;
    while(1){;}

    return 0;
}




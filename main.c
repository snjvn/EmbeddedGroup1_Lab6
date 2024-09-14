
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
    GPIO_PORTF_AFSEL_R = 0x08; // configuring the green LED for alternate function - PWM
    GPIO_PORTF_PCTL_R =0x00005000;

    PWM1_CTL_R = 0x00;
    PWM1_3_CTL_R = 0x00; // enable after PWM is fully configured
    PWM1_3_GENB_R = 0x202; // when counter hits zero, drive pwm_out = 0; when counter hits cmpA, drive pwm_out = 1;
    PWM1_3_LOAD_R = 160;
    PWM1_3_CMPB_R = 79; // 79 for 50% duty cycle
    PWM1_3_CMPA_R = 0;
//    PWM1_CTL_R = 0x01;
    PWM1_3_CTL_R = 0x01; // enable
    PWM1_ENABLE_R = 0x80;


    GPIO_PORTF_DATA_R = 0x02;
    return 0;
}




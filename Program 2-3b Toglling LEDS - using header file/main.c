#include <stdint.h>
#include "C:\ti\TivaWare_C_Series-2.1.4.178\inc\tm4c123gh6pm.h"

void delay(int d);
void initialization();
/**
 * main.c
 */
int main(void)
{

    initialization();
    while(1)
    {
        GPIO_PORTF_DATA_R ^= 0x0E;
        delay(100);

    }
    return 0;
}

void delay(int d)
{

   int i,j;
   for(j=0; j < d ; j++)
   {
       for(i=0; i < 10000 ; i++);
   }
}

void initialization()
{
    SYSCTL_RCGCGPIO_R |= 0X00000020; // enable clock port F
    int x = 203;
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_AFSEL_R = 0;
    GPIO_PORTF_DEN_R |= 0x0E;
    GPIO_PORTF_PCTL_R  = 0x00000000;
    GPIO_PORTF_CR_R = 0x0E;
    GPIO_PORTF_AMSEL_R = 0;
}

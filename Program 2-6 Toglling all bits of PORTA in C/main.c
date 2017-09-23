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
        GPIO_PORTA_DATA_R ^= 0xFF;
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
    SYSCTL_RCGCGPIO_R |= 0X00000001; // enable clock port A
    int x = 203; // delay for a moment
    GPIO_PORTA_LOCK_R = 0x4C4F434B;
    GPIO_PORTA_DIR_R |= 0xFF;
    GPIO_PORTA_AFSEL_R = 0;
    GPIO_PORTA_DEN_R |= 0xFF;
    GPIO_PORTA_PCTL_R  = 0x00000000;
    GPIO_PORTA_CR_R = 0xFF;
    GPIO_PORTA_AMSEL_R = 0;
}

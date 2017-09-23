#include <stdint.h>
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned int *)0x40025400))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned int *)0x4002551C))
#define RCGCGPIO       (*((volatile uint32_t *)0x400FE608))
#define GPIO_PORTF_AFSEL_R      (*((volatile uint32_t *)0x40025420))
#define GPIO_PORTF_LOCK_R       (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_PCTL_R       (*((volatile uint32_t *)0x4002552C))
#define GPIO_PORTF_CR_R         (*((volatile uint32_t *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile uint32_t *)0x40025528))




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
    RCGCGPIO |= 0X00000020; // enable clock port F
    int x = 203;
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_AFSEL_R = 0;
    GPIO_PORTF_DEN_R |= 0x0E;
    GPIO_PORTF_PCTL_R  = 0x00000000;
    GPIO_PORTF_CR_R = 0x0E;
    GPIO_PORTF_AMSEL_R = 0;


}

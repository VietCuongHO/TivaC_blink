/*
 * Blinky Led, Blue, Green Program
 * Ho Viet Cuong
 * University of Technology
 * Embedded Sofware C/C++
 * Solution:
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <driverlib/sysctl.h>
#include <driverlib/gpio.h>

//Main Program
int main(void)
{
    uint8_t shift = 2;
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);     //freq = 200/2.5 = 80Mhz
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, shift);
        SysCtlDelay(13333333);         //delay 1s --> ham delay co thoi gian 3 chu ky may, tdelay = ((1/80Mhz) * 3)* value
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
        SysCtlDelay(13333333);
        shift <<= 1;
        if (shift > 8)
            shift = 2;
    }

}

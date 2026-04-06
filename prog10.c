#include <LPC214x.h>

int main()
{
    int i;

    PINSEL0 |= 0x05;
    U0LCR = 0x83;
    U0DLL = 78;
    U0LCR = 0x03;

    while(1)
    {
        while(!(U0LSR & 0x20)); U0THR='O';
        while(!(U0LSR & 0x20)); U0THR='K';
        while(!(U0LSR & 0x20)); U0THR='\n';

        for(i=0;i<5000000;i++);
    }
}

#include <LPC214x.h>

void delay()
{
    int i,j;
    for(i=0;i<200;i++)
        for(j=0;j<1000;j++);
}

int main()
{
    int i;

    PINSEL0 |= 0x05;
    U0LCR = 0x83;
    U0DLL = 97;
    U0LCR = 0x03;

    while(1)
    {
        for(i=0;i<16;i++)
        {
            while(!(U0LSR & 0x20));
            U0THR = (i<10)? i+'0' : i+55;

            while(!(U0LSR & 0x20));
            U0THR = '\n';

            delay();
        }
    }
}

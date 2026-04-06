#include <LPC214x.h>

unsigned int cw[4]={0x90,0xC0,0x60,0x30};
unsigned int ccw[4]={0x30,0x60,0xC0,0x90};

void delay()
{
    int i,j;
    for(i=0;i<200;i++)
        for(j=0;j<5000;j++);
}

void send(char *s)
{
    while(*s)
    {
        while(!(U0LSR & 0x20));
        U0THR=*s++;
    }
}

int main()
{
    int i;

    PINSEL0 |= 0x05;
    U0LCR = 0x83;
    U0DLL = 78;
    U0DLM = 0;
    U0LCR = 0x03;

    IO0DIR |= 0xF0;

    while(1)
    {
        send("CLOCKWISE\r\n\r\n");

        for(i=0;i<4;i++)
        {
            IO0CLR=0xF0;
            IO0SET=cw[i];
            delay();
        }

        send("ANTICLOCKWISE\r\n\r\n");

        for(i=0;i<4;i++)
        {
            IO0CLR=0xF0;
            IO0SET=ccw[i];
            delay();
        }
    }
}

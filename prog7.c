#include <LPC214x.h>

void UART0_Init(void)
{
    PINSEL0 |= 0x05;
    U0LCR = 0x83;
    U0DLL = 78;
    U0DLM = 0;
    U0LCR = 0x03;
}

void UART0_TxString(char *s)
{
    while(*s)
    {
        while(!(U0LSR & 0x20));
        U0THR = *s++;
    }
}

int main()
{
    UART0_Init();
    UART0_TxString("Hello World\r\n");
    while(1);
}

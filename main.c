#include <xc.h>
#include "main.h"
void init_config(void)
{

    PEIE = 1;
	/* Clear old content */
	PORTB = 0x00;

	/* Set PORTB as a Output */
	TRISB = 0x00;

	/* Config PORTB as digital */
	ADCON1 = 0x0F;

	init_timer0();

	GIE = 1;
	init_uart();
    init_i2c();
      
}

void main()
{
	char c;

	init_config();
    unsigned char address = 0;
    char ch;
	while (1)
	{
        address = 0;
        while((ch = getche()) != '$')
        {
            write_24c02(address++, ch);
        }
        write_24c02(address, '\0');
        puts("\n\r");
        
        address = 0;
        ch = read_24c02(address++);        
        while(ch)
        {
            putch(ch);
            ch = read_24c02(address++);        
        }
        puts("\n\r");
    }
}
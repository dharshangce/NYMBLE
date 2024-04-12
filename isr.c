#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
	static unsigned short count;
     
	if (TMR0IF)
	{
		TMR0 = TMR0 + 8;

		if (count++ == 20000)
		{
			count = 0;
            sec++;
            if(sec==5)
            {
                
                average=(c*8)/5;
                putch((average/10)%10+48);
                putch(average%10 + 48);
                sec=0;
                c=0;
            }
		
		}
		TMR0IF = 0;
	}
}
#include <xc.h>
#include "main.h"
void write_24c02(unsigned char address, unsigned char data)
{
	i2c_start();
	i2c_write(0xA0);                                      //slave id ,write op
	i2c_write(address);
	i2c_write(data);
	i2c_stop();
    for(long int wait=3000;wait--;);
}
unsigned char read_24c02(unsigned char address)
{
	unsigned char data;
	i2c_start();
	i2c_write(0xA0);
	i2c_write(address);
	i2c_rep_start();
	i2c_write(0xA1);                                    //slave id ,read op
	data = i2c_read();
	i2c_stop();
	return data;
}
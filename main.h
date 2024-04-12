#ifndef I2C_H
#define I2C_H
#define RX_PIN					TRISC7
#define TX_PIN					TRISC6

void init_timer0(void);
void init_i2c(void);
void i2c_start(void);
void i2c_rep_start(void);
void i2c_stop(void);
void i2c_write(unsigned char data);
unsigned char i2c_read(void);

void init_uart(void);
void putch(unsigned char byte);
int puts(const char *s);
unsigned char getch(void);
unsigned char getch_with_timeout(unsigned short max_time);
unsigned char getche(void);
void write_24c02(unsigned char address, unsigned char data);
unsigned char read_24c02(unsigned char address);
unsigned char address;
int sec=0,c=0,average;

#endif
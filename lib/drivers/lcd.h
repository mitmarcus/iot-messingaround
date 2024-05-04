#pragma once
#define F_CPU 16000000UL /* Define CPU Frequency */

#include <avr/io.h>
#include <util/delay.h>

/* LCD Port and Pin Definitions */
#define LCD_Data_Dir DDRA	 /* Define LCD data port direction */
#define LCD_Command_Dir DDRC /* Define LCD command port direction register */
#define LCD_Data_Port PORTA
#define LCD_Command_Port PORTC
#define RS PC0 /* Define Register Select pin */
#define RW PC1 /* Define Read/Write signal pin */
#define EN PC2 /* Define Enable signal pin */

/* LCD Function Prototypes */
void lcd_command(unsigned char cmnd);
void lcd_char(unsigned char char_data);
void lcd_init(void);
void lcd_string(char *str);
void lcd_string_xy(char row, char pos, char *str);
void lcd_clear(void);
void lcd_two_rows(const char *row1_text, char row1_pos, const char *row2_text, char row2_pos);
void lcd_static_with_scroll(const char *static_text, const char *scroll_text, uint16_t delay, int cycles);

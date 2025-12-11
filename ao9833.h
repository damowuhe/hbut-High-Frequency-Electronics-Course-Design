#ifndef __AO9833_H__
#define __AO9833_H__

#include "gpio.h"

void write_ad9833_d16(unsigned int data);
void ao9833_init(void);
void wave_out(void);
void triangle_wave_out(void);
void square_wave_out(void);
#endif

#ifndef MLX_USER_H
#define MLX_USER_H

#include "stdint.h"

#define CHIP_ADDRESS 0x3A << 1

int32_t mlx90632_i2c_read(int16_t register_address, uint16_t *value);
int32_t mlx90632_i2c_read32(int16_t register_address, uint32_t *value);
int32_t mlx90632_i2c_write(int16_t register_address, uint16_t value);

void usleep(int min_range, int max_range);

void MLX_Init(void);
double MLX_Run(void);

#endif

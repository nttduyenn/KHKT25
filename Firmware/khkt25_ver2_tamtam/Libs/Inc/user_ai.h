#ifndef USER_AI__H
#define USER_AI_H

#define INPUT_SCALE     0.14491689205169678f
#define INPUT_ZP       -128
#define OUTPUT_SCALE    0.007374064065515995f
#define OUTPUT_ZP      -128

#define MAE_THRESHOLD   1238.0508f

typedef enum {
    NORMAL = 0,
    ANOMALY = 1,
	ERR = -1
} AI_Status;

void AI_Init(void);
AI_Status AI_Run(double value);

#endif

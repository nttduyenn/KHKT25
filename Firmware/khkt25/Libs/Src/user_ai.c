#include "user_ai.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "network.h"
#include "network_data.h"
#include "network_data_params.h"

ai_handle net_handle = AI_HANDLE_NULL;
ai_buffer ai_input[AI_NETWORK_IN_NUM];
ai_buffer ai_output[AI_NETWORK_OUT_NUM];

void AI_Init(void)
{
    AI_ALIGNED(32)
    static uint8_t activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];

    ai_error ai_err;

    g_network_activations_table[1] = activations;

    ai_handle* weights_table = AI_NETWORK_DATA_WEIGHTS_TABLE_GET();

    ai_err = ai_network_create_and_init(
        &net_handle,
        AI_NETWORK_DATA_ACTIVATIONS_TABLE_GET(),
        weights_table
    );

    if (ai_err.type != AI_ERROR_NONE) {
        while(1);
    }

    const ai_buffer *in  = ai_network_inputs_get(net_handle, NULL);
    const ai_buffer *out = ai_network_outputs_get(net_handle, NULL);

    memcpy(ai_input,  in,  sizeof(ai_input));
    memcpy(ai_output, out, sizeof(ai_output));
}

AI_Status AI_Run(double value)
{
	// Quantize input float → int8
    ai_i8 inp_quant = (ai_i8)roundf(value / INPUT_SCALE) + INPUT_ZP;

    ai_input[0].data = AI_HANDLE_PTR(&inp_quant);

    ai_i32 batch = ai_network_run(net_handle, ai_input, ai_output);

	if (batch != 1) {
		return ERR;
	}

	// Dequantize output int8 → float
    ai_i8 out_quant = *((ai_i8*)ai_output[0].data);
    float reconstructed = (out_quant - OUTPUT_ZP) * OUTPUT_SCALE;

    // Calculate error MSE
    float diff = value - reconstructed;
    float error = diff * diff;

    if (error > MAE_THRESHOLD) {
        return ANOMALY;
    } else {
        return NORMAL;
    }
}

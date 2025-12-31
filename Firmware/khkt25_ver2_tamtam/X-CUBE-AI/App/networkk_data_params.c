/**
  ******************************************************************************
  * @file    networkk_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-12-26T14:53:48+0700
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "networkk_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_networkk_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_networkk_weights_array_u64[21] = {
  0xbe98a4bc3ed54918U, 0xbf43f7d33f3db646U, 0x3ea8794cbf45d0dbU, 0x3f3e59f2bf2573ddU,
  0x0U, 0x0U, 0x0U, 0x0U,
  0x3d758ff0bf468bf9U, 0x3f4efb0cbe3fd4dcU, 0xbd8fc0383f4b4bd4U, 0xbf2df4b5be9d2532U,
  0xbf43462c00000000U, 0x3f41984abe57d5a8U, 0xbf0e6130bf216020U, 0x3f0592f2bf0b4814U,
  0x3ebecfb83f2ef334U, 0x3f33b6103dc1d730U, 0xbea18638bed0da99U, 0x3f3b9868bf3de2d7U,
  0x3ff0b0803e95e92cU,
};


ai_handle g_networkk_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_networkk_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};


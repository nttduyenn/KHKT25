################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/Src/anomaly_detector.c \
../Libs/Src/mlx90632.c \
../Libs/Src/network.c \
../Libs/Src/network_data.c \
../Libs/Src/network_data_params.c \
../Libs/Src/simple_kalman_filter.c \
../Libs/Src/user_ai.c \
../Libs/Src/user_mlx.c \
../Libs/Src/user_syscalls.c 

OBJS += \
./Libs/Src/anomaly_detector.o \
./Libs/Src/mlx90632.o \
./Libs/Src/network.o \
./Libs/Src/network_data.o \
./Libs/Src/network_data_params.o \
./Libs/Src/simple_kalman_filter.o \
./Libs/Src/user_ai.o \
./Libs/Src/user_mlx.o \
./Libs/Src/user_syscalls.o 

C_DEPS += \
./Libs/Src/anomaly_detector.d \
./Libs/Src/mlx90632.d \
./Libs/Src/network.d \
./Libs/Src/network_data.d \
./Libs/Src/network_data_params.d \
./Libs/Src/simple_kalman_filter.d \
./Libs/Src/user_ai.d \
./Libs/Src/user_mlx.d \
./Libs/Src/user_syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/Src/%.o Libs/Src/%.su Libs/Src/%.cyclo: ../Libs/Src/%.c Libs/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/ST/AI/Inc -I../X-CUBE-AI/App -I"D:/STM32CubeIDE/workspace_1.18.1/khkt25_first/Libs" -I"D:/STM32CubeIDE/workspace_1.18.1/khkt25_first/Libs/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-Src

clean-Libs-2f-Src:
	-$(RM) ./Libs/Src/anomaly_detector.cyclo ./Libs/Src/anomaly_detector.d ./Libs/Src/anomaly_detector.o ./Libs/Src/anomaly_detector.su ./Libs/Src/mlx90632.cyclo ./Libs/Src/mlx90632.d ./Libs/Src/mlx90632.o ./Libs/Src/mlx90632.su ./Libs/Src/network.cyclo ./Libs/Src/network.d ./Libs/Src/network.o ./Libs/Src/network.su ./Libs/Src/network_data.cyclo ./Libs/Src/network_data.d ./Libs/Src/network_data.o ./Libs/Src/network_data.su ./Libs/Src/network_data_params.cyclo ./Libs/Src/network_data_params.d ./Libs/Src/network_data_params.o ./Libs/Src/network_data_params.su ./Libs/Src/simple_kalman_filter.cyclo ./Libs/Src/simple_kalman_filter.d ./Libs/Src/simple_kalman_filter.o ./Libs/Src/simple_kalman_filter.su ./Libs/Src/user_ai.cyclo ./Libs/Src/user_ai.d ./Libs/Src/user_ai.o ./Libs/Src/user_ai.su ./Libs/Src/user_mlx.cyclo ./Libs/Src/user_mlx.d ./Libs/Src/user_mlx.o ./Libs/Src/user_mlx.su ./Libs/Src/user_syscalls.cyclo ./Libs/Src/user_syscalls.d ./Libs/Src/user_syscalls.o ./Libs/Src/user_syscalls.su

.PHONY: clean-Libs-2f-Src


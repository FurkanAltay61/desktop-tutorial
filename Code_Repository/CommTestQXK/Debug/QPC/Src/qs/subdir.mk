################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../QPC/Src/qs/qs.c \
../QPC/Src/qs/qs_64bit.c \
../QPC/Src/qs/qs_fp.c \
../QPC/Src/qs/qs_rx.c \
../QPC/Src/qs/qutest.c 

OBJS += \
./QPC/Src/qs/qs.o \
./QPC/Src/qs/qs_64bit.o \
./QPC/Src/qs/qs_fp.o \
./QPC/Src/qs/qs_rx.o \
./QPC/Src/qs/qutest.o 

C_DEPS += \
./QPC/Src/qs/qs.d \
./QPC/Src/qs/qs_64bit.d \
./QPC/Src/qs/qs_fp.d \
./QPC/Src/qs/qs_rx.d \
./QPC/Src/qs/qutest.d 


# Each subdirectory must supply rules for building sources it contributes
QPC/Src/qs/%.o QPC/Src/qs/%.su: ../QPC/Src/qs/%.c QPC/Src/qs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/QPC_Port" -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/QPC/Inc" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/User/Inc" -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-QPC-2f-Src-2f-qs

clean-QPC-2f-Src-2f-qs:
	-$(RM) ./QPC/Src/qs/qs.d ./QPC/Src/qs/qs.o ./QPC/Src/qs/qs.su ./QPC/Src/qs/qs_64bit.d ./QPC/Src/qs/qs_64bit.o ./QPC/Src/qs/qs_64bit.su ./QPC/Src/qs/qs_fp.d ./QPC/Src/qs/qs_fp.o ./QPC/Src/qs/qs_fp.su ./QPC/Src/qs/qs_rx.d ./QPC/Src/qs/qs_rx.o ./QPC/Src/qs/qs_rx.su ./QPC/Src/qs/qutest.d ./QPC/Src/qs/qutest.o ./QPC/Src/qs/qutest.su

.PHONY: clean-QPC-2f-Src-2f-qs


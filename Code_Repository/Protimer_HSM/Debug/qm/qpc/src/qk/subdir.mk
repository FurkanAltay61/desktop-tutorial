################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/src/qk/qk.c 

OBJS += \
./qm/qpc/src/qk/qk.o 

C_DEPS += \
./qm/qpc/src/qk/qk.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/src/qk/%.o qm/qpc/src/qk/%.su: ../qm/qpc/src/qk/%.c qm/qpc/src/qk/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/qp/qpc/ports/arm7-9/qk/gnu" -I"C:/qp/qpc/ports/arm7-9/qv/gnu" -I"C:/qp/qpc/include" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-src-2f-qk

clean-qm-2f-qpc-2f-src-2f-qk:
	-$(RM) ./qm/qpc/src/qk/qk.d ./qm/qpc/src/qk/qk.o ./qm/qpc/src/qk/qk.su

.PHONY: clean-qm-2f-qpc-2f-src-2f-qk

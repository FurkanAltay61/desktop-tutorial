################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/src/qv/qv.c 

OBJS += \
./qm/qpc/src/qv/qv.o 

C_DEPS += \
./qm/qpc/src/qv/qv.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/src/qv/%.o qm/qpc/src/qv/%.su: ../qm/qpc/src/qv/%.c qm/qpc/src/qv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/qp/qpc/ports/arm7-9/qk/gnu" -I"C:/qp/qpc/ports/arm7-9/qv/gnu" -I"C:/qp/qpc/include" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-src-2f-qv

clean-qm-2f-qpc-2f-src-2f-qv:
	-$(RM) ./qm/qpc/src/qv/qv.d ./qm/qpc/src/qv/qv.o ./qm/qpc/src/qv/qv.su

.PHONY: clean-qm-2f-qpc-2f-src-2f-qv


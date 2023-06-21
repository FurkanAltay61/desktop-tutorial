################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/src/qs/qs.c \
../qm/qpc/src/qs/qs_64bit.c \
../qm/qpc/src/qs/qs_fp.c \
../qm/qpc/src/qs/qs_rx.c \
../qm/qpc/src/qs/qutest.c 

OBJS += \
./qm/qpc/src/qs/qs.o \
./qm/qpc/src/qs/qs_64bit.o \
./qm/qpc/src/qs/qs_fp.o \
./qm/qpc/src/qs/qs_rx.o \
./qm/qpc/src/qs/qutest.o 

C_DEPS += \
./qm/qpc/src/qs/qs.d \
./qm/qpc/src/qs/qs_64bit.d \
./qm/qpc/src/qs/qs_fp.d \
./qm/qpc/src/qs/qs_rx.d \
./qm/qpc/src/qs/qutest.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/src/qs/%.o qm/qpc/src/qs/%.su: ../qm/qpc/src/qs/%.c qm/qpc/src/qs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/qp/qpc/ports/arm7-9/qk/gnu" -I"C:/qp/qpc/ports/arm7-9/qv/gnu" -I"C:/qp/qpc/include" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-src-2f-qs

clean-qm-2f-qpc-2f-src-2f-qs:
	-$(RM) ./qm/qpc/src/qs/qs.d ./qm/qpc/src/qs/qs.o ./qm/qpc/src/qs/qs.su ./qm/qpc/src/qs/qs_64bit.d ./qm/qpc/src/qs/qs_64bit.o ./qm/qpc/src/qs/qs_64bit.su ./qm/qpc/src/qs/qs_fp.d ./qm/qpc/src/qs/qs_fp.o ./qm/qpc/src/qs/qs_fp.su ./qm/qpc/src/qs/qs_rx.d ./qm/qpc/src/qs/qs_rx.o ./qm/qpc/src/qs/qs_rx.su ./qm/qpc/src/qs/qutest.d ./qm/qpc/src/qs/qutest.o ./qm/qpc/src/qs/qutest.su

.PHONY: clean-qm-2f-qpc-2f-src-2f-qs


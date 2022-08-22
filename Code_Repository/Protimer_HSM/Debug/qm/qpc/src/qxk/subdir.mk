################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/src/qxk/qxk.c \
../qm/qpc/src/qxk/qxk_mutex.c \
../qm/qpc/src/qxk/qxk_sema.c \
../qm/qpc/src/qxk/qxk_xthr.c 

OBJS += \
./qm/qpc/src/qxk/qxk.o \
./qm/qpc/src/qxk/qxk_mutex.o \
./qm/qpc/src/qxk/qxk_sema.o \
./qm/qpc/src/qxk/qxk_xthr.o 

C_DEPS += \
./qm/qpc/src/qxk/qxk.d \
./qm/qpc/src/qxk/qxk_mutex.d \
./qm/qpc/src/qxk/qxk_sema.d \
./qm/qpc/src/qxk/qxk_xthr.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/src/qxk/%.o qm/qpc/src/qxk/%.su: ../qm/qpc/src/qxk/%.c qm/qpc/src/qxk/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/qp/qpc/ports/arm7-9/qk/gnu" -I"C:/qp/qpc/ports/arm7-9/qv/gnu" -I"C:/qp/qpc/include" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-src-2f-qxk

clean-qm-2f-qpc-2f-src-2f-qxk:
	-$(RM) ./qm/qpc/src/qxk/qxk.d ./qm/qpc/src/qxk/qxk.o ./qm/qpc/src/qxk/qxk.su ./qm/qpc/src/qxk/qxk_mutex.d ./qm/qpc/src/qxk/qxk_mutex.o ./qm/qpc/src/qxk/qxk_mutex.su ./qm/qpc/src/qxk/qxk_sema.d ./qm/qpc/src/qxk/qxk_sema.o ./qm/qpc/src/qxk/qxk_sema.su ./qm/qpc/src/qxk/qxk_xthr.d ./qm/qpc/src/qxk/qxk_xthr.o ./qm/qpc/src/qxk/qxk_xthr.su

.PHONY: clean-qm-2f-qpc-2f-src-2f-qxk


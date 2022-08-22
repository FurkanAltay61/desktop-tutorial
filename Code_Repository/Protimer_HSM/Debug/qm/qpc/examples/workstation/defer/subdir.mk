################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/workstation/defer/bsp.c \
../qm/qpc/examples/workstation/defer/defer.c 

OBJS += \
./qm/qpc/examples/workstation/defer/bsp.o \
./qm/qpc/examples/workstation/defer/defer.o 

C_DEPS += \
./qm/qpc/examples/workstation/defer/bsp.d \
./qm/qpc/examples/workstation/defer/defer.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/workstation/defer/%.o qm/qpc/examples/workstation/defer/%.su: ../qm/qpc/examples/workstation/defer/%.c qm/qpc/examples/workstation/defer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-workstation-2f-defer

clean-qm-2f-qpc-2f-examples-2f-workstation-2f-defer:
	-$(RM) ./qm/qpc/examples/workstation/defer/bsp.d ./qm/qpc/examples/workstation/defer/bsp.o ./qm/qpc/examples/workstation/defer/bsp.su ./qm/qpc/examples/workstation/defer/defer.d ./qm/qpc/examples/workstation/defer/defer.o ./qm/qpc/examples/workstation/defer/defer.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-workstation-2f-defer


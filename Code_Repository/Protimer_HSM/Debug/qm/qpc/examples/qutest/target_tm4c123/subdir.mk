################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/qutest/target_tm4c123/qutest_port.c 

OBJS += \
./qm/qpc/examples/qutest/target_tm4c123/qutest_port.o 

C_DEPS += \
./qm/qpc/examples/qutest/target_tm4c123/qutest_port.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/qutest/target_tm4c123/%.o qm/qpc/examples/qutest/target_tm4c123/%.su: ../qm/qpc/examples/qutest/target_tm4c123/%.c qm/qpc/examples/qutest/target_tm4c123/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-qutest-2f-target_tm4c123

clean-qm-2f-qpc-2f-examples-2f-qutest-2f-target_tm4c123:
	-$(RM) ./qm/qpc/examples/qutest/target_tm4c123/qutest_port.d ./qm/qpc/examples/qutest/target_tm4c123/qutest_port.o ./qm/qpc/examples/qutest/target_tm4c123/qutest_port.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-qutest-2f-target_tm4c123


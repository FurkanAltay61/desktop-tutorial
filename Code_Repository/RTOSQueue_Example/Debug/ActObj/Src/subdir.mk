################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ActObj/Src/uc_ao.c 

OBJS += \
./ActObj/Src/uc_ao.o 

C_DEPS += \
./ActObj/Src/uc_ao.d 


# Each subdirectory must supply rules for building sources it contributes
ActObj/Src/%.o ActObj/Src/%.su: ../ActObj/Src/%.c ActObj/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/RTOSQueue_Example/ActObj/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/RTOSQueue_Example/User/Inc" -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/RTOSQueue_Example/QPC/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ActObj-2f-Src

clean-ActObj-2f-Src:
	-$(RM) ./ActObj/Src/uc_ao.d ./ActObj/Src/uc_ao.o ./ActObj/Src/uc_ao.su

.PHONY: clean-ActObj-2f-Src


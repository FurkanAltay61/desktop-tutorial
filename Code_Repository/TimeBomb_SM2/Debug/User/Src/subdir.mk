################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/Bsp.c \
../User/Src/TimeBomb.c 

OBJS += \
./User/Src/Bsp.o \
./User/Src/TimeBomb.o 

C_DEPS += \
./User/Src/Bsp.d \
./User/Src/TimeBomb.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o User/Src/%.su: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/TimeBomb_SM2/ActObj/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/TimeBomb_SM2/User/Inc" -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/TimeBomb_SM2/QPC/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Src

clean-User-2f-Src:
	-$(RM) ./User/Src/Bsp.d ./User/Src/Bsp.o ./User/Src/Bsp.su ./User/Src/TimeBomb.d ./User/Src/TimeBomb.o ./User/Src/TimeBomb.su

.PHONY: clean-User-2f-Src

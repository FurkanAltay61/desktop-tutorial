################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.c 

OBJS += \
./FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.o 

C_DEPS += \
./FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/ARM_CM7/r0p1/%.o FreeRTOS/portable/GCC/ARM_CM7/r0p1/%.su: ../FreeRTOS/portable/GCC/ARM_CM7/r0p1/%.c FreeRTOS/portable/GCC/ARM_CM7/r0p1/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXKLWIPExported/FreeRTOS/include" -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXKLWIPExported/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXKLWIPExported/User/Inc" -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXKLWIPExported/QPC/Inc" -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7-2f-r0p1

clean-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7-2f-r0p1:
	-$(RM) ./FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.d ./FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.o ./FreeRTOS/portable/GCC/ARM_CM7/r0p1/port.su

.PHONY: clean-FreeRTOS-2f-portable-2f-GCC-2f-ARM_CM7-2f-r0p1


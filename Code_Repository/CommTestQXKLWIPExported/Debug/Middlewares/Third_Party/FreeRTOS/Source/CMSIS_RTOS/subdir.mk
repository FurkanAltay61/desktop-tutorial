################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.o Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.su: ../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.c Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include/compat/stdc" -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include/compat/posix/sys" -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/system/arch" -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include" -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include/compat/posix" -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include/lwip/prot" -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include/lwip/apps" -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include/lwip/priv" -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include/netif/ppp" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXKLWIPExported/User/Inc" -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXKLWIPExported/QPC/Inc" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d ./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o ./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source-2f-CMSIS_RTOS


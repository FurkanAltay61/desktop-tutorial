################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/bsp.c \
../qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/main.c 

OBJS += \
./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/bsp.o \
./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/main.o 

C_DEPS += \
./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/bsp.d \
./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/main.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/%.o qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/%.su: ../qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/%.c qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-arm-2d-cm-2f-dpp_stm32f4-2d-discovery-2f-qv

clean-qm-2f-qpc-2f-examples-2f-arm-2d-cm-2f-dpp_stm32f4-2d-discovery-2f-qv:
	-$(RM) ./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/bsp.d ./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/bsp.o ./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/bsp.su ./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/main.d ./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/main.o ./qm/qpc/examples/arm-cm/dpp_stm32f4-discovery/qv/main.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-arm-2d-cm-2f-dpp_stm32f4-2d-discovery-2f-qv


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/bsp.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/main.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/philo.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/table.c 

OBJS += \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/bsp.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/main.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/philo.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/table.o 

C_DEPS += \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/bsp.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/main.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/philo.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/table.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/%.o qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/%.su: ../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/%.c qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery

clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery:
	-$(RM) ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/bsp.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/bsp.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/bsp.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/main.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/main.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/main.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/philo.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/philo.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/philo.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/table.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/table.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/table.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery


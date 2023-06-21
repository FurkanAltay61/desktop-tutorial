################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/BSP.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/JLINKMEM_Process.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/OS_Error.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/RTOSInit_STM32F4xx.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/SEGGER_HardFaultHandler.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx2.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx3.c 

S_UPPER_SRCS += \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/HardFaultHandler.S 

OBJS += \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/BSP.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/HardFaultHandler.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/JLINKMEM_Process.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/OS_Error.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/RTOSInit_STM32F4xx.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/SEGGER_HardFaultHandler.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx2.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx3.o 

S_UPPER_DEPS += \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/HardFaultHandler.d 

C_DEPS += \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/BSP.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/JLINKMEM_Process.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/OS_Error.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/RTOSInit_STM32F4xx.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/SEGGER_HardFaultHandler.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx2.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx3.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/%.o qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/%.su: ../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/%.c qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/%.o: ../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/%.S qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery-2f-iar-2f-Setup

clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery-2f-iar-2f-Setup:
	-$(RM) ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/BSP.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/BSP.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/BSP.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/HardFaultHandler.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/HardFaultHandler.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/JLINKMEM_Process.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/JLINKMEM_Process.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/JLINKMEM_Process.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/OS_Error.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/OS_Error.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/OS_Error.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/RTOSInit_STM32F4xx.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/RTOSInit_STM32F4xx.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/RTOSInit_STM32F4xx.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/SEGGER_HardFaultHandler.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/SEGGER_HardFaultHandler.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/SEGGER_HardFaultHandler.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx2.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx2.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx2.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx3.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx3.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/Setup/xmtx3.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery-2f-iar-2f-Setup


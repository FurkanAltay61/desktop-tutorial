################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_Syscalls_IAR.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_printf.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_Config_embOS.c \
../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_embOS.c 

OBJS += \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_Syscalls_IAR.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_printf.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_Config_embOS.o \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_embOS.o 

C_DEPS += \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_Syscalls_IAR.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_printf.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_Config_embOS.d \
./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_embOS.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/%.o qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/%.su: ../qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/%.c qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery-2f-iar-2f-SEGGER

clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery-2f-iar-2f-SEGGER:
	-$(RM) ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_Syscalls_IAR.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_Syscalls_IAR.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_Syscalls_IAR.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_printf.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_printf.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_RTT_printf.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_Config_embOS.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_Config_embOS.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_Config_embOS.su ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_embOS.d ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_embOS.o ./qm/qpc/examples/embos/arm-cm/dpp_stm32f429-discovery/iar/SEGGER/SEGGER_SYSVIEW_embOS.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-embos-2f-arm-2d-cm-2f-dpp_stm32f429-2d-discovery-2f-iar-2f-SEGGER


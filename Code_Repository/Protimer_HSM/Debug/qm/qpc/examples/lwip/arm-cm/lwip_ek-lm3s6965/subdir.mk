################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwip.c \
../qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwipmgr.c \
../qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/main.c \
../qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/philo.c \
../qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/table.c 

OBJS += \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwip.o \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwipmgr.o \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/main.o \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/philo.o \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/table.o 

C_DEPS += \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwip.d \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwipmgr.d \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/main.d \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/philo.d \
./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/table.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/%.o qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/%.su: ../qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/%.c qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-lwip-2f-arm-2d-cm-2f-lwip_ek-2d-lm3s6965

clean-qm-2f-qpc-2f-examples-2f-lwip-2f-arm-2d-cm-2f-lwip_ek-2d-lm3s6965:
	-$(RM) ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwip.d ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwip.o ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwip.su ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwipmgr.d ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwipmgr.o ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/lwipmgr.su ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/main.d ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/main.o ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/main.su ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/philo.d ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/philo.o ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/philo.su ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/table.d ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/table.o ./qm/qpc/examples/lwip/arm-cm/lwip_ek-lm3s6965/table.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-lwip-2f-arm-2d-cm-2f-lwip_ek-2d-lm3s6965


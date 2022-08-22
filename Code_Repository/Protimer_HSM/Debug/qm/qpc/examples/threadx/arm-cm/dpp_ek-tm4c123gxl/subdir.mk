################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/bsp.c \
../qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/main.c \
../qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/philo.c \
../qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/table.c 

OBJS += \
./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/bsp.o \
./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/main.o \
./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/philo.o \
./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/table.o 

C_DEPS += \
./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/bsp.d \
./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/main.d \
./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/philo.d \
./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/table.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/%.o qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/%.su: ../qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/%.c qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-threadx-2f-arm-2d-cm-2f-dpp_ek-2d-tm4c123gxl

clean-qm-2f-qpc-2f-examples-2f-threadx-2f-arm-2d-cm-2f-dpp_ek-2d-tm4c123gxl:
	-$(RM) ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/bsp.d ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/bsp.o ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/bsp.su ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/main.d ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/main.o ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/main.su ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/philo.d ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/philo.o ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/philo.su ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/table.d ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/table.o ./qm/qpc/examples/threadx/arm-cm/dpp_ek-tm4c123gxl/table.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-threadx-2f-arm-2d-cm-2f-dpp_ek-2d-tm4c123gxl


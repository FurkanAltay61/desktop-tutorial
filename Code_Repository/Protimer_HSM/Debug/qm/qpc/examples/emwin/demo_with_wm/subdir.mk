################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/emwin/demo_with_wm/bsp.c \
../qm/qpc/examples/emwin/demo_with_wm/main.c \
../qm/qpc/examples/emwin/demo_with_wm/philo.c \
../qm/qpc/examples/emwin/demo_with_wm/sim_x.c \
../qm/qpc/examples/emwin/demo_with_wm/table.c \
../qm/qpc/examples/emwin/demo_with_wm/winmain.c 

OBJS += \
./qm/qpc/examples/emwin/demo_with_wm/bsp.o \
./qm/qpc/examples/emwin/demo_with_wm/main.o \
./qm/qpc/examples/emwin/demo_with_wm/philo.o \
./qm/qpc/examples/emwin/demo_with_wm/sim_x.o \
./qm/qpc/examples/emwin/demo_with_wm/table.o \
./qm/qpc/examples/emwin/demo_with_wm/winmain.o 

C_DEPS += \
./qm/qpc/examples/emwin/demo_with_wm/bsp.d \
./qm/qpc/examples/emwin/demo_with_wm/main.d \
./qm/qpc/examples/emwin/demo_with_wm/philo.d \
./qm/qpc/examples/emwin/demo_with_wm/sim_x.d \
./qm/qpc/examples/emwin/demo_with_wm/table.d \
./qm/qpc/examples/emwin/demo_with_wm/winmain.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/emwin/demo_with_wm/%.o qm/qpc/examples/emwin/demo_with_wm/%.su: ../qm/qpc/examples/emwin/demo_with_wm/%.c qm/qpc/examples/emwin/demo_with_wm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-emwin-2f-demo_with_wm

clean-qm-2f-qpc-2f-examples-2f-emwin-2f-demo_with_wm:
	-$(RM) ./qm/qpc/examples/emwin/demo_with_wm/bsp.d ./qm/qpc/examples/emwin/demo_with_wm/bsp.o ./qm/qpc/examples/emwin/demo_with_wm/bsp.su ./qm/qpc/examples/emwin/demo_with_wm/main.d ./qm/qpc/examples/emwin/demo_with_wm/main.o ./qm/qpc/examples/emwin/demo_with_wm/main.su ./qm/qpc/examples/emwin/demo_with_wm/philo.d ./qm/qpc/examples/emwin/demo_with_wm/philo.o ./qm/qpc/examples/emwin/demo_with_wm/philo.su ./qm/qpc/examples/emwin/demo_with_wm/sim_x.d ./qm/qpc/examples/emwin/demo_with_wm/sim_x.o ./qm/qpc/examples/emwin/demo_with_wm/sim_x.su ./qm/qpc/examples/emwin/demo_with_wm/table.d ./qm/qpc/examples/emwin/demo_with_wm/table.o ./qm/qpc/examples/emwin/demo_with_wm/table.su ./qm/qpc/examples/emwin/demo_with_wm/winmain.d ./qm/qpc/examples/emwin/demo_with_wm/winmain.o ./qm/qpc/examples/emwin/demo_with_wm/winmain.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-emwin-2f-demo_with_wm


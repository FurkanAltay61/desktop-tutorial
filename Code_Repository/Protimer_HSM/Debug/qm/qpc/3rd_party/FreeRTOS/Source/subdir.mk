################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/FreeRTOS/Source/croutine.c \
../qm/qpc/3rd_party/FreeRTOS/Source/event_groups.c \
../qm/qpc/3rd_party/FreeRTOS/Source/list.c \
../qm/qpc/3rd_party/FreeRTOS/Source/queue.c \
../qm/qpc/3rd_party/FreeRTOS/Source/stream_buffer.c \
../qm/qpc/3rd_party/FreeRTOS/Source/tasks.c \
../qm/qpc/3rd_party/FreeRTOS/Source/timers.c 

OBJS += \
./qm/qpc/3rd_party/FreeRTOS/Source/croutine.o \
./qm/qpc/3rd_party/FreeRTOS/Source/event_groups.o \
./qm/qpc/3rd_party/FreeRTOS/Source/list.o \
./qm/qpc/3rd_party/FreeRTOS/Source/queue.o \
./qm/qpc/3rd_party/FreeRTOS/Source/stream_buffer.o \
./qm/qpc/3rd_party/FreeRTOS/Source/tasks.o \
./qm/qpc/3rd_party/FreeRTOS/Source/timers.o 

C_DEPS += \
./qm/qpc/3rd_party/FreeRTOS/Source/croutine.d \
./qm/qpc/3rd_party/FreeRTOS/Source/event_groups.d \
./qm/qpc/3rd_party/FreeRTOS/Source/list.d \
./qm/qpc/3rd_party/FreeRTOS/Source/queue.d \
./qm/qpc/3rd_party/FreeRTOS/Source/stream_buffer.d \
./qm/qpc/3rd_party/FreeRTOS/Source/tasks.d \
./qm/qpc/3rd_party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/FreeRTOS/Source/%.o qm/qpc/3rd_party/FreeRTOS/Source/%.su: ../qm/qpc/3rd_party/FreeRTOS/Source/%.c qm/qpc/3rd_party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-FreeRTOS-2f-Source

clean-qm-2f-qpc-2f-3rd_party-2f-FreeRTOS-2f-Source:
	-$(RM) ./qm/qpc/3rd_party/FreeRTOS/Source/croutine.d ./qm/qpc/3rd_party/FreeRTOS/Source/croutine.o ./qm/qpc/3rd_party/FreeRTOS/Source/croutine.su ./qm/qpc/3rd_party/FreeRTOS/Source/event_groups.d ./qm/qpc/3rd_party/FreeRTOS/Source/event_groups.o ./qm/qpc/3rd_party/FreeRTOS/Source/event_groups.su ./qm/qpc/3rd_party/FreeRTOS/Source/list.d ./qm/qpc/3rd_party/FreeRTOS/Source/list.o ./qm/qpc/3rd_party/FreeRTOS/Source/list.su ./qm/qpc/3rd_party/FreeRTOS/Source/queue.d ./qm/qpc/3rd_party/FreeRTOS/Source/queue.o ./qm/qpc/3rd_party/FreeRTOS/Source/queue.su ./qm/qpc/3rd_party/FreeRTOS/Source/stream_buffer.d ./qm/qpc/3rd_party/FreeRTOS/Source/stream_buffer.o ./qm/qpc/3rd_party/FreeRTOS/Source/stream_buffer.su ./qm/qpc/3rd_party/FreeRTOS/Source/tasks.d ./qm/qpc/3rd_party/FreeRTOS/Source/tasks.o ./qm/qpc/3rd_party/FreeRTOS/Source/tasks.su ./qm/qpc/3rd_party/FreeRTOS/Source/timers.d ./qm/qpc/3rd_party/FreeRTOS/Source/timers.o ./qm/qpc/3rd_party/FreeRTOS/Source/timers.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-FreeRTOS-2f-Source


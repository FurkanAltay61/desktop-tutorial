################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/ucos-ii/Source/os_core.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_dbg_r.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_flag.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_mbox.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_mem.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_mutex.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_q.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_sem.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_task.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_time.c \
../qm/qpc/3rd_party/ucos-ii/Source/os_tmr.c \
../qm/qpc/3rd_party/ucos-ii/Source/ucos_ii.c 

OBJS += \
./qm/qpc/3rd_party/ucos-ii/Source/os_core.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_dbg_r.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_flag.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_mbox.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_mem.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_mutex.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_q.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_sem.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_task.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_time.o \
./qm/qpc/3rd_party/ucos-ii/Source/os_tmr.o \
./qm/qpc/3rd_party/ucos-ii/Source/ucos_ii.o 

C_DEPS += \
./qm/qpc/3rd_party/ucos-ii/Source/os_core.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_dbg_r.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_flag.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_mbox.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_mem.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_mutex.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_q.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_sem.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_task.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_time.d \
./qm/qpc/3rd_party/ucos-ii/Source/os_tmr.d \
./qm/qpc/3rd_party/ucos-ii/Source/ucos_ii.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/ucos-ii/Source/%.o qm/qpc/3rd_party/ucos-ii/Source/%.su: ../qm/qpc/3rd_party/ucos-ii/Source/%.c qm/qpc/3rd_party/ucos-ii/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-ucos-2d-ii-2f-Source

clean-qm-2f-qpc-2f-3rd_party-2f-ucos-2d-ii-2f-Source:
	-$(RM) ./qm/qpc/3rd_party/ucos-ii/Source/os_core.d ./qm/qpc/3rd_party/ucos-ii/Source/os_core.o ./qm/qpc/3rd_party/ucos-ii/Source/os_core.su ./qm/qpc/3rd_party/ucos-ii/Source/os_dbg_r.d ./qm/qpc/3rd_party/ucos-ii/Source/os_dbg_r.o ./qm/qpc/3rd_party/ucos-ii/Source/os_dbg_r.su ./qm/qpc/3rd_party/ucos-ii/Source/os_flag.d ./qm/qpc/3rd_party/ucos-ii/Source/os_flag.o ./qm/qpc/3rd_party/ucos-ii/Source/os_flag.su ./qm/qpc/3rd_party/ucos-ii/Source/os_mbox.d ./qm/qpc/3rd_party/ucos-ii/Source/os_mbox.o ./qm/qpc/3rd_party/ucos-ii/Source/os_mbox.su ./qm/qpc/3rd_party/ucos-ii/Source/os_mem.d ./qm/qpc/3rd_party/ucos-ii/Source/os_mem.o ./qm/qpc/3rd_party/ucos-ii/Source/os_mem.su ./qm/qpc/3rd_party/ucos-ii/Source/os_mutex.d ./qm/qpc/3rd_party/ucos-ii/Source/os_mutex.o ./qm/qpc/3rd_party/ucos-ii/Source/os_mutex.su ./qm/qpc/3rd_party/ucos-ii/Source/os_q.d ./qm/qpc/3rd_party/ucos-ii/Source/os_q.o ./qm/qpc/3rd_party/ucos-ii/Source/os_q.su ./qm/qpc/3rd_party/ucos-ii/Source/os_sem.d ./qm/qpc/3rd_party/ucos-ii/Source/os_sem.o ./qm/qpc/3rd_party/ucos-ii/Source/os_sem.su ./qm/qpc/3rd_party/ucos-ii/Source/os_task.d ./qm/qpc/3rd_party/ucos-ii/Source/os_task.o ./qm/qpc/3rd_party/ucos-ii/Source/os_task.su ./qm/qpc/3rd_party/ucos-ii/Source/os_time.d ./qm/qpc/3rd_party/ucos-ii/Source/os_time.o ./qm/qpc/3rd_party/ucos-ii/Source/os_time.su ./qm/qpc/3rd_party/ucos-ii/Source/os_tmr.d ./qm/qpc/3rd_party/ucos-ii/Source/os_tmr.o ./qm/qpc/3rd_party/ucos-ii/Source/os_tmr.su ./qm/qpc/3rd_party/ucos-ii/Source/ucos_ii.d ./qm/qpc/3rd_party/ucos-ii/Source/ucos_ii.o ./qm/qpc/3rd_party/ucos-ii/Source/ucos_ii.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-ucos-2d-ii-2f-Source


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_initialize_low_level.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_misra.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_restore.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_save.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_control.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_disable.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_restore.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_schedule.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_stack_build.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_system_return.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_timer_interrupt.s 

C_SRCS += \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_iar.c 

OBJS += \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_iar.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_initialize_low_level.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_misra.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_restore.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_save.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_control.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_disable.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_restore.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_schedule.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_stack_build.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_system_return.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_timer_interrupt.o 

S_DEPS += \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_initialize_low_level.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_misra.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_restore.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_save.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_control.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_disable.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_restore.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_schedule.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_stack_build.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_system_return.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_timer_interrupt.d 

C_DEPS += \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_iar.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/%.o qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/%.su: ../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/%.c qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/%.o: ../qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/%.s qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-threadx-2f-ports-2f-cortex_m4-2f-iar-2f-src

clean-qm-2f-qpc-2f-3rd_party-2f-threadx-2f-ports-2f-cortex_m4-2f-iar-2f-src:
	-$(RM) ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_iar.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_iar.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_iar.su ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_initialize_low_level.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_initialize_low_level.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_misra.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_misra.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_restore.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_restore.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_save.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_context_save.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_control.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_control.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_disable.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_disable.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_restore.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_interrupt_restore.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_schedule.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_schedule.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_stack_build.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_stack_build.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_system_return.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_thread_system_return.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_timer_interrupt.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/iar/src/tx_timer_interrupt.o

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-threadx-2f-ports-2f-cortex_m4-2f-iar-2f-src


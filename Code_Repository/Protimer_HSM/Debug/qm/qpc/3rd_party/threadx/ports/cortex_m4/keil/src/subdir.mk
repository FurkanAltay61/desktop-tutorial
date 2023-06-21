################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_initialize_low_level.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_restore.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_save.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_control.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_disable.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_restore.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_schedule.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_stack_build.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_system_return.s \
../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_timer_interrupt.s 

OBJS += \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_initialize_low_level.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_restore.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_save.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_control.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_disable.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_restore.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_schedule.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_stack_build.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_system_return.o \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_timer_interrupt.o 

S_DEPS += \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_initialize_low_level.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_restore.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_save.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_control.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_disable.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_restore.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_schedule.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_stack_build.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_system_return.d \
./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_timer_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/%.o: ../qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/%.s qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-threadx-2f-ports-2f-cortex_m4-2f-keil-2f-src

clean-qm-2f-qpc-2f-3rd_party-2f-threadx-2f-ports-2f-cortex_m4-2f-keil-2f-src:
	-$(RM) ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_initialize_low_level.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_initialize_low_level.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_restore.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_restore.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_save.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_context_save.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_control.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_control.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_disable.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_disable.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_restore.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_interrupt_restore.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_schedule.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_schedule.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_stack_build.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_stack_build.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_system_return.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_thread_system_return.o ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_timer_interrupt.d ./qm/qpc/3rd_party/threadx/ports/cortex_m4/keil/src/tx_timer_interrupt.o

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-threadx-2f-ports-2f-cortex_m4-2f-keil-2f-src


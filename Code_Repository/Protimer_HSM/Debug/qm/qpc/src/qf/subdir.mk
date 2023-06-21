################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/src/qf/qep_hsm.c \
../qm/qpc/src/qf/qep_msm.c \
../qm/qpc/src/qf/qf_act.c \
../qm/qpc/src/qf/qf_actq.c \
../qm/qpc/src/qf/qf_defer.c \
../qm/qpc/src/qf/qf_dyn.c \
../qm/qpc/src/qf/qf_mem.c \
../qm/qpc/src/qf/qf_ps.c \
../qm/qpc/src/qf/qf_qact.c \
../qm/qpc/src/qf/qf_qeq.c \
../qm/qpc/src/qf/qf_qmact.c \
../qm/qpc/src/qf/qf_time.c 

OBJS += \
./qm/qpc/src/qf/qep_hsm.o \
./qm/qpc/src/qf/qep_msm.o \
./qm/qpc/src/qf/qf_act.o \
./qm/qpc/src/qf/qf_actq.o \
./qm/qpc/src/qf/qf_defer.o \
./qm/qpc/src/qf/qf_dyn.o \
./qm/qpc/src/qf/qf_mem.o \
./qm/qpc/src/qf/qf_ps.o \
./qm/qpc/src/qf/qf_qact.o \
./qm/qpc/src/qf/qf_qeq.o \
./qm/qpc/src/qf/qf_qmact.o \
./qm/qpc/src/qf/qf_time.o 

C_DEPS += \
./qm/qpc/src/qf/qep_hsm.d \
./qm/qpc/src/qf/qep_msm.d \
./qm/qpc/src/qf/qf_act.d \
./qm/qpc/src/qf/qf_actq.d \
./qm/qpc/src/qf/qf_defer.d \
./qm/qpc/src/qf/qf_dyn.d \
./qm/qpc/src/qf/qf_mem.d \
./qm/qpc/src/qf/qf_ps.d \
./qm/qpc/src/qf/qf_qact.d \
./qm/qpc/src/qf/qf_qeq.d \
./qm/qpc/src/qf/qf_qmact.d \
./qm/qpc/src/qf/qf_time.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/src/qf/%.o qm/qpc/src/qf/%.su: ../qm/qpc/src/qf/%.c qm/qpc/src/qf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/qp/qpc/ports/arm7-9/qk/gnu" -I"C:/qp/qpc/ports/arm7-9/qv/gnu" -I"C:/qp/qpc/include" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-src-2f-qf

clean-qm-2f-qpc-2f-src-2f-qf:
	-$(RM) ./qm/qpc/src/qf/qep_hsm.d ./qm/qpc/src/qf/qep_hsm.o ./qm/qpc/src/qf/qep_hsm.su ./qm/qpc/src/qf/qep_msm.d ./qm/qpc/src/qf/qep_msm.o ./qm/qpc/src/qf/qep_msm.su ./qm/qpc/src/qf/qf_act.d ./qm/qpc/src/qf/qf_act.o ./qm/qpc/src/qf/qf_act.su ./qm/qpc/src/qf/qf_actq.d ./qm/qpc/src/qf/qf_actq.o ./qm/qpc/src/qf/qf_actq.su ./qm/qpc/src/qf/qf_defer.d ./qm/qpc/src/qf/qf_defer.o ./qm/qpc/src/qf/qf_defer.su ./qm/qpc/src/qf/qf_dyn.d ./qm/qpc/src/qf/qf_dyn.o ./qm/qpc/src/qf/qf_dyn.su ./qm/qpc/src/qf/qf_mem.d ./qm/qpc/src/qf/qf_mem.o ./qm/qpc/src/qf/qf_mem.su ./qm/qpc/src/qf/qf_ps.d ./qm/qpc/src/qf/qf_ps.o ./qm/qpc/src/qf/qf_ps.su ./qm/qpc/src/qf/qf_qact.d ./qm/qpc/src/qf/qf_qact.o ./qm/qpc/src/qf/qf_qact.su ./qm/qpc/src/qf/qf_qeq.d ./qm/qpc/src/qf/qf_qeq.o ./qm/qpc/src/qf/qf_qeq.su ./qm/qpc/src/qf/qf_qmact.d ./qm/qpc/src/qf/qf_qmact.o ./qm/qpc/src/qf/qf_qmact.su ./qm/qpc/src/qf/qf_time.d ./qm/qpc/src/qf/qf_time.o ./qm/qpc/src/qf/qf_time.su

.PHONY: clean-qm-2f-qpc-2f-src-2f-qf


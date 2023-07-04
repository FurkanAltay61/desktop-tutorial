################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../QPC/Src/qep_hsm.c \
../QPC/Src/qep_msm.c \
../QPC/Src/qf_act.c \
../QPC/Src/qf_actq.c \
../QPC/Src/qf_defer.c \
../QPC/Src/qf_dyn.c \
../QPC/Src/qf_mem.c \
../QPC/Src/qf_ps.c \
../QPC/Src/qf_qact.c \
../QPC/Src/qf_qeq.c \
../QPC/Src/qf_qmact.c \
../QPC/Src/qf_time.c \
../QPC/Src/qv.c \
../QPC/Src/qv_port.c 

OBJS += \
./QPC/Src/qep_hsm.o \
./QPC/Src/qep_msm.o \
./QPC/Src/qf_act.o \
./QPC/Src/qf_actq.o \
./QPC/Src/qf_defer.o \
./QPC/Src/qf_dyn.o \
./QPC/Src/qf_mem.o \
./QPC/Src/qf_ps.o \
./QPC/Src/qf_qact.o \
./QPC/Src/qf_qeq.o \
./QPC/Src/qf_qmact.o \
./QPC/Src/qf_time.o \
./QPC/Src/qv.o \
./QPC/Src/qv_port.o 

C_DEPS += \
./QPC/Src/qep_hsm.d \
./QPC/Src/qep_msm.d \
./QPC/Src/qf_act.d \
./QPC/Src/qf_actq.d \
./QPC/Src/qf_defer.d \
./QPC/Src/qf_dyn.d \
./QPC/Src/qf_mem.d \
./QPC/Src/qf_ps.d \
./QPC/Src/qf_qact.d \
./QPC/Src/qf_qeq.d \
./QPC/Src/qf_qmact.d \
./QPC/Src/qf_time.d \
./QPC/Src/qv.d \
./QPC/Src/qv_port.d 


# Each subdirectory must supply rules for building sources it contributes
QPC/Src/%.o QPC/Src/%.su QPC/Src/%.cyclo: ../QPC/Src/%.c QPC/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"/home/furkan/Desktop/desktop-tutorial/Code_Repository/TimeBomb_QHSM_Auto/QPC_Port" -I"/home/furkan/Desktop/desktop-tutorial/Code_Repository/TimeBomb_QHSM_Auto/QPC/Inc" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"/home/furkan/Desktop/desktop-tutorial/Code_Repository/TimeBomb_QHSM_Auto/User/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-QPC-2f-Src

clean-QPC-2f-Src:
	-$(RM) ./QPC/Src/qep_hsm.cyclo ./QPC/Src/qep_hsm.d ./QPC/Src/qep_hsm.o ./QPC/Src/qep_hsm.su ./QPC/Src/qep_msm.cyclo ./QPC/Src/qep_msm.d ./QPC/Src/qep_msm.o ./QPC/Src/qep_msm.su ./QPC/Src/qf_act.cyclo ./QPC/Src/qf_act.d ./QPC/Src/qf_act.o ./QPC/Src/qf_act.su ./QPC/Src/qf_actq.cyclo ./QPC/Src/qf_actq.d ./QPC/Src/qf_actq.o ./QPC/Src/qf_actq.su ./QPC/Src/qf_defer.cyclo ./QPC/Src/qf_defer.d ./QPC/Src/qf_defer.o ./QPC/Src/qf_defer.su ./QPC/Src/qf_dyn.cyclo ./QPC/Src/qf_dyn.d ./QPC/Src/qf_dyn.o ./QPC/Src/qf_dyn.su ./QPC/Src/qf_mem.cyclo ./QPC/Src/qf_mem.d ./QPC/Src/qf_mem.o ./QPC/Src/qf_mem.su ./QPC/Src/qf_ps.cyclo ./QPC/Src/qf_ps.d ./QPC/Src/qf_ps.o ./QPC/Src/qf_ps.su ./QPC/Src/qf_qact.cyclo ./QPC/Src/qf_qact.d ./QPC/Src/qf_qact.o ./QPC/Src/qf_qact.su ./QPC/Src/qf_qeq.cyclo ./QPC/Src/qf_qeq.d ./QPC/Src/qf_qeq.o ./QPC/Src/qf_qeq.su ./QPC/Src/qf_qmact.cyclo ./QPC/Src/qf_qmact.d ./QPC/Src/qf_qmact.o ./QPC/Src/qf_qmact.su ./QPC/Src/qf_time.cyclo ./QPC/Src/qf_time.d ./QPC/Src/qf_time.o ./QPC/Src/qf_time.su ./QPC/Src/qv.cyclo ./QPC/Src/qv.d ./QPC/Src/qv.o ./QPC/Src/qv.su ./QPC/Src/qv_port.cyclo ./QPC/Src/qv_port.d ./QPC/Src/qv_port.o ./QPC/Src/qv_port.su

.PHONY: clean-QPC-2f-Src


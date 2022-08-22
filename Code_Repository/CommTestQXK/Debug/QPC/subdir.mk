################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../QPC/qep_hsm.c \
../QPC/qep_msm.c \
../QPC/qf_act.c \
../QPC/qf_actq.c \
../QPC/qf_defer.c \
../QPC/qf_dyn.c \
../QPC/qf_mem.c \
../QPC/qf_ps.c \
../QPC/qf_qact.c \
../QPC/qf_qeq.c \
../QPC/qf_qmact.c \
../QPC/qf_time.c 

OBJS += \
./QPC/qep_hsm.o \
./QPC/qep_msm.o \
./QPC/qf_act.o \
./QPC/qf_actq.o \
./QPC/qf_defer.o \
./QPC/qf_dyn.o \
./QPC/qf_mem.o \
./QPC/qf_ps.o \
./QPC/qf_qact.o \
./QPC/qf_qeq.o \
./QPC/qf_qmact.o \
./QPC/qf_time.o 

C_DEPS += \
./QPC/qep_hsm.d \
./QPC/qep_msm.d \
./QPC/qf_act.d \
./QPC/qf_actq.d \
./QPC/qf_defer.d \
./QPC/qf_dyn.d \
./QPC/qf_mem.d \
./QPC/qf_ps.d \
./QPC/qf_qact.d \
./QPC/qf_qeq.d \
./QPC/qf_qmact.d \
./QPC/qf_time.d 


# Each subdirectory must supply rules for building sources it contributes
QPC/%.o QPC/%.su: ../QPC/%.c QPC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/QPC_PORT" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/User/Inc" -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I"C:/qp/qpc/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-QPC

clean-QPC:
	-$(RM) ./QPC/qep_hsm.d ./QPC/qep_hsm.o ./QPC/qep_hsm.su ./QPC/qep_msm.d ./QPC/qep_msm.o ./QPC/qep_msm.su ./QPC/qf_act.d ./QPC/qf_act.o ./QPC/qf_act.su ./QPC/qf_actq.d ./QPC/qf_actq.o ./QPC/qf_actq.su ./QPC/qf_defer.d ./QPC/qf_defer.o ./QPC/qf_defer.su ./QPC/qf_dyn.d ./QPC/qf_dyn.o ./QPC/qf_dyn.su ./QPC/qf_mem.d ./QPC/qf_mem.o ./QPC/qf_mem.su ./QPC/qf_ps.d ./QPC/qf_ps.o ./QPC/qf_ps.su ./QPC/qf_qact.d ./QPC/qf_qact.o ./QPC/qf_qact.su ./QPC/qf_qeq.d ./QPC/qf_qeq.o ./QPC/qf_qeq.su ./QPC/qf_qmact.d ./QPC/qf_qmact.o ./QPC/qf_qmact.su ./QPC/qf_time.d ./QPC/qf_time.o ./QPC/qf_time.su

.PHONY: clean-QPC


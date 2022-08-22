################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../QPC/Src/qf/qep_hsm.c \
../QPC/Src/qf/qep_msm.c \
../QPC/Src/qf/qf_act.c \
../QPC/Src/qf/qf_actq.c \
../QPC/Src/qf/qf_defer.c \
../QPC/Src/qf/qf_dyn.c \
../QPC/Src/qf/qf_mem.c \
../QPC/Src/qf/qf_ps.c \
../QPC/Src/qf/qf_qact.c \
../QPC/Src/qf/qf_qeq.c \
../QPC/Src/qf/qf_qmact.c \
../QPC/Src/qf/qf_time.c 

OBJS += \
./QPC/Src/qf/qep_hsm.o \
./QPC/Src/qf/qep_msm.o \
./QPC/Src/qf/qf_act.o \
./QPC/Src/qf/qf_actq.o \
./QPC/Src/qf/qf_defer.o \
./QPC/Src/qf/qf_dyn.o \
./QPC/Src/qf/qf_mem.o \
./QPC/Src/qf/qf_ps.o \
./QPC/Src/qf/qf_qact.o \
./QPC/Src/qf/qf_qeq.o \
./QPC/Src/qf/qf_qmact.o \
./QPC/Src/qf/qf_time.o 

C_DEPS += \
./QPC/Src/qf/qep_hsm.d \
./QPC/Src/qf/qep_msm.d \
./QPC/Src/qf/qf_act.d \
./QPC/Src/qf/qf_actq.d \
./QPC/Src/qf/qf_defer.d \
./QPC/Src/qf/qf_dyn.d \
./QPC/Src/qf/qf_mem.d \
./QPC/Src/qf/qf_ps.d \
./QPC/Src/qf/qf_qact.d \
./QPC/Src/qf/qf_qeq.d \
./QPC/Src/qf/qf_qmact.d \
./QPC/Src/qf/qf_time.d 


# Each subdirectory must supply rules for building sources it contributes
QPC/Src/qf/%.o QPC/Src/qf/%.su: ../QPC/Src/qf/%.c QPC/Src/qf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/QPC_Port" -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/QPC/Inc" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/User/Inc" -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-QPC-2f-Src-2f-qf

clean-QPC-2f-Src-2f-qf:
	-$(RM) ./QPC/Src/qf/qep_hsm.d ./QPC/Src/qf/qep_hsm.o ./QPC/Src/qf/qep_hsm.su ./QPC/Src/qf/qep_msm.d ./QPC/Src/qf/qep_msm.o ./QPC/Src/qf/qep_msm.su ./QPC/Src/qf/qf_act.d ./QPC/Src/qf/qf_act.o ./QPC/Src/qf/qf_act.su ./QPC/Src/qf/qf_actq.d ./QPC/Src/qf/qf_actq.o ./QPC/Src/qf/qf_actq.su ./QPC/Src/qf/qf_defer.d ./QPC/Src/qf/qf_defer.o ./QPC/Src/qf/qf_defer.su ./QPC/Src/qf/qf_dyn.d ./QPC/Src/qf/qf_dyn.o ./QPC/Src/qf/qf_dyn.su ./QPC/Src/qf/qf_mem.d ./QPC/Src/qf/qf_mem.o ./QPC/Src/qf/qf_mem.su ./QPC/Src/qf/qf_ps.d ./QPC/Src/qf/qf_ps.o ./QPC/Src/qf/qf_ps.su ./QPC/Src/qf/qf_qact.d ./QPC/Src/qf/qf_qact.o ./QPC/Src/qf/qf_qact.su ./QPC/Src/qf/qf_qeq.d ./QPC/Src/qf/qf_qeq.o ./QPC/Src/qf/qf_qeq.su ./QPC/Src/qf/qf_qmact.d ./QPC/Src/qf/qf_qmact.o ./QPC/Src/qf/qf_qmact.su ./QPC/Src/qf/qf_time.d ./QPC/Src/qf/qf_time.o ./QPC/Src/qf/qf_time.su

.PHONY: clean-QPC-2f-Src-2f-qf


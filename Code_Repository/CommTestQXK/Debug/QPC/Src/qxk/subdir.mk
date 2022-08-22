################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../QPC/Src/qxk/qxk.c \
../QPC/Src/qxk/qxk_mutex.c \
../QPC/Src/qxk/qxk_sema.c \
../QPC/Src/qxk/qxk_xthr.c 

OBJS += \
./QPC/Src/qxk/qxk.o \
./QPC/Src/qxk/qxk_mutex.o \
./QPC/Src/qxk/qxk_sema.o \
./QPC/Src/qxk/qxk_xthr.o 

C_DEPS += \
./QPC/Src/qxk/qxk.d \
./QPC/Src/qxk/qxk_mutex.d \
./QPC/Src/qxk/qxk_sema.d \
./QPC/Src/qxk/qxk_xthr.d 


# Each subdirectory must supply rules for building sources it contributes
QPC/Src/qxk/%.o QPC/Src/qxk/%.su: ../QPC/Src/qxk/%.c QPC/Src/qxk/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/QPC_Port" -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/QPC/Inc" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/CommTestQXK/User/Inc" -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-QPC-2f-Src-2f-qxk

clean-QPC-2f-Src-2f-qxk:
	-$(RM) ./QPC/Src/qxk/qxk.d ./QPC/Src/qxk/qxk.o ./QPC/Src/qxk/qxk.su ./QPC/Src/qxk/qxk_mutex.d ./QPC/Src/qxk/qxk_mutex.o ./QPC/Src/qxk/qxk_mutex.su ./QPC/Src/qxk/qxk_sema.d ./QPC/Src/qxk/qxk_sema.o ./QPC/Src/qxk/qxk_sema.su ./QPC/Src/qxk/qxk_xthr.d ./QPC/Src/qxk/qxk_xthr.o ./QPC/Src/qxk/qxk_xthr.su

.PHONY: clean-QPC-2f-Src-2f-qxk


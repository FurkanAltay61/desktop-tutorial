################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/lwip/src/core/ipv6/icmp6.c \
../qm/qpc/3rd_party/lwip/src/core/ipv6/inet6.c \
../qm/qpc/3rd_party/lwip/src/core/ipv6/ip6.c \
../qm/qpc/3rd_party/lwip/src/core/ipv6/ip6_addr.c 

OBJS += \
./qm/qpc/3rd_party/lwip/src/core/ipv6/icmp6.o \
./qm/qpc/3rd_party/lwip/src/core/ipv6/inet6.o \
./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6.o \
./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6_addr.o 

C_DEPS += \
./qm/qpc/3rd_party/lwip/src/core/ipv6/icmp6.d \
./qm/qpc/3rd_party/lwip/src/core/ipv6/inet6.d \
./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6.d \
./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6_addr.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/lwip/src/core/ipv6/%.o qm/qpc/3rd_party/lwip/src/core/ipv6/%.su: ../qm/qpc/3rd_party/lwip/src/core/ipv6/%.c qm/qpc/3rd_party/lwip/src/core/ipv6/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core-2f-ipv6

clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core-2f-ipv6:
	-$(RM) ./qm/qpc/3rd_party/lwip/src/core/ipv6/icmp6.d ./qm/qpc/3rd_party/lwip/src/core/ipv6/icmp6.o ./qm/qpc/3rd_party/lwip/src/core/ipv6/icmp6.su ./qm/qpc/3rd_party/lwip/src/core/ipv6/inet6.d ./qm/qpc/3rd_party/lwip/src/core/ipv6/inet6.o ./qm/qpc/3rd_party/lwip/src/core/ipv6/inet6.su ./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6.d ./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6.o ./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6.su ./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6_addr.d ./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6_addr.o ./qm/qpc/3rd_party/lwip/src/core/ipv6/ip6_addr.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core-2f-ipv6


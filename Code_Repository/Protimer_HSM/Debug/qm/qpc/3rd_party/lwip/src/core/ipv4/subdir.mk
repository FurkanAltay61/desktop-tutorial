################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/lwip/src/core/ipv4/autoip.c \
../qm/qpc/3rd_party/lwip/src/core/ipv4/icmp.c \
../qm/qpc/3rd_party/lwip/src/core/ipv4/igmp.c \
../qm/qpc/3rd_party/lwip/src/core/ipv4/inet.c \
../qm/qpc/3rd_party/lwip/src/core/ipv4/inet_chksum.c \
../qm/qpc/3rd_party/lwip/src/core/ipv4/ip.c \
../qm/qpc/3rd_party/lwip/src/core/ipv4/ip_addr.c \
../qm/qpc/3rd_party/lwip/src/core/ipv4/ip_frag.c 

OBJS += \
./qm/qpc/3rd_party/lwip/src/core/ipv4/autoip.o \
./qm/qpc/3rd_party/lwip/src/core/ipv4/icmp.o \
./qm/qpc/3rd_party/lwip/src/core/ipv4/igmp.o \
./qm/qpc/3rd_party/lwip/src/core/ipv4/inet.o \
./qm/qpc/3rd_party/lwip/src/core/ipv4/inet_chksum.o \
./qm/qpc/3rd_party/lwip/src/core/ipv4/ip.o \
./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_addr.o \
./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_frag.o 

C_DEPS += \
./qm/qpc/3rd_party/lwip/src/core/ipv4/autoip.d \
./qm/qpc/3rd_party/lwip/src/core/ipv4/icmp.d \
./qm/qpc/3rd_party/lwip/src/core/ipv4/igmp.d \
./qm/qpc/3rd_party/lwip/src/core/ipv4/inet.d \
./qm/qpc/3rd_party/lwip/src/core/ipv4/inet_chksum.d \
./qm/qpc/3rd_party/lwip/src/core/ipv4/ip.d \
./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_addr.d \
./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_frag.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/lwip/src/core/ipv4/%.o qm/qpc/3rd_party/lwip/src/core/ipv4/%.su: ../qm/qpc/3rd_party/lwip/src/core/ipv4/%.c qm/qpc/3rd_party/lwip/src/core/ipv4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core-2f-ipv4

clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core-2f-ipv4:
	-$(RM) ./qm/qpc/3rd_party/lwip/src/core/ipv4/autoip.d ./qm/qpc/3rd_party/lwip/src/core/ipv4/autoip.o ./qm/qpc/3rd_party/lwip/src/core/ipv4/autoip.su ./qm/qpc/3rd_party/lwip/src/core/ipv4/icmp.d ./qm/qpc/3rd_party/lwip/src/core/ipv4/icmp.o ./qm/qpc/3rd_party/lwip/src/core/ipv4/icmp.su ./qm/qpc/3rd_party/lwip/src/core/ipv4/igmp.d ./qm/qpc/3rd_party/lwip/src/core/ipv4/igmp.o ./qm/qpc/3rd_party/lwip/src/core/ipv4/igmp.su ./qm/qpc/3rd_party/lwip/src/core/ipv4/inet.d ./qm/qpc/3rd_party/lwip/src/core/ipv4/inet.o ./qm/qpc/3rd_party/lwip/src/core/ipv4/inet.su ./qm/qpc/3rd_party/lwip/src/core/ipv4/inet_chksum.d ./qm/qpc/3rd_party/lwip/src/core/ipv4/inet_chksum.o ./qm/qpc/3rd_party/lwip/src/core/ipv4/inet_chksum.su ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip.d ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip.o ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip.su ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_addr.d ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_addr.o ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_addr.su ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_frag.d ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_frag.o ./qm/qpc/3rd_party/lwip/src/core/ipv4/ip_frag.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core-2f-ipv4


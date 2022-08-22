################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/lwip/src/core/def.c \
../qm/qpc/3rd_party/lwip/src/core/dhcp.c \
../qm/qpc/3rd_party/lwip/src/core/dns.c \
../qm/qpc/3rd_party/lwip/src/core/init.c \
../qm/qpc/3rd_party/lwip/src/core/mem.c \
../qm/qpc/3rd_party/lwip/src/core/memp.c \
../qm/qpc/3rd_party/lwip/src/core/netif.c \
../qm/qpc/3rd_party/lwip/src/core/pbuf.c \
../qm/qpc/3rd_party/lwip/src/core/raw.c \
../qm/qpc/3rd_party/lwip/src/core/stats.c \
../qm/qpc/3rd_party/lwip/src/core/sys.c \
../qm/qpc/3rd_party/lwip/src/core/tcp.c \
../qm/qpc/3rd_party/lwip/src/core/tcp_in.c \
../qm/qpc/3rd_party/lwip/src/core/tcp_out.c \
../qm/qpc/3rd_party/lwip/src/core/timers.c \
../qm/qpc/3rd_party/lwip/src/core/udp.c 

OBJS += \
./qm/qpc/3rd_party/lwip/src/core/def.o \
./qm/qpc/3rd_party/lwip/src/core/dhcp.o \
./qm/qpc/3rd_party/lwip/src/core/dns.o \
./qm/qpc/3rd_party/lwip/src/core/init.o \
./qm/qpc/3rd_party/lwip/src/core/mem.o \
./qm/qpc/3rd_party/lwip/src/core/memp.o \
./qm/qpc/3rd_party/lwip/src/core/netif.o \
./qm/qpc/3rd_party/lwip/src/core/pbuf.o \
./qm/qpc/3rd_party/lwip/src/core/raw.o \
./qm/qpc/3rd_party/lwip/src/core/stats.o \
./qm/qpc/3rd_party/lwip/src/core/sys.o \
./qm/qpc/3rd_party/lwip/src/core/tcp.o \
./qm/qpc/3rd_party/lwip/src/core/tcp_in.o \
./qm/qpc/3rd_party/lwip/src/core/tcp_out.o \
./qm/qpc/3rd_party/lwip/src/core/timers.o \
./qm/qpc/3rd_party/lwip/src/core/udp.o 

C_DEPS += \
./qm/qpc/3rd_party/lwip/src/core/def.d \
./qm/qpc/3rd_party/lwip/src/core/dhcp.d \
./qm/qpc/3rd_party/lwip/src/core/dns.d \
./qm/qpc/3rd_party/lwip/src/core/init.d \
./qm/qpc/3rd_party/lwip/src/core/mem.d \
./qm/qpc/3rd_party/lwip/src/core/memp.d \
./qm/qpc/3rd_party/lwip/src/core/netif.d \
./qm/qpc/3rd_party/lwip/src/core/pbuf.d \
./qm/qpc/3rd_party/lwip/src/core/raw.d \
./qm/qpc/3rd_party/lwip/src/core/stats.d \
./qm/qpc/3rd_party/lwip/src/core/sys.d \
./qm/qpc/3rd_party/lwip/src/core/tcp.d \
./qm/qpc/3rd_party/lwip/src/core/tcp_in.d \
./qm/qpc/3rd_party/lwip/src/core/tcp_out.d \
./qm/qpc/3rd_party/lwip/src/core/timers.d \
./qm/qpc/3rd_party/lwip/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/lwip/src/core/%.o qm/qpc/3rd_party/lwip/src/core/%.su: ../qm/qpc/3rd_party/lwip/src/core/%.c qm/qpc/3rd_party/lwip/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core

clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core:
	-$(RM) ./qm/qpc/3rd_party/lwip/src/core/def.d ./qm/qpc/3rd_party/lwip/src/core/def.o ./qm/qpc/3rd_party/lwip/src/core/def.su ./qm/qpc/3rd_party/lwip/src/core/dhcp.d ./qm/qpc/3rd_party/lwip/src/core/dhcp.o ./qm/qpc/3rd_party/lwip/src/core/dhcp.su ./qm/qpc/3rd_party/lwip/src/core/dns.d ./qm/qpc/3rd_party/lwip/src/core/dns.o ./qm/qpc/3rd_party/lwip/src/core/dns.su ./qm/qpc/3rd_party/lwip/src/core/init.d ./qm/qpc/3rd_party/lwip/src/core/init.o ./qm/qpc/3rd_party/lwip/src/core/init.su ./qm/qpc/3rd_party/lwip/src/core/mem.d ./qm/qpc/3rd_party/lwip/src/core/mem.o ./qm/qpc/3rd_party/lwip/src/core/mem.su ./qm/qpc/3rd_party/lwip/src/core/memp.d ./qm/qpc/3rd_party/lwip/src/core/memp.o ./qm/qpc/3rd_party/lwip/src/core/memp.su ./qm/qpc/3rd_party/lwip/src/core/netif.d ./qm/qpc/3rd_party/lwip/src/core/netif.o ./qm/qpc/3rd_party/lwip/src/core/netif.su ./qm/qpc/3rd_party/lwip/src/core/pbuf.d ./qm/qpc/3rd_party/lwip/src/core/pbuf.o ./qm/qpc/3rd_party/lwip/src/core/pbuf.su ./qm/qpc/3rd_party/lwip/src/core/raw.d ./qm/qpc/3rd_party/lwip/src/core/raw.o ./qm/qpc/3rd_party/lwip/src/core/raw.su ./qm/qpc/3rd_party/lwip/src/core/stats.d ./qm/qpc/3rd_party/lwip/src/core/stats.o ./qm/qpc/3rd_party/lwip/src/core/stats.su ./qm/qpc/3rd_party/lwip/src/core/sys.d ./qm/qpc/3rd_party/lwip/src/core/sys.o ./qm/qpc/3rd_party/lwip/src/core/sys.su ./qm/qpc/3rd_party/lwip/src/core/tcp.d ./qm/qpc/3rd_party/lwip/src/core/tcp.o ./qm/qpc/3rd_party/lwip/src/core/tcp.su ./qm/qpc/3rd_party/lwip/src/core/tcp_in.d ./qm/qpc/3rd_party/lwip/src/core/tcp_in.o ./qm/qpc/3rd_party/lwip/src/core/tcp_in.su ./qm/qpc/3rd_party/lwip/src/core/tcp_out.d ./qm/qpc/3rd_party/lwip/src/core/tcp_out.o ./qm/qpc/3rd_party/lwip/src/core/tcp_out.su ./qm/qpc/3rd_party/lwip/src/core/timers.d ./qm/qpc/3rd_party/lwip/src/core/timers.o ./qm/qpc/3rd_party/lwip/src/core/timers.su ./qm/qpc/3rd_party/lwip/src/core/udp.d ./qm/qpc/3rd_party/lwip/src/core/udp.o ./qm/qpc/3rd_party/lwip/src/core/udp.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-core


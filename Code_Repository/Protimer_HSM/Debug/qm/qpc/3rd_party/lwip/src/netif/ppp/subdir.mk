################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/lwip/src/netif/ppp/auth.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/chap.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/chpms.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/fsm.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/ipcp.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/lcp.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/magic.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/md5.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/pap.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/ppp.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/ppp_oe.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/randm.c \
../qm/qpc/3rd_party/lwip/src/netif/ppp/vj.c 

OBJS += \
./qm/qpc/3rd_party/lwip/src/netif/ppp/auth.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/chap.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/chpms.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/fsm.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/ipcp.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/lcp.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/magic.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/md5.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/pap.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp_oe.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/randm.o \
./qm/qpc/3rd_party/lwip/src/netif/ppp/vj.o 

C_DEPS += \
./qm/qpc/3rd_party/lwip/src/netif/ppp/auth.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/chap.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/chpms.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/fsm.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/ipcp.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/lcp.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/magic.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/md5.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/pap.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp_oe.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/randm.d \
./qm/qpc/3rd_party/lwip/src/netif/ppp/vj.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/lwip/src/netif/ppp/%.o qm/qpc/3rd_party/lwip/src/netif/ppp/%.su: ../qm/qpc/3rd_party/lwip/src/netif/ppp/%.c qm/qpc/3rd_party/lwip/src/netif/ppp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-netif-2f-ppp

clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-netif-2f-ppp:
	-$(RM) ./qm/qpc/3rd_party/lwip/src/netif/ppp/auth.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/auth.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/auth.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/chap.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/chap.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/chap.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/chpms.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/chpms.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/chpms.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/fsm.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/fsm.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/fsm.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/ipcp.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/ipcp.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/ipcp.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/lcp.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/lcp.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/lcp.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/magic.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/magic.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/magic.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/md5.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/md5.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/md5.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/pap.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/pap.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/pap.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp_oe.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp_oe.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/ppp_oe.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/randm.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/randm.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/randm.su ./qm/qpc/3rd_party/lwip/src/netif/ppp/vj.d ./qm/qpc/3rd_party/lwip/src/netif/ppp/vj.o ./qm/qpc/3rd_party/lwip/src/netif/ppp/vj.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-netif-2f-ppp


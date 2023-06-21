################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/lwip/src/api/api_lib.c \
../qm/qpc/3rd_party/lwip/src/api/api_msg.c \
../qm/qpc/3rd_party/lwip/src/api/err.c \
../qm/qpc/3rd_party/lwip/src/api/netbuf.c \
../qm/qpc/3rd_party/lwip/src/api/netdb.c \
../qm/qpc/3rd_party/lwip/src/api/netifapi.c \
../qm/qpc/3rd_party/lwip/src/api/sockets.c \
../qm/qpc/3rd_party/lwip/src/api/tcpip.c 

OBJS += \
./qm/qpc/3rd_party/lwip/src/api/api_lib.o \
./qm/qpc/3rd_party/lwip/src/api/api_msg.o \
./qm/qpc/3rd_party/lwip/src/api/err.o \
./qm/qpc/3rd_party/lwip/src/api/netbuf.o \
./qm/qpc/3rd_party/lwip/src/api/netdb.o \
./qm/qpc/3rd_party/lwip/src/api/netifapi.o \
./qm/qpc/3rd_party/lwip/src/api/sockets.o \
./qm/qpc/3rd_party/lwip/src/api/tcpip.o 

C_DEPS += \
./qm/qpc/3rd_party/lwip/src/api/api_lib.d \
./qm/qpc/3rd_party/lwip/src/api/api_msg.d \
./qm/qpc/3rd_party/lwip/src/api/err.d \
./qm/qpc/3rd_party/lwip/src/api/netbuf.d \
./qm/qpc/3rd_party/lwip/src/api/netdb.d \
./qm/qpc/3rd_party/lwip/src/api/netifapi.d \
./qm/qpc/3rd_party/lwip/src/api/sockets.d \
./qm/qpc/3rd_party/lwip/src/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/lwip/src/api/%.o qm/qpc/3rd_party/lwip/src/api/%.su: ../qm/qpc/3rd_party/lwip/src/api/%.c qm/qpc/3rd_party/lwip/src/api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-api

clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-api:
	-$(RM) ./qm/qpc/3rd_party/lwip/src/api/api_lib.d ./qm/qpc/3rd_party/lwip/src/api/api_lib.o ./qm/qpc/3rd_party/lwip/src/api/api_lib.su ./qm/qpc/3rd_party/lwip/src/api/api_msg.d ./qm/qpc/3rd_party/lwip/src/api/api_msg.o ./qm/qpc/3rd_party/lwip/src/api/api_msg.su ./qm/qpc/3rd_party/lwip/src/api/err.d ./qm/qpc/3rd_party/lwip/src/api/err.o ./qm/qpc/3rd_party/lwip/src/api/err.su ./qm/qpc/3rd_party/lwip/src/api/netbuf.d ./qm/qpc/3rd_party/lwip/src/api/netbuf.o ./qm/qpc/3rd_party/lwip/src/api/netbuf.su ./qm/qpc/3rd_party/lwip/src/api/netdb.d ./qm/qpc/3rd_party/lwip/src/api/netdb.o ./qm/qpc/3rd_party/lwip/src/api/netdb.su ./qm/qpc/3rd_party/lwip/src/api/netifapi.d ./qm/qpc/3rd_party/lwip/src/api/netifapi.o ./qm/qpc/3rd_party/lwip/src/api/netifapi.su ./qm/qpc/3rd_party/lwip/src/api/sockets.d ./qm/qpc/3rd_party/lwip/src/api/sockets.o ./qm/qpc/3rd_party/lwip/src/api/sockets.su ./qm/qpc/3rd_party/lwip/src/api/tcpip.d ./qm/qpc/3rd_party/lwip/src/api/tcpip.o ./qm/qpc/3rd_party/lwip/src/api/tcpip.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-lwip-2f-src-2f-api


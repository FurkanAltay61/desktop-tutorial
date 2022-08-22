################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.c \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.c \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.c \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c \
../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c 

OBJS += \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.o \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.o \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.o \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.o \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.o \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.o \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.o \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.o \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.o 

C_DEPS += \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.d \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.d \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.d \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.d \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.d \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.d \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.d \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.d \
./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/%.o qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/%.su: ../qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/%.c qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-stm32f7-2d-discovery-2f-Drivers-2f-BSP-2f-STM32746G-2d-Discovery

clean-qm-2f-qpc-2f-3rd_party-2f-stm32f7-2d-discovery-2f-Drivers-2f-BSP-2f-STM32746G-2d-Discovery:
	-$(RM) ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.su ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.su ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.su ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.su ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.su ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.su ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.su ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.su ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.d ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.o ./qm/qpc/3rd_party/stm32f7-discovery/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-stm32f7-2d-discovery-2f-Drivers-2f-BSP-2f-STM32746G-2d-Discovery


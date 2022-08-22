################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/arm-cm/game_efm32-slstk3401a/main.c \
../qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine1.c \
../qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine2.c \
../qm/qpc/examples/arm-cm/game_efm32-slstk3401a/missile.c \
../qm/qpc/examples/arm-cm/game_efm32-slstk3401a/ship.c \
../qm/qpc/examples/arm-cm/game_efm32-slstk3401a/tunnel.c 

OBJS += \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/main.o \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine1.o \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine2.o \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/missile.o \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/ship.o \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/tunnel.o 

C_DEPS += \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/main.d \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine1.d \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine2.d \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/missile.d \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/ship.d \
./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/tunnel.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/arm-cm/game_efm32-slstk3401a/%.o qm/qpc/examples/arm-cm/game_efm32-slstk3401a/%.su: ../qm/qpc/examples/arm-cm/game_efm32-slstk3401a/%.c qm/qpc/examples/arm-cm/game_efm32-slstk3401a/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-arm-2d-cm-2f-game_efm32-2d-slstk3401a

clean-qm-2f-qpc-2f-examples-2f-arm-2d-cm-2f-game_efm32-2d-slstk3401a:
	-$(RM) ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/main.d ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/main.o ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/main.su ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine1.d ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine1.o ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine1.su ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine2.d ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine2.o ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/mine2.su ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/missile.d ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/missile.o ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/missile.su ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/ship.d ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/ship.o ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/ship.su ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/tunnel.d ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/tunnel.o ./qm/qpc/examples/arm-cm/game_efm32-slstk3401a/tunnel.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-arm-2d-cm-2f-game_efm32-2d-slstk3401a


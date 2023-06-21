################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/efm32pg1b/display_ls013b7dh03.c \
../qm/qpc/3rd_party/efm32pg1b/displaypalemlib.c \
../qm/qpc/3rd_party/efm32pg1b/em_assert.c \
../qm/qpc/3rd_party/efm32pg1b/em_cmu.c \
../qm/qpc/3rd_party/efm32pg1b/em_emu.c \
../qm/qpc/3rd_party/efm32pg1b/em_gpio.c \
../qm/qpc/3rd_party/efm32pg1b/em_int.c \
../qm/qpc/3rd_party/efm32pg1b/em_prs.c \
../qm/qpc/3rd_party/efm32pg1b/em_rtcc.c \
../qm/qpc/3rd_party/efm32pg1b/em_system.c \
../qm/qpc/3rd_party/efm32pg1b/em_usart.c \
../qm/qpc/3rd_party/efm32pg1b/system_efm32pg1b.c \
../qm/qpc/3rd_party/efm32pg1b/udelay.c 

OBJS += \
./qm/qpc/3rd_party/efm32pg1b/display_ls013b7dh03.o \
./qm/qpc/3rd_party/efm32pg1b/displaypalemlib.o \
./qm/qpc/3rd_party/efm32pg1b/em_assert.o \
./qm/qpc/3rd_party/efm32pg1b/em_cmu.o \
./qm/qpc/3rd_party/efm32pg1b/em_emu.o \
./qm/qpc/3rd_party/efm32pg1b/em_gpio.o \
./qm/qpc/3rd_party/efm32pg1b/em_int.o \
./qm/qpc/3rd_party/efm32pg1b/em_prs.o \
./qm/qpc/3rd_party/efm32pg1b/em_rtcc.o \
./qm/qpc/3rd_party/efm32pg1b/em_system.o \
./qm/qpc/3rd_party/efm32pg1b/em_usart.o \
./qm/qpc/3rd_party/efm32pg1b/system_efm32pg1b.o \
./qm/qpc/3rd_party/efm32pg1b/udelay.o 

C_DEPS += \
./qm/qpc/3rd_party/efm32pg1b/display_ls013b7dh03.d \
./qm/qpc/3rd_party/efm32pg1b/displaypalemlib.d \
./qm/qpc/3rd_party/efm32pg1b/em_assert.d \
./qm/qpc/3rd_party/efm32pg1b/em_cmu.d \
./qm/qpc/3rd_party/efm32pg1b/em_emu.d \
./qm/qpc/3rd_party/efm32pg1b/em_gpio.d \
./qm/qpc/3rd_party/efm32pg1b/em_int.d \
./qm/qpc/3rd_party/efm32pg1b/em_prs.d \
./qm/qpc/3rd_party/efm32pg1b/em_rtcc.d \
./qm/qpc/3rd_party/efm32pg1b/em_system.d \
./qm/qpc/3rd_party/efm32pg1b/em_usart.d \
./qm/qpc/3rd_party/efm32pg1b/system_efm32pg1b.d \
./qm/qpc/3rd_party/efm32pg1b/udelay.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/efm32pg1b/%.o qm/qpc/3rd_party/efm32pg1b/%.su: ../qm/qpc/3rd_party/efm32pg1b/%.c qm/qpc/3rd_party/efm32pg1b/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-efm32pg1b

clean-qm-2f-qpc-2f-3rd_party-2f-efm32pg1b:
	-$(RM) ./qm/qpc/3rd_party/efm32pg1b/display_ls013b7dh03.d ./qm/qpc/3rd_party/efm32pg1b/display_ls013b7dh03.o ./qm/qpc/3rd_party/efm32pg1b/display_ls013b7dh03.su ./qm/qpc/3rd_party/efm32pg1b/displaypalemlib.d ./qm/qpc/3rd_party/efm32pg1b/displaypalemlib.o ./qm/qpc/3rd_party/efm32pg1b/displaypalemlib.su ./qm/qpc/3rd_party/efm32pg1b/em_assert.d ./qm/qpc/3rd_party/efm32pg1b/em_assert.o ./qm/qpc/3rd_party/efm32pg1b/em_assert.su ./qm/qpc/3rd_party/efm32pg1b/em_cmu.d ./qm/qpc/3rd_party/efm32pg1b/em_cmu.o ./qm/qpc/3rd_party/efm32pg1b/em_cmu.su ./qm/qpc/3rd_party/efm32pg1b/em_emu.d ./qm/qpc/3rd_party/efm32pg1b/em_emu.o ./qm/qpc/3rd_party/efm32pg1b/em_emu.su ./qm/qpc/3rd_party/efm32pg1b/em_gpio.d ./qm/qpc/3rd_party/efm32pg1b/em_gpio.o ./qm/qpc/3rd_party/efm32pg1b/em_gpio.su ./qm/qpc/3rd_party/efm32pg1b/em_int.d ./qm/qpc/3rd_party/efm32pg1b/em_int.o ./qm/qpc/3rd_party/efm32pg1b/em_int.su ./qm/qpc/3rd_party/efm32pg1b/em_prs.d ./qm/qpc/3rd_party/efm32pg1b/em_prs.o ./qm/qpc/3rd_party/efm32pg1b/em_prs.su ./qm/qpc/3rd_party/efm32pg1b/em_rtcc.d ./qm/qpc/3rd_party/efm32pg1b/em_rtcc.o ./qm/qpc/3rd_party/efm32pg1b/em_rtcc.su ./qm/qpc/3rd_party/efm32pg1b/em_system.d ./qm/qpc/3rd_party/efm32pg1b/em_system.o ./qm/qpc/3rd_party/efm32pg1b/em_system.su ./qm/qpc/3rd_party/efm32pg1b/em_usart.d ./qm/qpc/3rd_party/efm32pg1b/em_usart.o ./qm/qpc/3rd_party/efm32pg1b/em_usart.su ./qm/qpc/3rd_party/efm32pg1b/system_efm32pg1b.d ./qm/qpc/3rd_party/efm32pg1b/system_efm32pg1b.o ./qm/qpc/3rd_party/efm32pg1b/system_efm32pg1b.su ./qm/qpc/3rd_party/efm32pg1b/udelay.d ./qm/qpc/3rd_party/efm32pg1b/udelay.o ./qm/qpc/3rd_party/efm32pg1b/udelay.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-efm32pg1b


################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/emwin/demo_no_wm/Config/GUIConf.c \
../qm/qpc/examples/emwin/demo_no_wm/Config/LCDConf.c \
../qm/qpc/examples/emwin/demo_no_wm/Config/SIMConf.c 

OBJS += \
./qm/qpc/examples/emwin/demo_no_wm/Config/GUIConf.o \
./qm/qpc/examples/emwin/demo_no_wm/Config/LCDConf.o \
./qm/qpc/examples/emwin/demo_no_wm/Config/SIMConf.o 

C_DEPS += \
./qm/qpc/examples/emwin/demo_no_wm/Config/GUIConf.d \
./qm/qpc/examples/emwin/demo_no_wm/Config/LCDConf.d \
./qm/qpc/examples/emwin/demo_no_wm/Config/SIMConf.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/emwin/demo_no_wm/Config/%.o qm/qpc/examples/emwin/demo_no_wm/Config/%.su: ../qm/qpc/examples/emwin/demo_no_wm/Config/%.c qm/qpc/examples/emwin/demo_no_wm/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-emwin-2f-demo_no_wm-2f-Config

clean-qm-2f-qpc-2f-examples-2f-emwin-2f-demo_no_wm-2f-Config:
	-$(RM) ./qm/qpc/examples/emwin/demo_no_wm/Config/GUIConf.d ./qm/qpc/examples/emwin/demo_no_wm/Config/GUIConf.o ./qm/qpc/examples/emwin/demo_no_wm/Config/GUIConf.su ./qm/qpc/examples/emwin/demo_no_wm/Config/LCDConf.d ./qm/qpc/examples/emwin/demo_no_wm/Config/LCDConf.o ./qm/qpc/examples/emwin/demo_no_wm/Config/LCDConf.su ./qm/qpc/examples/emwin/demo_no_wm/Config/SIMConf.d ./qm/qpc/examples/emwin/demo_no_wm/Config/SIMConf.o ./qm/qpc/examples/emwin/demo_no_wm/Config/SIMConf.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-emwin-2f-demo_no_wm-2f-Config


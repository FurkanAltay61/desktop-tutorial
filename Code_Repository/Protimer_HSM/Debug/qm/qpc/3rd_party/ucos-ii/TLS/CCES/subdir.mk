################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/ucos-ii/TLS/CCES/os_tls.c 

OBJS += \
./qm/qpc/3rd_party/ucos-ii/TLS/CCES/os_tls.o 

C_DEPS += \
./qm/qpc/3rd_party/ucos-ii/TLS/CCES/os_tls.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/ucos-ii/TLS/CCES/%.o qm/qpc/3rd_party/ucos-ii/TLS/CCES/%.su: ../qm/qpc/3rd_party/ucos-ii/TLS/CCES/%.c qm/qpc/3rd_party/ucos-ii/TLS/CCES/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-ucos-2d-ii-2f-TLS-2f-CCES

clean-qm-2f-qpc-2f-3rd_party-2f-ucos-2d-ii-2f-TLS-2f-CCES:
	-$(RM) ./qm/qpc/3rd_party/ucos-ii/TLS/CCES/os_tls.d ./qm/qpc/3rd_party/ucos-ii/TLS/CCES/os_tls.o ./qm/qpc/3rd_party/ucos-ii/TLS/CCES/os_tls.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-ucos-2d-ii-2f-TLS-2f-CCES


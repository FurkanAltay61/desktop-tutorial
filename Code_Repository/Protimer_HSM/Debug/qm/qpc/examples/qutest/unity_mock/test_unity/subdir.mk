################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/examples/qutest/unity_mock/test_unity/MockLed.c \
../qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar.c \
../qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar_Runner.c 

OBJS += \
./qm/qpc/examples/qutest/unity_mock/test_unity/MockLed.o \
./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar.o \
./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar_Runner.o 

C_DEPS += \
./qm/qpc/examples/qutest/unity_mock/test_unity/MockLed.d \
./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar.d \
./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar_Runner.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/examples/qutest/unity_mock/test_unity/%.o qm/qpc/examples/qutest/unity_mock/test_unity/%.su: ../qm/qpc/examples/qutest/unity_mock/test_unity/%.c qm/qpc/examples/qutest/unity_mock/test_unity/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-examples-2f-qutest-2f-unity_mock-2f-test_unity

clean-qm-2f-qpc-2f-examples-2f-qutest-2f-unity_mock-2f-test_unity:
	-$(RM) ./qm/qpc/examples/qutest/unity_mock/test_unity/MockLed.d ./qm/qpc/examples/qutest/unity_mock/test_unity/MockLed.o ./qm/qpc/examples/qutest/unity_mock/test_unity/MockLed.su ./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar.d ./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar.o ./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar.su ./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar_Runner.d ./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar_Runner.o ./qm/qpc/examples/qutest/unity_mock/test_unity/TestLedBar_Runner.su

.PHONY: clean-qm-2f-qpc-2f-examples-2f-qutest-2f-unity_mock-2f-test_unity


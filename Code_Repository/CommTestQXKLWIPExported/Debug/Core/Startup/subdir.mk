################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f746zgtx.s 

OBJS += \
./Core/Startup/startup_stm32f746zgtx.o 

S_DEPS += \
./Core/Startup/startup_stm32f746zgtx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"C:/Users/furkan.altay/Desktop/stm32_mw_lwip-master/stm32_mw_lwip-master/src/include/lwip" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f746zgtx.d ./Core/Startup/startup_stm32f746zgtx.o

.PHONY: clean-Core-2f-Startup

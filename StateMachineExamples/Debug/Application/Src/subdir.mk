################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Src/Rectangle.c \
../Application/Src/Shape.c 

OBJS += \
./Application/Src/Rectangle.o \
./Application/Src/Shape.o 

C_DEPS += \
./Application/Src/Rectangle.d \
./Application/Src/Shape.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/%.o Application/Src/%.su: ../Application/Src/%.c Application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"C:/Users/furkan.altay/Documents/GitHub/desktop-tutorial/StateMachineExamples/Application/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Src

clean-Application-2f-Src:
	-$(RM) ./Application/Src/Rectangle.d ./Application/Src/Rectangle.o ./Application/Src/Rectangle.su ./Application/Src/Shape.d ./Application/Src/Shape.o ./Application/Src/Shape.su

.PHONY: clean-Application-2f-Src


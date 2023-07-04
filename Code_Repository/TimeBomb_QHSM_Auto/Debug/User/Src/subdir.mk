################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/Bsp.c \
../User/Src/Timebomb.c 

OBJS += \
./User/Src/Bsp.o \
./User/Src/Timebomb.o 

C_DEPS += \
./User/Src/Bsp.d \
./User/Src/Timebomb.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o User/Src/%.su User/Src/%.cyclo: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I"/home/furkan/Desktop/desktop-tutorial/Code_Repository/TimeBomb_QHSM_Auto/QPC_Port" -I"/home/furkan/Desktop/desktop-tutorial/Code_Repository/TimeBomb_QHSM_Auto/QPC/Inc" -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"/home/furkan/Desktop/desktop-tutorial/Code_Repository/TimeBomb_QHSM_Auto/User/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Src

clean-User-2f-Src:
	-$(RM) ./User/Src/Bsp.cyclo ./User/Src/Bsp.d ./User/Src/Bsp.o ./User/Src/Bsp.su ./User/Src/Timebomb.cyclo ./User/Src/Timebomb.d ./User/Src/Timebomb.o ./User/Src/Timebomb.su

.PHONY: clean-User-2f-Src


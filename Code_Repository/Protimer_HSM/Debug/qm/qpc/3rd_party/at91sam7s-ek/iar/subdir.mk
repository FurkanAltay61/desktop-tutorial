################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../qm/qpc/3rd_party/at91sam7s-ek/iar/startup_at91mc.s 

C_SRCS += \
../qm/qpc/3rd_party/at91sam7s-ek/iar/low_level_init.c 

OBJS += \
./qm/qpc/3rd_party/at91sam7s-ek/iar/low_level_init.o \
./qm/qpc/3rd_party/at91sam7s-ek/iar/startup_at91mc.o 

S_DEPS += \
./qm/qpc/3rd_party/at91sam7s-ek/iar/startup_at91mc.d 

C_DEPS += \
./qm/qpc/3rd_party/at91sam7s-ek/iar/low_level_init.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/at91sam7s-ek/iar/%.o qm/qpc/3rd_party/at91sam7s-ek/iar/%.su: ../qm/qpc/3rd_party/at91sam7s-ek/iar/%.c qm/qpc/3rd_party/at91sam7s-ek/iar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
qm/qpc/3rd_party/at91sam7s-ek/iar/%.o: ../qm/qpc/3rd_party/at91sam7s-ek/iar/%.s qm/qpc/3rd_party/at91sam7s-ek/iar/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-at91sam7s-2d-ek-2f-iar

clean-qm-2f-qpc-2f-3rd_party-2f-at91sam7s-2d-ek-2f-iar:
	-$(RM) ./qm/qpc/3rd_party/at91sam7s-ek/iar/low_level_init.d ./qm/qpc/3rd_party/at91sam7s-ek/iar/low_level_init.o ./qm/qpc/3rd_party/at91sam7s-ek/iar/low_level_init.su ./qm/qpc/3rd_party/at91sam7s-ek/iar/startup_at91mc.d ./qm/qpc/3rd_party/at91sam7s-ek/iar/startup_at91mc.o

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-at91sam7s-2d-ek-2f-iar


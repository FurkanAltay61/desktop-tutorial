################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../qm/qpc/3rd_party/mbed-lpc1768/iar/startup_LPC17xx.s 

OBJS += \
./qm/qpc/3rd_party/mbed-lpc1768/iar/startup_LPC17xx.o 

S_DEPS += \
./qm/qpc/3rd_party/mbed-lpc1768/iar/startup_LPC17xx.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/mbed-lpc1768/iar/%.o: ../qm/qpc/3rd_party/mbed-lpc1768/iar/%.s qm/qpc/3rd_party/mbed-lpc1768/iar/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-mbed-2d-lpc1768-2f-iar

clean-qm-2f-qpc-2f-3rd_party-2f-mbed-2d-lpc1768-2f-iar:
	-$(RM) ./qm/qpc/3rd_party/mbed-lpc1768/iar/startup_LPC17xx.d ./qm/qpc/3rd_party/mbed-lpc1768/iar/startup_LPC17xx.o

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-mbed-2d-lpc1768-2f-iar

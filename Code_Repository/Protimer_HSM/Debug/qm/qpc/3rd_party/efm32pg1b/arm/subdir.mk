################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../qm/qpc/3rd_party/efm32pg1b/arm/startup_efm32pg1b.s 

OBJS += \
./qm/qpc/3rd_party/efm32pg1b/arm/startup_efm32pg1b.o 

S_DEPS += \
./qm/qpc/3rd_party/efm32pg1b/arm/startup_efm32pg1b.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/efm32pg1b/arm/%.o: ../qm/qpc/3rd_party/efm32pg1b/arm/%.s qm/qpc/3rd_party/efm32pg1b/arm/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-efm32pg1b-2f-arm

clean-qm-2f-qpc-2f-3rd_party-2f-efm32pg1b-2f-arm:
	-$(RM) ./qm/qpc/3rd_party/efm32pg1b/arm/startup_efm32pg1b.d ./qm/qpc/3rd_party/efm32pg1b/arm/startup_efm32pg1b.o

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-efm32pg1b-2f-arm


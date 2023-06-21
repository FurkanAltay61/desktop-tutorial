################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../qm/qpc/3rd_party/ek-lm3s6965/arm/startup_LM3S6965.s 

OBJS += \
./qm/qpc/3rd_party/ek-lm3s6965/arm/startup_LM3S6965.o 

S_DEPS += \
./qm/qpc/3rd_party/ek-lm3s6965/arm/startup_LM3S6965.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/ek-lm3s6965/arm/%.o: ../qm/qpc/3rd_party/ek-lm3s6965/arm/%.s qm/qpc/3rd_party/ek-lm3s6965/arm/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-ek-2d-lm3s6965-2f-arm

clean-qm-2f-qpc-2f-3rd_party-2f-ek-2d-lm3s6965-2f-arm:
	-$(RM) ./qm/qpc/3rd_party/ek-lm3s6965/arm/startup_LM3S6965.d ./qm/qpc/3rd_party/ek-lm3s6965/arm/startup_LM3S6965.o

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-ek-2d-lm3s6965-2f-arm


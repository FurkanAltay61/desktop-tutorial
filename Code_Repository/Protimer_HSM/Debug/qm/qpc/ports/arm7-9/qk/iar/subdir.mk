################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../qm/qpc/ports/arm7-9/qk/iar/qk_port.s 

OBJS += \
./qm/qpc/ports/arm7-9/qk/iar/qk_port.o 

S_DEPS += \
./qm/qpc/ports/arm7-9/qk/iar/qk_port.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/ports/arm7-9/qk/iar/%.o: ../qm/qpc/ports/arm7-9/qk/iar/%.s qm/qpc/ports/arm7-9/qk/iar/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-ports-2f-arm7-2d-9-2f-qk-2f-iar

clean-qm-2f-qpc-2f-ports-2f-arm7-2d-9-2f-qk-2f-iar:
	-$(RM) ./qm/qpc/ports/arm7-9/qk/iar/qk_port.d ./qm/qpc/ports/arm7-9/qk/iar/qk_port.o

.PHONY: clean-qm-2f-qpc-2f-ports-2f-arm7-2d-9-2f-qk-2f-iar


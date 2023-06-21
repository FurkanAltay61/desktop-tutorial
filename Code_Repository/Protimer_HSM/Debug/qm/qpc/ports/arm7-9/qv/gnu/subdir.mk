################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../qm/qpc/ports/arm7-9/qv/gnu/qv_port.s 

OBJS += \
./qm/qpc/ports/arm7-9/qv/gnu/qv_port.o 

S_DEPS += \
./qm/qpc/ports/arm7-9/qv/gnu/qv_port.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/ports/arm7-9/qv/gnu/%.o: ../qm/qpc/ports/arm7-9/qv/gnu/%.s qm/qpc/ports/arm7-9/qv/gnu/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-qm-2f-qpc-2f-ports-2f-arm7-2d-9-2f-qv-2f-gnu

clean-qm-2f-qpc-2f-ports-2f-arm7-2d-9-2f-qv-2f-gnu:
	-$(RM) ./qm/qpc/ports/arm7-9/qv/gnu/qv_port.d ./qm/qpc/ports/arm7-9/qv/gnu/qv_port.o

.PHONY: clean-qm-2f-qpc-2f-ports-2f-arm7-2d-9-2f-qv-2f-gnu


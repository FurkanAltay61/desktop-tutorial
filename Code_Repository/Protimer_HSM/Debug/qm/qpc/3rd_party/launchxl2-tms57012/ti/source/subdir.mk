################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/esm.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/gio.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/het.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/notification.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/pinmux.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/rti.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sci.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_dma.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_main.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pcr.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_phantom.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pmm.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_selftest.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_startup.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_vim.c \
../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/system.c 

OBJS += \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/esm.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/gio.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/het.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/notification.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/pinmux.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/rti.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sci.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_dma.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_main.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pcr.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_phantom.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pmm.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_selftest.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_startup.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_vim.o \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/system.o 

C_DEPS += \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/esm.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/gio.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/het.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/notification.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/pinmux.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/rti.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sci.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_dma.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_main.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pcr.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_phantom.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pmm.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_selftest.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_startup.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_vim.d \
./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/system.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/launchxl2-tms57012/ti/source/%.o qm/qpc/3rd_party/launchxl2-tms57012/ti/source/%.su: ../qm/qpc/3rd_party/launchxl2-tms57012/ti/source/%.c qm/qpc/3rd_party/launchxl2-tms57012/ti/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-launchxl2-2d-tms57012-2f-ti-2f-source

clean-qm-2f-qpc-2f-3rd_party-2f-launchxl2-2d-tms57012-2f-ti-2f-source:
	-$(RM) ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/esm.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/esm.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/esm.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/gio.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/gio.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/gio.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/het.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/het.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/het.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/notification.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/notification.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/notification.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/pinmux.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/pinmux.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/pinmux.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/rti.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/rti.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/rti.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sci.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sci.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sci.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_dma.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_dma.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_dma.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_main.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_main.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_main.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pcr.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pcr.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pcr.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_phantom.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_phantom.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_phantom.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pmm.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pmm.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_pmm.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_selftest.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_selftest.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_selftest.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_startup.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_startup.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_startup.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_vim.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_vim.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/sys_vim.su ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/system.d ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/system.o ./qm/qpc/3rd_party/launchxl2-tms57012/ti/source/system.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-launchxl2-2d-tms57012-2f-ti-2f-source


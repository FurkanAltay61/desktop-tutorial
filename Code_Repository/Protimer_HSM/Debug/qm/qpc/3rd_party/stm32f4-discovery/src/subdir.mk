################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qm/qpc/3rd_party/stm32f4-discovery/src/misc.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_adc.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_can.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_crc.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_aes.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_des.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_tdes.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dac.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dbgmcu.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dcmi.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dma.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_exti.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_flash.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_fsmc.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_gpio.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_md5.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_sha1.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_i2c.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_iwdg.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_pwr.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rcc.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rng.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rtc.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_sdio.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_spi.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_syscfg.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_tim.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_usart.c \
../qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_wwdg.c 

OBJS += \
./qm/qpc/3rd_party/stm32f4-discovery/src/misc.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_adc.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_can.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_crc.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_aes.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_des.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_tdes.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dac.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dbgmcu.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dcmi.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dma.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_exti.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_flash.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_fsmc.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_gpio.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_md5.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_sha1.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_i2c.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_iwdg.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_pwr.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rcc.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rng.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rtc.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_sdio.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_spi.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_syscfg.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_tim.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_usart.o \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_wwdg.o 

C_DEPS += \
./qm/qpc/3rd_party/stm32f4-discovery/src/misc.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_adc.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_can.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_crc.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_aes.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_des.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_tdes.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dac.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dbgmcu.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dcmi.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dma.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_exti.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_flash.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_fsmc.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_gpio.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_md5.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_sha1.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_i2c.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_iwdg.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_pwr.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rcc.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rng.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rtc.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_sdio.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_spi.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_syscfg.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_tim.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_usart.d \
./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
qm/qpc/3rd_party/stm32f4-discovery/src/%.o qm/qpc/3rd_party/stm32f4-discovery/src/%.su: ../qm/qpc/3rd_party/stm32f4-discovery/src/%.c qm/qpc/3rd_party/stm32f4-discovery/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I"C:/Users/furkan.altay/STM32CubeIDE/workspace_1.7.1/Protimer_HSM/qm/qpc/include" -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-qm-2f-qpc-2f-3rd_party-2f-stm32f4-2d-discovery-2f-src

clean-qm-2f-qpc-2f-3rd_party-2f-stm32f4-2d-discovery-2f-src:
	-$(RM) ./qm/qpc/3rd_party/stm32f4-discovery/src/misc.d ./qm/qpc/3rd_party/stm32f4-discovery/src/misc.o ./qm/qpc/3rd_party/stm32f4-discovery/src/misc.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_adc.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_adc.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_adc.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_can.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_can.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_can.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_crc.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_crc.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_crc.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_aes.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_aes.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_aes.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_des.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_des.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_des.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_tdes.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_tdes.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_cryp_tdes.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dac.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dac.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dac.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dbgmcu.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dbgmcu.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dbgmcu.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dcmi.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dcmi.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dcmi.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dma.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dma.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_dma.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_exti.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_exti.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_exti.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_flash.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_flash.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_flash.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_fsmc.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_fsmc.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_fsmc.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_gpio.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_gpio.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_gpio.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_md5.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_md5.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_md5.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_sha1.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_sha1.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_hash_sha1.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_i2c.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_i2c.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_i2c.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_iwdg.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_iwdg.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_iwdg.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_pwr.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_pwr.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_pwr.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rcc.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rcc.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rcc.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rng.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rng.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rng.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rtc.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rtc.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_rtc.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_sdio.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_sdio.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_sdio.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_spi.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_spi.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_spi.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_syscfg.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_syscfg.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_syscfg.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_tim.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_tim.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_tim.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_usart.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_usart.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_usart.su ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_wwdg.d ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_wwdg.o ./qm/qpc/3rd_party/stm32f4-discovery/src/stm32f4xx_wwdg.su

.PHONY: clean-qm-2f-qpc-2f-3rd_party-2f-stm32f4-2d-discovery-2f-src


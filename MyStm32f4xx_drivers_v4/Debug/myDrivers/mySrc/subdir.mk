################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../myDrivers/mySrc/stm32f407xx_dma_driver.c \
../myDrivers/mySrc/stm32f407xx_gpio_driver.c \
../myDrivers/mySrc/stm32f407xx_i2c_driver.c \
../myDrivers/mySrc/stm32f407xx_rcc_driver.c \
../myDrivers/mySrc/stm32f407xx_spi_driver.c \
../myDrivers/mySrc/stm32f407xx_usart_driver.c 

OBJS += \
./myDrivers/mySrc/stm32f407xx_dma_driver.o \
./myDrivers/mySrc/stm32f407xx_gpio_driver.o \
./myDrivers/mySrc/stm32f407xx_i2c_driver.o \
./myDrivers/mySrc/stm32f407xx_rcc_driver.o \
./myDrivers/mySrc/stm32f407xx_spi_driver.o \
./myDrivers/mySrc/stm32f407xx_usart_driver.o 

C_DEPS += \
./myDrivers/mySrc/stm32f407xx_dma_driver.d \
./myDrivers/mySrc/stm32f407xx_gpio_driver.d \
./myDrivers/mySrc/stm32f407xx_i2c_driver.d \
./myDrivers/mySrc/stm32f407xx_rcc_driver.d \
./myDrivers/mySrc/stm32f407xx_spi_driver.d \
./myDrivers/mySrc/stm32f407xx_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
myDrivers/mySrc/%.o myDrivers/mySrc/%.su: ../myDrivers/mySrc/%.c myDrivers/mySrc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"E:/GitHubRepo/desktop-tutorial/MyStm32f4xx_drivers_v4/myDrivers/myInc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-myDrivers-2f-mySrc

clean-myDrivers-2f-mySrc:
	-$(RM) ./myDrivers/mySrc/stm32f407xx_dma_driver.d ./myDrivers/mySrc/stm32f407xx_dma_driver.o ./myDrivers/mySrc/stm32f407xx_dma_driver.su ./myDrivers/mySrc/stm32f407xx_gpio_driver.d ./myDrivers/mySrc/stm32f407xx_gpio_driver.o ./myDrivers/mySrc/stm32f407xx_gpio_driver.su ./myDrivers/mySrc/stm32f407xx_i2c_driver.d ./myDrivers/mySrc/stm32f407xx_i2c_driver.o ./myDrivers/mySrc/stm32f407xx_i2c_driver.su ./myDrivers/mySrc/stm32f407xx_rcc_driver.d ./myDrivers/mySrc/stm32f407xx_rcc_driver.o ./myDrivers/mySrc/stm32f407xx_rcc_driver.su ./myDrivers/mySrc/stm32f407xx_spi_driver.d ./myDrivers/mySrc/stm32f407xx_spi_driver.o ./myDrivers/mySrc/stm32f407xx_spi_driver.su ./myDrivers/mySrc/stm32f407xx_usart_driver.d ./myDrivers/mySrc/stm32f407xx_usart_driver.o ./myDrivers/mySrc/stm32f407xx_usart_driver.su

.PHONY: clean-myDrivers-2f-mySrc


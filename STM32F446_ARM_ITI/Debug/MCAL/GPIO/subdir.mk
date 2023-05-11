################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/stm32f446_gpio.c 

OBJS += \
./MCAL/GPIO/stm32f446_gpio.o 

C_DEPS += \
./MCAL/GPIO/stm32f446_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/%.o MCAL/GPIO/%.su MCAL/GPIO/%.cyclo: ../MCAL/GPIO/%.c MCAL/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"D:/github_ITI_ARM/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL" -I"D:/github_ITI_ARM/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL/GPIO" -I"D:/github_ITI_ARM/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL/RCC" -I"D:/github_ITI_ARM/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/HAL" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-GPIO

clean-MCAL-2f-GPIO:
	-$(RM) ./MCAL/GPIO/stm32f446_gpio.cyclo ./MCAL/GPIO/stm32f446_gpio.d ./MCAL/GPIO/stm32f446_gpio.o ./MCAL/GPIO/stm32f446_gpio.su

.PHONY: clean-MCAL-2f-GPIO


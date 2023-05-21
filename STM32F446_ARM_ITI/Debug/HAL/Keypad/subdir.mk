################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad/keypad.c 

OBJS += \
./HAL/Keypad/keypad.o 

C_DEPS += \
./HAL/Keypad/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad/%.o HAL/Keypad/%.su HAL/Keypad/%.cyclo: ../HAL/Keypad/%.c HAL/Keypad/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL" -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/HAL/Keypad" -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/HAL/LCD" -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/HAL/LEDs" -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/HAL/SSD" -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL/GPIO" -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL/RCC" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-Keypad

clean-HAL-2f-Keypad:
	-$(RM) ./HAL/Keypad/keypad.cyclo ./HAL/Keypad/keypad.d ./HAL/Keypad/keypad.o ./HAL/Keypad/keypad.su

.PHONY: clean-HAL-2f-Keypad


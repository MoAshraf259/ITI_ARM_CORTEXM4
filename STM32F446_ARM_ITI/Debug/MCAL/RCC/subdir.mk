################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/RCC/stm32f446_rcc.c 

OBJS += \
./MCAL/RCC/stm32f446_rcc.o 

C_DEPS += \
./MCAL/RCC/stm32f446_rcc.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/RCC/%.o MCAL/RCC/%.su MCAL/RCC/%.cyclo: ../MCAL/RCC/%.c MCAL/RCC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL" -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL/GPIO" -I"D:/Embedded_ITI/ARM_GitHub/ITI_ARM_CORTEXM4/STM32F446_ARM_ITI/MCAL/RCC" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-RCC

clean-MCAL-2f-RCC:
	-$(RM) ./MCAL/RCC/stm32f446_rcc.cyclo ./MCAL/RCC/stm32f446_rcc.d ./MCAL/RCC/stm32f446_rcc.o ./MCAL/RCC/stm32f446_rcc.su

.PHONY: clean-MCAL-2f-RCC


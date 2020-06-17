################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f746xx.s 

OBJS += \
./startup/startup_stm32f746xx.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/HAL_Driver/Inc/Legacy" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/Utilities/STM32F7xx_Nucleo_144" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/inc" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/CMSIS/device" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/CMSIS/core" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



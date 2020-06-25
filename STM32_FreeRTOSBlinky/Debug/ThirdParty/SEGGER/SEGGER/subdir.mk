################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c \
../ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

OBJS += \
./ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o \
./ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

C_DEPS += \
./ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d \
./ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/SEGGER/SEGGER/%.o: ../ThirdParty/SEGGER/SEGGER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DSTM32 -DSTM32F7 -DSTM32F746ZGTx -DNUCLEO_F746ZG -DDEBUG -DSTM32F746xx -DUSE_HAL_DRIVER -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/HAL_Driver/Inc/Legacy" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/ThirdParty/SEGGER/Config" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/ThirdParty/SEGGER/OS" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/ThirdParty/SEGGER/SEGGER" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/Config" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/ThirdParty/FreeRTOS/org/Source/portable/GCC/ARM_CM7/r0p1" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/ThirdParty/FreeRTOS/org/Source/include" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/Utilities/STM32F7xx_Nucleo_144" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/inc" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/CMSIS/device" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/CMSIS/core" -I"C:/Users/VRAVI/Documents/Sigma/STMF7_FreeRTOS/Workspace/STM32_FreeRTOSBlinky/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



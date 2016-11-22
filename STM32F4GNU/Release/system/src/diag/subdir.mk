################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/diag/Trace.c \
../system/src/diag/trace_impl.c 

C_DEPS += \
./system/src/diag/Trace.d \
./system/src/diag/trace_impl.d 

OBJS += \
./system/src/diag/Trace.o \
./system/src/diag/trace_impl.o 


# Each subdirectory must supply rules for building sources it contributes
system/src/diag/%.o: ../system/src/diag/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DSTM32F411xE -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -DSTM32F411RETx -DUSED_SYSTICK -DUSE_SYSTICK -DTRACE -I"../include" -I"../system/include" -I"../system/include/CMSIS" -I../system/include/StdPeriph_Driver/inc -I../system/src/CMSIS -I../Lib -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



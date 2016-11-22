################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp 

C_SRCS += \
../src/_write.c \
../src/startup.c 

C_DEPS += \
./src/_write.d \
./src/startup.d 

OBJS += \
./src/_write.o \
./src/main.o \
./src/startup.o 

CPP_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DSTM32F411xE -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -DSTM32F411RETx -DUSED_SYSTICK -DUSE_SYSTICK -DTRACE -I"../include" -I"../system/include" -I"../system/include/CMSIS" -I../system/include/StdPeriph_Driver/inc -I../system/src/CMSIS -I../Lib -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DSTM32F411xE -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -DSTM32F411RETx -DUSED_SYSTICK -DUSE_SYSTICK -DTRACE -I"../include" -I"../system/include" -I"../system/include/CMSIS" -I../system/include/StdPeriph_Driver/inc -I../system/src/CMSIS -I../Lib -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



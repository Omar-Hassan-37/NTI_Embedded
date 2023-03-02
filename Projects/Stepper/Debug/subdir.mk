################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STEPPER_config.c \
../STEPPER_prog.c \
../dio.c \
../main_stepper.c 

OBJS += \
./STEPPER_config.o \
./STEPPER_prog.o \
./dio.o \
./main_stepper.o 

C_DEPS += \
./STEPPER_config.d \
./STEPPER_prog.d \
./dio.d \
./main_stepper.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



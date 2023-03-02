################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../EXTI0_prog.c \
../dio.c \
../lcd.c \
../lcd_cfg.c \
../led.c \
../main_ADC.c 

OBJS += \
./ADC_program.o \
./EXTI0_prog.o \
./dio.o \
./lcd.o \
./lcd_cfg.o \
./led.o \
./main_ADC.o 

C_DEPS += \
./ADC_program.d \
./EXTI0_prog.d \
./dio.d \
./lcd.d \
./lcd_cfg.d \
./led.d \
./main_ADC.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



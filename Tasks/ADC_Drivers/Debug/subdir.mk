################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_prog.c \
../DIO_prog.c \
../EXTI_config.c \
../EXTI_prog.c \
../GIE_prog.c \
../main.c 

OBJS += \
./ADC_prog.o \
./DIO_prog.o \
./EXTI_config.o \
./EXTI_prog.o \
./GIE_prog.o \
./main.o 

C_DEPS += \
./ADC_prog.d \
./DIO_prog.d \
./EXTI_config.d \
./EXTI_prog.d \
./GIE_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



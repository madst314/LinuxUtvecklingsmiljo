################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../20150825_Ovn12Test/linumtest.c 

OBJS += \
./20150825_Ovn12Test/linumtest.o 

C_DEPS += \
./20150825_Ovn12Test/linumtest.d 


# Each subdirectory must supply rules for building sources it contributes
20150825_Ovn12Test/%.o: ../20150825_Ovn12Test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc `pkg-config --cflags gtk+-2.0` -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: lab12_Eclipse

# Tool invocations
lab12_Eclipse: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	gcc -L/usr/lib -L/usr/local/lib -L/usr/lib -o "lab12_Eclipse" $(OBJS) $(USER_OBJS) $(LIBS)  `pkg-config --libs gtk+-2.0`
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) lab12_Eclipse
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

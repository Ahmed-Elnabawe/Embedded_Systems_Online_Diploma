################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
lesson_4_interrupts.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lesson_4_interrupts.list \

OBJCOPY_BIN += \
lesson_4_interrupts.bin \


# All Target
all: lesson_4_interrupts.elf secondary-outputs

# Tool invocations
lesson_4_interrupts.elf: $(OBJS) $(USER_OBJS) G:\Embedded\ Systems\ Diploma\git\Embedded_Systems_Online_Diploma\MCU_Fundamentals\lesson_4_Interrupts\lesson_4_interrupts\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "lesson_4_interrupts.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"G:\Embedded Systems Diploma\git\Embedded_Systems_Online_Diploma\MCU_Fundamentals\lesson_4_Interrupts\lesson_4_interrupts\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lesson_4_interrupts.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lesson_4_interrupts.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lesson_4_interrupts.list"
	@echo 'Finished building: $@'
	@echo ' '

lesson_4_interrupts.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lesson_4_interrupts.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

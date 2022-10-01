################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := CAR1_HUIJIEZHAOXIN
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CAR1_HUIJIEZHAOXIN.elf \

MAP_FILES += \
CAR1_HUIJIEZHAOXIN.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CAR1_HUIJIEZHAOXIN.list \

OBJCOPY_HEX += \
CAR1_HUIJIEZHAOXIN.hex \

OBJCOPY_BIN += \
CAR1_HUIJIEZHAOXIN.bin \


# All Target
all: main-build

# Main-build Target
main-build: CAR1_HUIJIEZHAOXIN.elf secondary-outputs

# Tool invocations
CAR1_HUIJIEZHAOXIN.elf CAR1_HUIJIEZHAOXIN.map: $(OBJS) $(USER_OBJS) C:\Users\bamia\STM32CubeIDE\workspace_1.10.1\CAR1_HUIJIEZHAOXIN\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "CAR1_HUIJIEZHAOXIN.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\bamia\STM32CubeIDE\workspace_1.10.1\CAR1_HUIJIEZHAOXIN\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CAR1_HUIJIEZHAOXIN.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CAR1_HUIJIEZHAOXIN.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CAR1_HUIJIEZHAOXIN.list"
	@echo 'Finished building: $@'
	@echo ' '

CAR1_HUIJIEZHAOXIN.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "CAR1_HUIJIEZHAOXIN.hex"
	@echo 'Finished building: $@'
	@echo ' '

CAR1_HUIJIEZHAOXIN.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CAR1_HUIJIEZHAOXIN.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CAR1_HUIJIEZHAOXIN.bin CAR1_HUIJIEZHAOXIN.elf CAR1_HUIJIEZHAOXIN.hex CAR1_HUIJIEZHAOXIN.list CAR1_HUIJIEZHAOXIN.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets

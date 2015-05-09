################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include scr/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: hello_ext.so

dependents:
	-cd /home/pedro/BoostPython/utiles/Release && $(MAKE) all

# Tool invocations
hello_ext.so: $(OBJS) $(USER_OBJS) /home/pedro/BoostPython/utiles/Release/libutiles.a
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/home/pedro/BoostPython/utiles/Release" -fPIC -shared -Wl,-soname=hello_ext.so -o "hello_ext.so" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(LIBRARIES)$(CPP_DEPS)$(CXX_DEPS)$(C_UPPER_DEPS) hello_ext.so
	-@echo ' '

post-build:
	-@echo 'Se copia a la carpeta comun de librerias dinamicas c++'
	-cp hello_ext.so /home/pedro/Documents/librerias_cpp_python/hello_ext.so
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
/home/pedro/BoostPython/utiles/Release/libutiles.a:

-include ../makefile.targets

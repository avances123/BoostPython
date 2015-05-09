################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../scr/rc_datetime.cpp 

OBJS += \
./scr/rc_datetime.o 

CPP_DEPS += \
./scr/rc_datetime.d 


# Each subdirectory must supply rules for building sources it contributes
scr/%.o: ../scr/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/pedro/BoostPython/utiles" -I/usr/include/python2.7 -O3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



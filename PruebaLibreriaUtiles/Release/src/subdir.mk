################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PruebaLibreriaUtiles.cpp 

OBJS += \
./src/PruebaLibreriaUtiles.o 

CPP_DEPS += \
./src/PruebaLibreriaUtiles.d 


# Each subdirectory must supply rules for building sources it contributes
src/PruebaLibreriaUtiles.o: ../src/PruebaLibreriaUtiles.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/pedro/workspaceBoostPython/utiles" -O3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/PruebaLibreriaUtiles.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



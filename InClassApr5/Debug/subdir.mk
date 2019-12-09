################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BSTY.cpp \
../NodeT.cpp \
../TreePuzzle.cpp \
../mainYahtzee.cpp 

OBJS += \
./BSTY.o \
./NodeT.o \
./TreePuzzle.o \
./mainYahtzee.o 

CPP_DEPS += \
./BSTY.d \
./NodeT.d \
./TreePuzzle.d \
./mainYahtzee.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



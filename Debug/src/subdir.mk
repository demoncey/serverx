################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Message.cpp \
../src/MessageQueue.cpp \
../src/test_process.cpp 

OBJS += \
./src/Message.o \
./src/MessageQueue.o \
./src/test_process.o 

CPP_DEPS += \
./src/Message.d \
./src/MessageQueue.d \
./src/test_process.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



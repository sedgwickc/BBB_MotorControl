GPP=g++
CFLAGS= 
DEBUG=-Wall -g -DDEBUG
LINKER= -lmraa

all: MC_Test

MC_Test:
	$(GPP) $(CFLAGS) MotorControl_test.cpp MotorControl.cpp -o MotorControl_test $(LINKER)

debug:
	$(GPP) $(CFLAGS) $(DEBUG) MotorControl_test.cpp MotorControl.cpp -o MotorControl_test $(LINKER)

clean:
	rm *.o MotorControl_test *.log

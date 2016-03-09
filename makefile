GPP=g++
CFLAGS= 
DEBUG=-Wall -g -DDEBUG
LINKER= -lmraa

all: sub_drive

sub_drive:
	$(GPP) $(CFLAGS) MotorControl_test.cpp MotorControl.cpp -o MotorControl_test $(LINKER)

debug:
	$(GPP) $(CFLAGS) $(DEBUG) MotorControl_test.cpp MotorControl.cpp -o MotorControl_test $(LINKER)

clean:
	rm *.o MotorControl_test *.log

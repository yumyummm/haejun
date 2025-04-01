TARGET = helloRaspberry switch_led interrupt
all : $(TARGET)
CFLAG = -lwiringPi

% : %.c
	cc -o $@ $< $(CFLAG)

clean: 
	rm $(TARGET)
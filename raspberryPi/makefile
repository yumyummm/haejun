TARGET = helloRaspberry switch_led interrupt led_pwm soft_tone_buzzer hard_tone_buzzer i2c_rgb_led i2c_rgb_led_switch i2c_servo
all : $(TARGET)
CFLAG = -lwiringPi

% : %.c
	cc -o $@ $< $(CFLAG)

clean: 
	rm $(TARGET)
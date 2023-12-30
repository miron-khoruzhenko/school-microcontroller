#include <16F887.h>

#fuses HS, NOWDT, NOPROTECT, NOLVP
#use delay(clock = 4000000)

// Define LED pins
#define LED1 PIN_B7
#define LED2 PIN_B5
#define LED3 PIN_B3
#define LED4 PIN_B1
#define LED5 PIN_B0

// Define Bluetooth module pins
#define BT_RX PIN_C7
#define BT_TX PIN_C6

// Define Servo motor pin
#define SERVO_PIN PIN_C2

// UART configuration
#use rs232(baud = 9600, xmit = BT_TX, rcv = BT_RX, stream = BT_SERIAL)

// Variables to store the previous state of LEDs
void control_leds(char receivedData);
void control_servo(char receivedData);

void main()
{
	// Initialize port directions
	set_tris_c(0b11000000); // Configure RC6 and RC7 as inputs for Bluetooth module
	set_tris_c(0b11111101); // Configure RC2 as output for Servo motor

	// Initialize LEDs
	output_low(LED1);
	output_low(LED2);
	output_low(LED3);
	output_low(LED4);
	output_low(LED5);

	// Main loop
	while (true)
	{
		// Check if data is available on the Bluetooth module
		if (kbhit(BT_SERIAL))
		{
			char receivedData = getc(BT_SERIAL);

			// Control LEDs and Servo based on received data
			control_leds(receivedData);
			control_servo(receivedData);
		}
	}
}

void control_leds(char receivedData)
{
	if (receivedData == '1')
	{
		output_high(LED1);
	}
	else if (receivedData == 'a')
	{
		output_low(LED1);
	}
	else if (receivedData == '2')
	{
		output_high(LED2);
	}
	else if (receivedData == 's')
	{
		output_low(LED2);
	}
	else if (receivedData == '3')
	{
		output_high(LED3);
	}
	else if (receivedData == 'd')
	{
		output_low(LED3);
	}
	else if (receivedData == '4')
	{
		output_high(LED4);
	}
	else if (receivedData == 'f')
	{
		output_low(LED4);
	}
	else if (receivedData == '5')
	{
		output_high(LED5);
	}
	else if (receivedData == 'g')
	{
		output_low(LED5);
	}
}

void control_servo(char receivedData)
{
	// Assuming that '9' is the command to rotate the servo to 90 degrees
	if (receivedData == '9')
	{
		// Set PWM duty cycle for 90 degrees rotation
		set_pwm1_duty(255);
		delay_ms(1000);
	}
	// You may add more conditions for other servo positions based on your requirements
	else
	{
		// Set PWM duty cycle for the default position or any other desired position
		set_pwm1_duty(127);
	}
}

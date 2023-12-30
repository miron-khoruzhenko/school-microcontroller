#include <16F887.h>
#use delay(clock=20000000) // Assuming a 20 MHz crystal

#fuses XT, NOWDT, NOPUT, NOLVP, NOCPD, NOPROTECT, NODEBUG, NOBROWNOUT, NOWRT

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, bits=8, parity=N)

#define LED_PIN PIN_D0

void main() {
    char receivedData;

    setup_adc_ports(NO_ANALOGS);
    setup_adc(ADC_OFF);

    printf("Bluetooth is Ready\r\n");

    while (TRUE) {
        if (kbhit()) {
            receivedData = getc();

            if (receivedData == '0') {
                output_low(LED_PIN); // Turn off LED connected to RD0
                printf("LED turned OFF\r\n");
            } else if (receivedData == '1') {
                output_high(LED_PIN); // Turn on LED connected to RD0
                printf("LED turned ON\r\n");
            }
        }
    }
}

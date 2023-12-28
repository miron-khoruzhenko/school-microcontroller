#include <16F887.h>
#FUSES HS
#use delay(clock= 4000000 )
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
char c;
#INT_RDA
void ngatUART()
{
	c = getc();
}
void main()
{
	enable_interrupts(int_rda);
	enable_interrupts(global);
	while(true)
	{
		if(c == 'a') output_high(pin_d0);
		if(c == 'b') output_low(pin_d0);
		
		if(c == 'c') output_high(pin_d1);
		if(c == 'd') output_low(pin_d1);
		
		if(c == 'e') output_high(pin_d2);
		if(c == 'f') output_low(pin_d2);
		
		if(c == 'g') output_high(pin_d3);
		if(c == 'h') output_low(pin_d3);
		
		
		
	}
	
}

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "pinDefines.h"

#define LIGHT_THRESHOLD 50 
#define BUTTON_PIN PIND
#define BUTTON PD2
#define LED_PORT PORTD
#define LED_DDR DDRD
#define LED1 PD3
#define BUZZER PD4

ISR(INT0_vect)
{
    
    if (bit_is_clear(BUTTON_PIN, BUTTON))
    {
        
        LED_PORT |= (1 << BUZZER);
        _delay_ms(5000);
        LED_PORT &= ~(1 << BUZZER);
    }
}

void initInterrupt0(void)
{
    EIMSK |= (1 << INT0); 
    EICRA |= (1 << ISC00); 
    sei(); 
}

uint16_t readLightSensor(void)
{
    
    ADCSRA |= (1 << ADSC);
    
    while (ADCSRA & (1 << ADSC))
        ;
    return ADC;
}

void initADC(void)
{
    
    ADMUX |= (1 << REFS0);
    
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
    
    ADCSRA |= (1 << ADEN);
}

int main(void)
{
    
    LED_DDR |= (1 << LED1) | (1 << BUZZER); 
    LED_PORT &= ~((1 << LED1) | (1 << BUZZER)); 
    DDRD &= ~(1 << BUTTON); 
    PORTD |= (1 << BUTTON); 

    initInterrupt0();
    initADC();

    
    while (1)
    {
        uint16_t lightValue = readLightSensor();
        if (lightValue > LIGHT_THRESHOLD)
        {
            LED_PORT |= (1 << LED1); 
        }
        else
        {
            LED_PORT &= ~(1 << LED1); 
        }
        _delay_ms(200);
    } 

    return 0; 
}

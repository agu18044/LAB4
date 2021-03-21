/*
  Blink
  The basic Energia example.
  Turns on an LED on for one second, then off for one second, repeatedly.
  Change the LED define to blink other LEDs.
  
  Hardware Required:
  * LaunchPad with an LED
  
  This example code is in the public domain.
*/
#include <stdint.h>

// most launchpads have a red LED
#define LEDR PF_1
#define LEDG PF_3
#define LEDB PF_2
uint8_t cont1;

//see pins_energia.h for more LED definitions
//#define LED GREEN_LED

void semaforo (void);  

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);     
  cont1 = 0;
  }

// the loop routine runs over and over again forever:
void loop() {
  semaforo();

}
/// secuencia de semaforo

void semaforo (void){
  digitalWrite(LEDB, LOW);  
  digitalWrite(LEDR, HIGH);    
  digitalWrite(LEDG, LOW);
  delay(1000); 
  digitalWrite(LEDR, HIGH);    
  digitalWrite(LEDG, HIGH);
  delay(1000); 
  digitalWrite(LEDR, LOW);    
  digitalWrite(LEDG, HIGH);
  delay(1000);
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, HIGH);
  delay(1000);
  }

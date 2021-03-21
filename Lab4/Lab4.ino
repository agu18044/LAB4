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
int cont1 = 0;
int cont2 = 0;
int led1[] = {23,24,25,26,27,28,29,10};
int led2[] = {19,18,15,14,13,12,11,32};
int band = 1;
const int player1 = PUSH1;
const int player2 = PUSH2;
const int start = PB_5;
int state0 = 0;
int state1 = 0;
int state2 = 0;


//see pins_energia.h for more LED definitions
//#define LED GREEN_LED

void semaforo (void);  
void juego (void);


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT); 
  pinMode (start, INPUT_PULLUP); 
  pinMode (player1, INPUT_PULLUP);
  pinMode (player2, INPUT_PULLUP);      
  for (int i=0; i<8; i++){
    pinMode(led1[i], OUTPUT);
    }
  for (int i=0; i<8; i++){
    pinMode(led2[i], OUTPUT);
    }
  }

void loop() {
  state0 = digitalRead(start);
  state1 = digitalRead(player1);
  state2 = digitalRead(player2);
  if (state0 == LOW){
    semaforo();
    band = 0;
    }
  if (band == 0){
    juego();
    }
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

void juego (void){
  if (state1 == LOW){
    if (cont1 >= 8){
      cont1 = 0;
      }
    cont1 ++;
    digitalWrite(led1[cont1], HIGH);
    delay(250);
    digitalWrite(led1[cont1], LOW);
    }
  if (state2 == LOW){
    if (cont2 >= 8){
      cont2 = 0;
      }
    cont2 ++;
    digitalWrite(led2[cont2], HIGH);
    delay(250);
    digitalWrite(led2[cont2], LOW);
    }
  }

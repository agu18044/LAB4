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

int led1[] = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};
int led2[] = {PD_0, PD_1, PD_2, PD_3, PD_6, PD_7, PE_1, PE_2};

int band = 1;
const int player1 = PUSH1;
const int player2 = PUSH2;
const int start = PA_2;
int state0 = 0;
int state1 = 0;
int state2 = 0;


// declaración de funciones
void semaforo (void);  
void juego (void);



void setup() {  
  cont1 = 0;
  cont2 = 0;
  // Semaforo              
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT); 
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDG, LOW);
  // botones para iniciar y jugar
  pinMode (start, INPUT_PULLUP); 
  pinMode (player1, INPUT_PULLUP);
  pinMode (player2, INPUT_PULLUP); 
  // contador de leds     
  for (int i=0; i<8; i++){
    pinMode(led1[i], OUTPUT);
    digitalWrite(led1[i], LOW);
    }
  for (int i=0; i<8; i++){
    pinMode(led2[i], OUTPUT);
    digitalWrite(led2[i], LOW);
    }
  digitalWrite(led1[0], HIGH);
  digitalWrite(led2[0], HIGH);
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
/////////////////////////////////////////////////////////////
//                   secuencia de semaforo                 //
/////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////
//                   secuencia de juego                    //
/////////////////////////////////////////////////////////////
void juego (void){
  if (state1 == LOW){
    digitalWrite(led1[0], LOW);
    cont1 ++;
    digitalWrite(led1[cont1], HIGH);
    delay(500);
    digitalWrite(led1[cont1], LOW);
    }
  if (state2 == LOW){
    digitalWrite(led2[0], LOW);
    cont2 ++;
    digitalWrite(led2[cont2], HIGH);
    delay(500);
    digitalWrite(led2[cont2], LOW);
    }
  if (cont1 >= 8){
    cont1 = 0;
    band = 1;
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDR, HIGH); 
    delay(500);
    setup();
    }
  if (cont2 >= 8){
    cont2 = 0;
    band = 1;
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDG, HIGH); 
    delay(500);
    setup();
    } 
 }

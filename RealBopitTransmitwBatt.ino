#include <stdio.h>
#include <stdlib.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 FCWAZZZZZZZZZZZZZZZZZZZZZZZ CZ Cradio(9, 10); // CE, CSN
const byte address[6] = "42069";
const int button = 6;     
  // GPIO 8 for the button
int buttonStatus=0;   // LED status flag
//batt info
const int battLoad =  3;
int battState = LOW;
unsigned long previousMillis = 0;
const long interval = 6000;


void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT);         // define button as an input 
            // define LED as an output
          // turn output off just in case
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(battLoad, OUTPUT);
}

void loop() {
  int SentMessage[1] = {333};
  if (digitalRead(button)==HIGH){ // if button is pressed
   
    if (buttonStatus==0) {             
      buttonStatus=1;                  
    Serial.println("Button activated");
    SentMessage[0] = 111;
    radio.write(SentMessage, 1);
    SentMessage[0] = 333;
      }   
                             
    else {                        
      buttonStatus=0;    
      Serial.println("Button Deactivated");
      SentMessage[0] = 333;
      radio.write(SentMessage, 1);
            
    }
  delay(1000);                    // wait a sec for the 
  }                               // hardware to stabilize
                            // begin again 

unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (battState == LOW) {
      battState = HIGH;
    } else {
      battState = LOW;
    }

    // set the LED with the battState of the variable:
    digitalWrite(battLoad, battState);
  }
  }

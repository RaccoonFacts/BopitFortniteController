#include <Keyboard.h>
#include <Mouse.h>
//#include <AbsMouse.h>
#include <stdio.h>
#include <stdlib.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); //CE CSN
const byte address[6] = "42069";
int ReceivedMessage[1] = {000};
const int ledPin = 12; 
signed char xturn = 40;
signed char nullmove = 0;
signed char ylookup = 90;
bool crankLoop = true;
void setup() {
Serial.begin(9600);
Serial.println("Power On");
Keyboard.begin();
Mouse.begin();
Serial.println("Power On");
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
pinMode(ledPin, OUTPUT);

//AbsMouse.init(1920, 1080);  //ABSOLUTE MOUSE INITIALIZING
}

void loop() {


while (radio.available())
  
  { 
    radio.read(ReceivedMessage, 1);
  

  if  (ReceivedMessage[0] == 111) {
      Serial.println("Button Activated");
      crankLoop = true;
      crank90s();
           
    }

   else  { 
       Serial.println("Button Deactivated");
       crankLoop = false;
       quit();
     
    }
   
    }

}


//Cranking
void crank90s()
{
  
 Serial.println("Crank It");
 digitalWrite(ledPin, HIGH);
 Keyboard.press('F');
 Keyboard.release('F');
 delay(100);
 Keyboard.press('C');
 Keyboard.press('W');
 Keyboard.press('A');
 delay(100);
 Keyboard.release('A');
 Keyboard.release('C');
 Mouse.press(); 
 delay(100);
 Mouse.release(); 
 delay(300);
 Keyboard.press('Z');
 Mouse.press();
 delay(100);
 Mouse.move(0,-100);
 delay(1000);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(127,0);
 delay(100);
 Keyboard.release('Z');
 Keyboard.press(' ');
 Keyboard.release(' ');
 Keyboard.press('C');
 Keyboard.release('C');
 delay(100);
 Mouse.press();
 delay(10);
 Mouse.move(0,-100);
 delay(100);
 Keyboard.press('Z');
 Keyboard.release('Z');
 delay(700);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(20,0);
 Mouse.move(0,60);
 delay(50);
 Mouse.release();
 Keyboard.press(' ');
 Keyboard.release(' ');
 Keyboard.press('C');
 Keyboard.release('C');
 delay(100);
 Mouse.press();
 
 delay(100);
 Keyboard.press('Z');
 Keyboard.release('Z');
 delay(700);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(20,0);
 Mouse.move(0,60);
 delay(50);
 Mouse.release();
 Keyboard.press(' ');
 Keyboard.release(' ');
 Keyboard.press('C');
 Keyboard.release('C');
 delay(100);
 Mouse.press();
//Work on loop


 



 
 while (!radio.available())
  
  { 
    cranklevel();
  }
  quit();
}
void cranklevel()
{
  
delay(100);
 Keyboard.press('Z');
 Keyboard.release('Z');
 delay(800);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(0,20);
 delay(50);
 Mouse.release();
 Keyboard.press(' ');
 Keyboard.release(' ');
 Keyboard.press('C');
 Keyboard.release('C');
 delay(200);
 Mouse.press();

 delay(100);
 Keyboard.press('Z');
 Keyboard.release('Z');
 delay(800);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(0,20);
 delay(50);
 Mouse.release();
 Keyboard.press(' ');
 Keyboard.release(' ');
 Keyboard.press('C');
 Keyboard.release('C');
 delay(200);
 Mouse.press();

  delay(100);
 Keyboard.press('Z');
 Keyboard.release('Z');
 delay(800);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(127,0);
 Mouse.move(20,0);
 Mouse.move(0,-25);
 delay(50);
 Mouse.release();
 Keyboard.press(' ');
 Keyboard.release(' ');
 Keyboard.press('C');
 Keyboard.release('C');
 delay(200);
 Mouse.press();
 
}



  
 
void quit()
{
 
  Mouse.release();
  Keyboard.releaseAll();
  Serial.println("quit function");
  digitalWrite(ledPin, LOW);
  
  
}

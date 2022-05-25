/*
   Made By R14GENIE

   Free to use

   Using a HC-06 Bluethooth module

   V.1.0:
   + Make connexion with any device and turn on a led with a port

*/

/*
  Include
*/
#include <SoftwareSerial.h>   // librairie pour creer une nouvelle connexion serie max 9600 baud

/*
  Define
*/
#define PIN_LED 7

/*
  Assign pin for the bluetooth module
*/
SoftwareSerial BTSerial(10, 11); // RX | TX  = > BT-TX=10 BT-RX=11


void setup()
{
  // Init Serial
  Serial.begin(9600);
  Serial.println("Setup begin");

  // Init the BTSerial at 9600 baud
  BTSerial.begin(9600);

  //Init the PIN for the led as OUTPUT
  pinMode(PIN_LED, OUTPUT);
}

void loop()
{

  /*
   * Variable
  */
  String message;
    
  while (Serial.available()) {
    
    message = Serial.readString();
    BTSerial.println(message);
    
  }

  if (message == "on\r") {
    
    digitalWrite(PIN_LED, HIGH); 
    
  }
  else if (message == "off\r") {
    
    digitalWrite(PIN_LED, LOW); 
    
  }
}

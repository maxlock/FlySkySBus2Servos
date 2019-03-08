
/*
 * Allows 2 servos to be controlled by an Flysky/Turnigy IBus receiver
 * Requires https://gitlab.com/timwilkinson/FlySkyIBus
 * Connect SBus receiver port to Serial RX, 5v & Gnd
 * Connect Servos to pins 9 or 10, 5v & Gnd
 */

#include <FlySkyIBus.h>
#include <Servo.h> 

int curvalue[2]; // Declare array to store received positions

Servo myservo1;  // Initialise servo1
Servo myservo2;  // Initialise servo2

void setup() 
{
  Serial.begin(115200); // Initialise the serial port
  IBus.begin(Serial);   // Initialise the IBus library
    
  curvalue[0] = 1000;   // Set servos position defaults
  curvalue[1] = 1000;
  
  myservo1.attach(9);   // Attach servos to pins
  myservo2.attach(10);
}

void loop() 
{
  IBus.loop(); // Get an IBus packet
  
  curvalue[0] = IBus.readChannel(0); // Read channel values, range 1000 to 2000
  curvalue[1] = IBus.readChannel(1);
  
  myservo1.write(((curvalue[0]-1000)*1.8)/10); // Set servos to channel values, scaled to degrees, 0 to 180
  myservo2.write(((curvalue[1]-1000)*1.8)/10);
}

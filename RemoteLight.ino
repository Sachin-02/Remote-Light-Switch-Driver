#include "IRremote.h"
#include "IR.h"
#include <Servo.h>

Servo myServo;               // create instance of Servo
IRrecv irrecv(RECEIVER);     // create instance of irrecv
decode_results results;      // create instance of decode_results

void setup() {
  // put your setup code here, to run once:
  myServo.attach(7); // connecting the servo to pin 7

  // aligning the motor piece to be uniform horizontally as it was not the default 
  // starting position on my servo. This value was determined through testing.
  myServo.write(73); 
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
}

void loop() {
 {
 if (irrecv.decode(&results)) // if a signal is received
  switch(results.value) // check if it was volume up or volume down
  {
    case 0xFF629D: 
      Serial.println("On"); 
      myServo.write(93); // turns my light switch on
      break;
    case 0xFFA857: 
      Serial.println("Off");  
      myServo.write(53); // turns my light switch off
      break;
    case 0xFFFFFFFF: Serial.println(" REPEAT");break;  
    default: Serial.println(" other button");
  }
  irrecv.resume(); // continue to wait for the next signal
 }
}

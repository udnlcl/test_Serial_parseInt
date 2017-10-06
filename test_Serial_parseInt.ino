/*
  Serial parse
  
  Demonstrates the use of the inbiult function, Serial.parseInt()
  
  As an example, two values seperated by a comma can be sent serially that gets 
  assigned to two different variable. These two variables will affect the ON and
  OFF time (in ms) delay of the blinking LED. If only one value is sent, then it 
  will get assiged to only first variable without affecting the second one. 
  
  This logic can be exteded to parse more than two values.  


  
  Connections:

  Uses the on-board LED connected to pin 13.


  -------------------------------------------------------------------------------
  
  This example code is in the public domain.

  modified 24 Mar 2017
  by Manoj Sharma
  
  imanoj_sharma@yahoo.com
  
  https://twitter.com/irahulone

  -------------------------------------------------------------------------------
 
*/

const int ledPin = 13;

int on_delay  = 1000;
int off_delay = 1000;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  
   if(Serial.available() > 0) // checks for any incomming serial data
   {
      // the values gets assigned to the following variables in the order 
      // are received
      on_delay  = Serial.parseInt(); 
      off_delay = Serial.parseInt(); 
   }

   // LED blink sequence
   digitalWrite(ledPin,1);
   delay(on_delay);
   digitalWrite(ledPin,0);
   delay(off_delay);

    // print the updated values
   Serial.print(on_delay); Serial.print(", ");
   Serial.print(off_delay); //Serial.print(", ");
   Serial.println();
   
}




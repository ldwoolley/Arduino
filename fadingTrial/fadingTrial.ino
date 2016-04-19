/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 
 */
int maxbrightness = 22;
int minbrightness = 0;
int brightness1 = 0;    // how bright the LED is
int fadeAmount1 = 1;    // how many points to fade the LED by
int brightness2 = 7;    // how bright the LED is
int fadeAmount2 = fadeAmount1;    // how many points to fade the LED by
int brightness3 = 14;    // how bright the LED is
int fadeAmount3 = fadeAmount1;    // how many points to fade the LED by
int brightness4 = 21;    // how bright the LED is
int fadeAmount4 = fadeAmount1;    // how many points to fade the LED by

void setup()  { 
  // declare pin 9 to be an output:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
} 

void loop()  { 
  // set the brightness of pin 9:
  analogWrite(3, brightness1);    
  analogWrite(5, brightness2);    
  analogWrite(9, brightness3);    
  analogWrite(11, brightness4);     

  // change the brightness for next time through the loop:
  brightness1 = brightness1 + fadeAmount1;
  brightness2 = brightness2 + fadeAmount2;
  brightness3 = brightness3 + fadeAmount3;
  brightness4 = brightness4 + fadeAmount4;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness1 <= minbrightness || brightness1 >= maxbrightness) {
    fadeAmount1 = -fadeAmount1 ; 
  }
  if (brightness2 <= minbrightness || brightness2 >= maxbrightness) {
    fadeAmount2 = -fadeAmount2 ; 
  }     
  if (brightness3 <= minbrightness || brightness3 >= maxbrightness) {
    fadeAmount3 = -fadeAmount3 ; 
  }
  if (brightness4 <= minbrightness || brightness4 >= maxbrightness) {
    fadeAmount4 = -fadeAmount4 ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(50);                            
}


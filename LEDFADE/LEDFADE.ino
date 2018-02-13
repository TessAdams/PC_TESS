//Assignment 1
//this sketch fades two outer LEDs while blinking the two middle ones
//this was an attempt to make an LED light pattern 
//consisting of two outer LEDs fading in and out while 
//the inner LEDs blink on and off


const int LED1 = 9;// the pin for the LED
const int LED2 = 10;
const int LED3 = 11;
const int LED4 = 6;
const int BUTTON = 5;

int i = 0; // We'll use this to count up and down

int ButtonValue = 0; //0 = LED off while 1 = LED on

void setup() {

pinMode(BUTTON, INPUT); //tells arduino BUTTON is an input
 
pinMode(LED1, OUTPUT); // tell Arduino LED is an output
pinMode(LED2, OUTPUT); // tell Arduino LED is an output
pinMode(LED3, OUTPUT); // tell Arduino LED is an output
pinMode(LED4, OUTPUT); // tell Arduino LED is an output

}

void loop(){

//ButtonValue = digitalRead(BUTTON);


//if(ButtonValue != HIGH){

  //if button pressed LED2 and LED3 turn on

 // digitalWrite(LED2, i++);
  //digitalWrite(LED3, i++);
  
//}

//else{
  //else, the button is not pressed, turns LED2 and LED3 off
 // digitalWrite(LED2,LOW);
  //digitalWrite(LED3,i--);
//}
  
for (i = 0; i < 255; i++) { // loop from 0 to 254 (fade in)
  
analogWrite(LED1, i); // set the LED brightness
delay(10); 
analogWrite(LED2, i); // set the LED brightness
delay(10); 
analogWrite(LED3, i); // set the LED brightness
delay(10); 
analogWrite(LED4, i); // set the LED brightness
delay(10); 

}
  
  

for (i = 255; i > 0; i--) { // loop from 255 to 1 (fade out)
  
analogWrite(LED1, i); // set the LED brightness
delay(10); 
analogWrite(LED2, i); // set the LED brightness
delay(10); 
analogWrite(LED3, i); // set the LED brightness
delay(10); 
analogWrite(LED4, i); // set the LED brightness
delay(10); // Wait 10ms

}

  }




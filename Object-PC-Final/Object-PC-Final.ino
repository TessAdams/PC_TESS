//Object is an interactive design that encompasses over 20 LEDs blinking and fading on a large plastic panel with a sheet of fake grass.  
//As an individual is detected by the motion sensor located at the center of the piece, 
//the 4 main LED panels located on top of the fake grass perform a light configuration, blinking in a timed pattern. 
//However, when no motion is detected, these 4 panels remain lit up. 
//All the while, LED's fading in and out illuminate the sides and edges of the plastic base. 
//interacting with the piece at times may seem unpredictable however, this is a core element in the piece as a whole. 

//this code derives influence from the various resources on the millis() function from the Arduino website as well as YouTube tutorials. 


const int led1 =  13;
const int led2 =  12;
const int led3 =  11;
const int led4 =  10;
  
 int led9 =  3;


int ledState1 = LOW;
int ledState2 = LOW;
int ledState3 = LOW;
int ledState4 = LOW;




unsigned long previousMillis = 0;      
unsigned long previousMillis2 = 0; 
unsigned long previousMillis3 = 0;
unsigned long previousMillis4 = 0;




const long interval1 = 1000;         
const long interval2 = 1000+10;
const long interval3 = 1000+20;
const long interval4 = 1000+30;


 int sensor = A0; 
 int val; 
 int state = LOW; 

int brightness = 0;    
int fadeAmount = 1.5;   

void setup() {

  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
 
  pinMode(led9, OUTPUT);

}

void loop() {

  FADE();
  val = analogRead(sensor);
Serial.println(val/4);




if (val>1){

  LED1();
  LED2();
  LED3();
  LED4();
}

else if (val<1){

nomotion();
  
  }
 
}

void FADE(){
   analogWrite(led9, brightness);

  
  brightness = brightness + fadeAmount;

  
  if (brightness <= 0 || brightness >= 255) { 
    fadeAmount = -fadeAmount;
  }
}

void LED1(){
  
  unsigned long currentMillis = millis();


  if (currentMillis - previousMillis >= interval1) {
   
    previousMillis = currentMillis;

    
    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }

    digitalWrite(led1, ledState1);
   

  }
}



void LED2(){

  unsigned long currentMillis2 = millis();

  if (currentMillis2 - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis2;

    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }

  
    digitalWrite(led2, ledState2);
    

  }
}



void LED3(){

  unsigned long currentMillis3 = millis();

  if (currentMillis3 - previousMillis3 >= interval3) {
    // save the last time you blinked the LED
    previousMillis3 = currentMillis3;

    if (ledState3 == LOW) {
      ledState3 = HIGH;
    } else {
      ledState3 = LOW;
    }

  
    digitalWrite(led3, ledState3);
  

  }
}



void LED4(){

  unsigned long currentMillis4 = millis();

  if (currentMillis4 - previousMillis4 >= interval4) {

    previousMillis4 = currentMillis4;

   
    if (ledState4 == LOW) {
      ledState4 = HIGH;
    } else {
      ledState4 = LOW;
    }

    
    digitalWrite(led4, ledState4);
   

  }
}

void nomotion(){

  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  
  
}



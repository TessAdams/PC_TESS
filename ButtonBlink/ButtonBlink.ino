const int LED = 13; //initializes pin for LED 
const int BUTTON =7; //initializes imput pin where the pushbutton is connected

int val = 0; //val is used to store the state of the input pin

int state = 0; //0 = LED off while 1 = LED on

void setup(){
  pinMode(LED,OUTPUT); //tells arduino LED is an output
  pinMode(BUTTON, INPUT); //tells arduino BUTTON is an input
}

void loop(){
  val = digitalRead(BUTTON); //reads the input value and stores it
  
  //CHECK WHETHER THE INPUT IS HIGH (button pressed)
  //change the state

if(val == HIGH){
  state = 1 -state; 
} 

if (state == 1){
  digitalWrite(LED, HIGH); //turn LED on
}
else {
  digitalWrite(LED, LOW);
}
  
}



// Reads analogue sensor and writes value to the serial port

int sensorPin = A0; //sensor hooked up to analog pin 0
int val;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

void setup() {

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
Serial.begin(9600); // Start serial communication at 9600 bps

}

void loop() {
val = analogRead(sensorPin); //read sensor and assign to variable called val
delay(100); // Wait 100 milliseconds
Serial.write(val); //make sure is active when opening processing
//Serial.println(val); //to check the values in serial monitor


  if (val < '1') { // If 0 received
    digitalWrite(led1, HIGH); // turn LEDs off
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH); // turn LEDs off
    digitalWrite(led4, HIGH);
  }
  else if (val > '1') { // If 1 received
    digitalWrite(led1, LOW); // turn the LED at pin 1 on
    digitalWrite(led2, LOW); // other LED off
    digitalWrite(led3, LOW); // turn LEDs off
    digitalWrite(led4, LOW);
  }
 
  delay(10); // Wait 10 milliseconds
}


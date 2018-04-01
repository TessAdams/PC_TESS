///// This is the Arduino sketch used for the 2nd iteration of Midterm projects
/////SP/18 for physical computing
/////This sketch draws reference from Allison Berkoy's sketches on transfering data 
/////from arduino to processing using Serial Communication
///This sketch uses input data from a capacitative touch sensor to send information
/// to processing to transforms a desolate, desert like terrain 
/////inspired by skin into a new luminescent realm.




// Reads analogue sensor and writes value to the serial port

int sensorPin = A5; //sensor hooked up to analog pin 0
int val;
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 8;

void setup() {

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
  
Serial.begin(9600); // Start serial communication at 9600 bps

}

void loop() {
val = analogRead(sensorPin); //read sensor and assign to variable called val
delay(100); // must be 100 or values in processing wont work
Serial.write(val/4); //make sure is active when opening processing
//Serial.println(val); //to check the values in serial monitor


  if (val > 700) { // If 0 received
    digitalWrite(led1, HIGH); // turn LEDs off
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  
  }
  else if (val <=80) { // If 1 received
    digitalWrite(led1, LOW); // turn the LED at pin 1 on
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

  }

}


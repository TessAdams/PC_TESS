import processing.serial.*; ///

Serial myPort; ///

int val; ///
float a;                
int num = 12;  
float r;

void setup() {
size(1000,800,P3D);
 stroke(0.01*val);  
 fill(100,100,100,10);
 background(255);
 printArray(Serial.list()); 
String portName = Serial.list()[1]; ///
myPort = new Serial(this, portName, 9600);///
}
void draw() {
  
  if ( myPort.available() > 0) { 
val = myPort.read(); 
println(val);
}

  translate(width/2,height/2);
  
  for (float i=0; i<60; i++) {
    pushMatrix();
  rotate(a + 10*i);
  lights();
  ambientLight(val,200,val*2);
  rotate(r);
     //rect(25,25,25,25);
     r=r+val;
    
  sphere(996);
  sphere(621);
  popMatrix();
  println (val);
  }

}
///// This is the processing sketch used for the 2nd iteration of Midterm projects
/////SP/18 for physical computing
/////This sketch draws reference from a Daniel Shiffman's lesson on building terrains in Processing
////as well as from Allison Berkoy's sketches on transfering data from arduino to processing using Serial Communication
///This sketch, using input data from arduino transforms a desolate, desert like terrain 
/////inspired by skin into a new luminescent realm.

import processing.serial.*;//

Serial myPort; ///

int val; ///


int cols,rows;
int scale = 24; //effects smoothness of terrain
int w = 4500; //width of terrain is..
int h = 1100; //height of terrain is..
 float camera = 0;
 int i=0;
 
 float[][] terrain; //defines two dimensional array

void setup() {
  size(1450, 860,P3D);
  cols = w / scale; //number of columns is width of grid/scale
  
  rows = h / scale; //number of columns is height of grid/scale
  
  terrain = new float[cols][rows]; //2d array w this many cols and rows
  
  String portName = Serial.list()[1]; ///
myPort = new Serial(this, portName, 9600);///
 
}

void draw(){
  
  if ( myPort.available() > 0) { 
val = myPort.read(); 
println(val);
}

  
  camera -= 0.007; //every draw cycle, camera increases a lil
  
   float yoff = camera; //defines y offset value
  for(int y = 0; y < rows; y++)  {
    float xoff = 0; //defines x offset value
    for(int x = 0; x < cols; x++) { 
     terrain[x][y] = map(noise(xoff,yoff), 0, 1, -50, 50); //give a noise value for very x, y, and map the value to -30,30 
      xoff += 0.3;
    }
    yoff += 0.40;
    }
  
  
  //background(165, 136, 105,.01);
   noStroke();
   //stroke(234,192,134,100); //cool effect
     fill(255,15);
     directionalLight(254, 205, 152, 8, 10, -5);
     
     if(val<=100){ 
    
   // if(keyPressed){
       
       stroke(234,192,134,100); //cool effect
      pointLight(57, 20, 100, 100, 100, 0); //color change #1, Heaven
       filter (ERODE); //slows down framerate 
       //filter (DILATE);
       //filter (POSTERIZE,40);
       //filter(BLUR);
       
       ambientLight(152,94,38);
       
      // pointLight(20, 60, 0, 0, 255, 100); //color change #2, Yellow
     // filter (DILATE);
     //ambientLight(200,25,2);
       
     }
 
     translate(width/2,height/2); //draws everything relative to the center of window
     rotateX(PI/3.1);//rotate plane
  translate(-w/2,-h/1.7);
  for(int y = 0; y < rows-1; y++) {
    beginShape(QUAD_STRIP);
    for(int x = 36; x < cols; x++) { 
      vertex(x*scale,y*scale, terrain[x][y]); //put the z value at x, y
      vertex(x*scale,(y+6)*scale, terrain[x][y]); //put z value at x, y+1
    }
    endShape();
  }
}
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>

#include "images.cpp"

// any pins can be used
#define SHARP_SCK  14
#define SHARP_MOSI 7
#define SHARP_SS   30
Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 400, 240);

#define BLACK 0
#define WHITE 1

// input reads the button and is set to the internal pull up
// output will sink the current and is set to low/ grounddd.
#define BUTT 35
#define PIEZO 31
#define PIEZO_SINK 29

int freq = 400; // piezo frequency to play with tone()!
unsigned int step = 0;


void setup() {
  pinMode(PIEZO, OUTPUT);
  pinMode(PIEZO_SINK, INPUT_PULLDOWN);
  pinMode(BUTT, INPUT_PULLUP);

  
  Serial.begin(9600);
  Serial.println("(-. - ) zzzZZZz!");

   // start & clear the display
  display.begin();
  display.clearDisplay();

  // draw a single pixel
  display.drawPixel(10, 10, BLACK);
  display.refresh();
  delay(500);
  
  display.clearDisplay();

}

void loop() {

  step++;

  
  freq = random(2000) + 1200 ;
  //freq = random(400);
  
  // when the button is pressed the input pin that is pulled high is drained into button output
  if(digitalRead(BUTT) == LOW) {
    freq = random(300);
    tone(PIEZO, freq );
  }else {
    noTone(PIEZO);
  }
  display.fillRect(0,0,display.width(), display.height(), BLACK);
  display.drawBitmap(0,0, Title_Img, display.width(), display.height(), WHITE);
  //display.drawRect(random(240 - 40),random(400 - 40),40,40, WHITE);
  display.refresh();
  
  //delay(60);

  //delay(500);
  //display.clearDisplay();

}
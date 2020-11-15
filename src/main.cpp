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

int boot_sequence_completed = false;


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
void boot_it() {
  //# show title sequence


  // --------------------------------------------
  // ---------  display Logos -------------------
  // ------------------shout--outs-------to--friends------their--doodles---logos---easter---------eggs-----------------
  // ------- EEE -------------------------------------------------------
  // --------------------------------------------
  // -- display source code --- snippy 00000x0 --
  // --------------------------------------------

  // Toggle Fan

  // Flash Screen

  // Display Stats about system

  // first created
  
  // uptime / downtime

  // hex-kex files

  // display qr codes

  // play melodious icon-sounds

  // Gibbered up speash! OSDIifisd89s9S*(Fg87sdfo98O(*))

  // Display Seed Information - RNG


}
void old_leg() {
  // this old leg is a vestigual ghost
  // only left as reference and to weight down the poor device
  // maybe someday via code surgery it can be removed...
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


}
void leg_it() {
  // The best leg+boot

  int leg = 0;
  if(digitalRead(BUTT) == LOW) {
    leg = 9001;
  }else {
    leg = 0;
  }

  display.clearDisplay();
  display.fillRect(0,0,400,240, WHITE);
  if(leg > 0) {
    // week statick
    int rows = 24;
    int cols = 14;
    int cellSize = 16;
    int cellWidth = random(cellSize);
    for(int i = 1; i < rows; i++) {
      for (int j = 1; j < cols; j++)
      {
        int col = BLACK;
        if(random(2))
          col = WHITE;
        display.fillRect(i * cellSize, j * cellSize, cellWidth, cellSize, col);
        for(int y = 0; y < cellSize; y ++) {
          //display.drawFastHLine(i* cellSize, j*cellSize+y, 16, col);
         // display.drawPixel(i* cellSize, j*cellSize+y, col);
        }
      }
      
    }
  } else {
      // hard black
      display.fillRect(0,0,400,240,BLACK);
    }
  // display is 15 - 20 fps
  // 66.666_ to 50 ms
  display.refresh();
  //delay(50);
  
}
void input_update() {
   if(digitalRead(BUTT) == LOW) {
    freq = random(300);
    tone(PIEZO, freq );
  }else {
    noTone(PIEZO);
  }
}

void loop() {
  if(boot_sequence_completed == false) {
    old_leg();
    if(digitalRead(BUTT) == LOW) {
      delay(5000);
    }
    boot_it();
    boot_sequence_completed = true;
  }
  // The in PUT update
  if(digitalRead(BUTT) == LOW) {
    freq = random(300);
    tone(PIEZO, freq );
  }else {
    noTone(PIEZO);
  }
  // leg_it!!;
  leg_it();
  /* text story. The talking house says:
  Hey there. You there. Hey.
  You worm you. Can you help me out?
  I need to get more 198239hf09d7tddj9.
  can you bring me ___--- -spbshhhh ---.

  I seamed to have ~ .... lost my __________.

  */
  
  /* Tetris S house:
  I am the S house.
  S is for snake.
  (Talks about missing letters)
  How c an you remember what you forgot?
  How do you know that you forgot something?
  How I am missing letters in my vocabulary.
  (He only accepts tetris pieces)
  (shows you how many you have colleted)
  Does not recognise letters. But is a hint
  to the player that villagers have forget things
  and their memories are curppeted. 
  THe world is becoOCMSING cru___PT.
  */

}
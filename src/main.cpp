#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>

#include "images.cpp"
#include "Input.h"
//#include "Board.h"

// any pins can be used
#define SHARP_SCK  14
#define SHARP_MOSI 7
#define SHARP_SS   30
Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 400, 240);

#define BLACK 0
#define WHITE 1

//Board board = Board();
#include "Dumb.h"
//Dumb dumb = Dumb(12);

#define BUTT 35
// input reads the button and is set to the internal pull up
// output will sink the current and is set to low/ grounddd.

#define PIEZO 31
#define PIEZO_SINK 29

int freq = 400; // piezo frequency to play with tone()!
unsigned int step = 0;

//int boot_sequence_completed = false;



void setup() {
  // board setup

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
  //boot_it();
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
void input_update() {
   if(digitalRead(BUTT) == LOW) {
    freq = random(300);
    tone(PIEZO, freq );
  }else {
    noTone(PIEZO);
  }

}

void loop() {
  // The in PUT update
  /*if(digitalRead(BUTT) == LOW) {
    freq = random(300);
    tone(PIEZO, freq );
  }else {
    noTone(PIEZO);
  }

  // leg_it!!;
  leg_it();
  */
 step ++;
 
 for(int i = 0; i < 400; i ++) {
   for(int j = 0; j < 240; j++) {
     if(step % 2 == 1) {
      display.drawPixel(i,j, BLACK);
     } else {
      display.drawPixel(i,j, WHITE);
     }
   }
 } /*
 for(int i = 0; i < 1000; i ++ ) {
     if(step % 2 == 1) {
      display.drawLine(random(400),random(240),random(400),random(240),  WHITE);
     } else {
      display.drawLine(random(400),random(240),random(400),random(240),  BLACK);
     }
 }
 */
//display.clearDisplay();
//board.draw();
display.refresh();
delay(80);

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
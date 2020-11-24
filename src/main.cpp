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
#define ROWS 60
#define COLS 100
#define CELLSIZE 4
#define GENPERFRAME 64
#define STOPATGEN 2000
long gensLeft = 2000;
unsigned long gens = 0;

int buttIn = 0;
int board[COLS][ROWS];
int antX = COLS /2;
int antY = ROWS /2;
int antLastX = COLS /2;
int antLastY = ROWS /2;
int dir = 0; // 0-E, 1-N, 2-W, 3-S. Based of Unit Circle angles

/// # # # # #  SNAKE GAME # # # # # #
#define SGCOLS 20
#define SGROWS 20
#define SGCELLSIZE 2

int snakeX = 10; int snakeY = 10;
int snakeBoard[20][20];
int snakeDir = 0;

void initSnakeBoard() {
  for(int col = 0; col < SGCOLS; col++) {
    for(int row = 0; row < SGROWS; row++) {
      snakeBoard[col][row] = 0;
    }
  }
}
void initSnakeGame() {

}
int checkSnakeCollision() {
  //get next move
  return 0;

}
void moveSnake() {

}

void moveAnt() {
  // Flip Block and rotate ant
  int block = board[antX][antY];
  if(block == 0) { // clockwise
    board[antX][antY] = 1;
    dir = dir -1;
    if(dir <0) {dir = 3;}
  } else if(block == 1){ //anti-clockwise
    board[antX][antY] = 0;
    dir = (dir +1) % 4;
  }

  if(dir==0) {
    antX = (antX +1) %COLS;
  } else if (dir==1) {
    antY = antY -1;
    if(antY < 0) {antY=ROWS-1;}
  } else if (dir==2) {
    antX = antX -1;
    if(antX < 0) {antX=COLS-1;}
  } else if( dir== 3) {
    antY = (antY+1)%ROWS;
  }

}
void drawAnt() {
  int cellSize = CELLSIZE;
  int x = antX*cellSize;
  int y = antY*cellSize;
  display.fillRect(x,y,cellSize,cellSize,BLACK);
  display.setCursor(x+2,y);
  display.setTextColor(WHITE,BLACK);
  display.setTextSize(2);
  display.setTextWrap(false);
  display.print('A');
}

void randoBoard() {
    
    for(int i = 0; i < ROWS; i ++) {
        for(int j = 0; j < COLS; j ++ ) {
            board[j][i] = random(2);
        }
    }
}
void fillBoard(int x1, int y1, int x2, int y2, int cell) {
    for(int i = y1; i < y2; i ++) {
        for(int j = x1; j < x2; j ++ ) {
            if(cell == -1) {
              board[j][i] = random(2);
            } else {
              board[j][i] = cell;
            }
        }
    }
}
void initBoard(int cell) {
    
    for(int i = 0; i < ROWS; i ++) {
        for(int j = 0; j < COLS; j ++ ) {
            //board[j][i] = random(2);
            board[j][i] = cell;
        }
    }
}
void drawBoard() {
  int cellSize = CELLSIZE;
  int padding = 0;
    for(int i = 0; i < ROWS; i ++) {
        for(int j = 0; j < COLS; j ++ ) {
            int x = j*cellSize;
            int y = i*cellSize;
            if(board[j][i] == 0) {
              // Clockwise Block
              // leave empty
               // display.drawRect(x+padding, y+padding, cellSize-padding*2, cellSize-padding*2, BLACK);
            } else if(board[j][i] == 1) {
              // Anti-Clockwise Block
                //display.drawRect(x+padding, y+padding, cellSize-padding*2, cellSize-padding*2, BLACK);
                display.fillRect(x+padding, y+padding, cellSize-padding*2, cellSize-padding*2, BLACK);
            }else if(board[j][i] == 2) {
              // Ant Block - Anti-clockwise

              // Characters at size 2 are 12x16 pixels. So I need to add 2 pixels of padding
              // doing so by drawing 2 rectangles one in front of the character and one behind.
              // To make it a perfect 16x16 block
              // draw padding
              display.fillRect(x,y,3,16,BLACK);
              display.fillRect(x+14,y,2,16,BLACK);
              display.setCursor(x+3,y);
              display.setTextColor(WHITE,BLACK);
              display.setTextSize(2);
              display.setTextWrap(false);
              display.print('A');
            }else if(board[j][i] == 3) {
              // Ant Block - Clockwise

              // Characters at size 2 are 12x16 pixels. So I need to add 2 pixels of padding
              // doing so by drawing 2 rectangles one in front of the character and one behind.
              // To make it a perfect 16x16 block
              // draw padding
              display.fillRect(x,y,16,16,BLACK);
              display.setCursor(x+2,y);
              display.setTextColor(WHITE,BLACK);
              display.setTextSize(2);
              display.setTextWrap(false);
              display.print('U');
              display.fillRect(x,y,2,15,BLACK);
              display.fillRect(x+14,y,15,15,BLACK);
            } else if (board[j][i] == 4) {
              display.fillRect(x,y,16,16,BLACK);
              display.setCursor(x+2,y);
              display.setTextColor(WHITE,BLACK);
              display.setTextSize(2);
              display.setTextWrap(false);
              char c = 32+ random(256-32); // skip first 32 special characters
              if(c == 127) {c=128;} // skip the DEL 
              display.print(c);
              display.fillRect(x,y,2,15,BLACK);
              display.fillRect(x+14,y,15,15,BLACK);
            }
        }

    }
    //disp.fillRect(20,20,200,200, BLACK);
    //disp.refresh();

}

/************************************Board messy hack**********************************/
/*
class Board {
    int cells[ROWS][COLS];
    int cellSize;
    //Adafruit_SharpMem& disp;
    //public: Board(Adafruit_SharpMem& display):disp(display){
    public:
    Board(){ }
    void init() {}
    void draw() {}
    
};

Board::Board(){
    cellSize = 16;
    init();
}
void Board::init() {
    for(int i = 0; i < ROWS; i ++) {
        for(int j = 0; j < COLS; j ++ ) {
            cells[j][i] = random(1);
        }
    }
}
void Board::draw() {
    for(int i = 0; i < ROWS; i ++) {
        for(int j = 0; j < COLS; j ++ ) {
            cells[j][i] = 0;
            if(cells[j][i] == 0) {
                int x = j*cellSize;
                int y = i*cellSize;
                //disp.drawRect(j*cellSize+2, i*cellSize+2, cellSize-2, cellSize-2, BLACK);
            }
        }

    }
    //disp.fillRect(20,20,200,200, BLACK);
    //disp.refresh();

}
*/
/**************************************************************************************/
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

  // Init game objects
  initBoard(0);
   // start & clear the display
  display.begin();
  display.clearDisplay();

  // draw a single pixel
  display.fillRect(0,0,400,240,BLACK);
  display.drawBitmap(0,0,Title_Img, 400, 240, WHITE);
  display.fillRect(16,16,16,32, BLACK);
  display.refresh();
  delay(500);
  if(digitalRead(BUTT) == LOW) {
    display.fillRect(16,16,16,32, WHITE);
    display.refresh();
    delay(500);
    display.fillRect(16,16,16,32, BLACK);
    display.refresh();
    delay(500);
    display.fillRect(16,16,16,32, WHITE);
    display.refresh();
    delay(500);
    display.fillRect(16,16,16,32, BLACK);
    display.refresh();
    delay(500);
    display.fillRect(16,16,16,32, WHITE);
    display.refresh();
    delay(500);
    display.fillRect(16,16,16,32, BLACK);
    display.refresh();
    delay(500);
    display.fillRect(16,16,16,32, WHITE);
    display.refresh();
    delay(500);
  }
  
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
    buttIn = 1;
    fillBoard(10,10,20,20,-1);
    gensLeft += 100;
    
  }else {
    noTone(PIEZO);
    buttIn = 0;
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
 input_update();
 
 /*
 for(int i = 0; i < 400; i ++) {
   for(int j = 0; j < 240; j++) {
     if(step % 2 == 1) {
      display.drawPixel(i,j, BLACK);
     } else {
      display.drawPixel(i,j, WHITE);
     }
   }
 } 
 */
 
 for(int i = 0; i < 10; i ++ ) {
     if(step % 2 == 1) {
      display.drawLine(random(400),random(240),random(400),random(240),  WHITE);
     } else {
      display.drawLine(random(400),random(240),random(400),random(240),  BLACK);
     }
 }
 
//display.clearDisplay();
//board.draw();
//display.clearDisplay();
display.drawRect(0,0,400,240, BLACK);
display.fillScreen(WHITE);
drawBoard();


if(buttIn == 1) {
}

if(gensLeft > 0) {
  for (int i = 0; i < GENPERFRAME; i++) {
    moveAnt();
    gens++;
    gensLeft --;
  }
  
}
drawAnt();


display.setCursor(0,16);
display.setTextColor(WHITE,BLACK);
display.setTextSize(2);
display.setTextWrap(true);
display.print("Generations:");
display.println(gens);
display.print("Life: ");
display.print(gensLeft);


// Display Random Char River
/*
for(int i = 0; i < 99; i ++) {
  char c = 32+ random(256 - 32);
  if(c==127) { c= 32;}
  display.print(c);
}
*/

display.refresh();
//delay(40);

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
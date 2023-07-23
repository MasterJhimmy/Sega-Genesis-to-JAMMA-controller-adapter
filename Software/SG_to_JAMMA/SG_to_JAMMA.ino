//Code by MasterJhimmy (2023) 
//Available at: https://github.com/MasterJhimmy/Sega-Genesis-to-JAMMA-controller-adapter/ 
//
//Install jonthysell's "SegaController" library:
//https://github.com/jonthysell/SegaController

#include <SegaController.h>
//      Sega Genesis/Mega Drive port (male DB9)
//
//     \----------------------------------------/
//      \ A0      A1      A2       A3      +5V /
//       \    A4      D13     GND      A5     /
//        \----------------------------------/
//
//                        or
//
//           \-----------------------------/
//            \ 1     2     3     4     5 /
//             \   6     7     8     9   /
//              \-----------------------/
//
//     Both are the front view of the male connector
//
//
//  Pay attention to pins 5 and 8, +5V and GND respectively.
//  They are a good way to check if the orientation of your 
//  DB9 connector is correct. 

//                        Change these pins if you're using another Arduino board.
//                       (DB9 Pin 7, DB9 Pin 1, DB9 Pin 2, DB9 Pin 3, DB9 Pin 4, DB9 Pin 6, DB9 Pin 9)
SegaController controller(13,        14,        15,        16,        17,        18,        19       );
word currentState = 0;

const int JAMMA_COIN = 1;
const int JAMMA_UP = 2;
const int JAMMA_DW = 3;
const int JAMMA_LEFT = 4;
const int JAMMA_RIGHT = 5;
const int JAMMA_1 = 6;
const int JAMMA_2 = 7;
const int JAMMA_3 = 8;
const int JAMMA_4 = 9;
const int JAMMA_5 = 10;
const int JAMMA_6 = 11;
const int JAMMA_ST = 12;



void setup() {

  //If a pull-up is needed on the output (JAMMA connector), uncomment the section bellow
//  pinMode(JAMMA_COIN, INPUT_PULLUP);  
//  pinMode(JAMMA_UP, INPUT_PULLUP);
//  pinMode(JAMMA_DW, INPUT_PULLUP);
//  pinMode(JAMMA_LEFT, INPUT_PULLUP);
//  pinMode(JAMMA_RIGHT, INPUT_PULLUP);
//  pinMode(JAMMA_1, INPUT_PULLUP);
//  pinMode(JAMMA_2, INPUT_PULLUP);
//  pinMode(JAMMA_3, INPUT_PULLUP);
//  pinMode(JAMMA_4, INPUT_PULLUP);
//  pinMode(JAMMA_5, INPUT_PULLUP);
//  pinMode(JAMMA_6, INPUT_PULLUP);
//  pinMode(JAMMA_ST, INPUT_PULLUP);

  pinMode(JAMMA_COIN, OUTPUT);
  pinMode(JAMMA_UP, OUTPUT);
  pinMode(JAMMA_DW, OUTPUT);
  pinMode(JAMMA_LEFT, OUTPUT);
  pinMode(JAMMA_RIGHT, OUTPUT);
  pinMode(JAMMA_1, OUTPUT);
  pinMode(JAMMA_2, OUTPUT);
  pinMode(JAMMA_3, OUTPUT);
  pinMode(JAMMA_4, OUTPUT);
  pinMode(JAMMA_5, OUTPUT);
  pinMode(JAMMA_6, OUTPUT);
  pinMode(JAMMA_ST, OUTPUT);

}

void loop() {
    currentState = controller.getState();
    output_write();
}

void output_write(){
  digitalWrite(JAMMA_COIN, ((currentState & SC_BTN_MODE)    ? 0 : 1));
  digitalWrite(JAMMA_UP, ((currentState & SC_BTN_UP)    ? 0 : 1));
  digitalWrite(JAMMA_DW, ((currentState & SC_BTN_DOWN)  ? 0 : 1));
  digitalWrite(JAMMA_LEFT, ((currentState & SC_BTN_LEFT)  ? 0 : 1));
  digitalWrite(JAMMA_RIGHT, ((currentState & SC_BTN_RIGHT)  ? 0 : 1));
  digitalWrite(JAMMA_1, ((currentState & SC_BTN_A)  ? 0 : 1));
  digitalWrite(JAMMA_2, ((currentState & SC_BTN_B)  ? 0 : 1));
  digitalWrite(JAMMA_3, ((currentState & SC_BTN_C)  ? 0 : 1));
  digitalWrite(JAMMA_4, ((currentState & SC_BTN_X)  ? 0 : 1));
  digitalWrite(JAMMA_5, ((currentState & SC_BTN_Y)  ? 0 : 1));
  digitalWrite(JAMMA_6, ((currentState & SC_BTN_Z)  ? 0 : 1));
  digitalWrite(JAMMA_ST, ((currentState & SC_BTN_START)  ? 0 : 1));
  
}

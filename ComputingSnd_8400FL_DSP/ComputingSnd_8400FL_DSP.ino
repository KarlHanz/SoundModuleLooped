/*

  Typical pin layout used:
  RC522 MODULE    Uno/Nano/Pro mini   JQ8400FL         Speaker

                  GND                 GND pin 06
                  D9
                  3.3V                vcc pin 07
                  D4 RX               TX pin 04
                  D5 TX               RX pin 03
                                      spk 1 (+) pin 10       spr +
                                      spk 2 (-) pin 09       spr -
*/


#include <SoftSerial.h>
#include <TinyPinChange.h>
SoftSerial mySerial(2, 3); // RX=digital pin 2, P2 on DSP, TX=digital pin 3, P3 on DSP


// UART commands to JQ8400FL
byte Cmd07[6] = {0xAA, 0x07, 0x02, 0x00, 0x01, 0xB4}; //play 1st MP3; filename : 01.mp3
byte Cmd13[5] = {0xAA, 0x13, 0x01, 0x0A, 0xC8}; // set to level 10
byte Cmd1A[5] = {0xAA, 0x1A, 0x01, 0x02, 0xC7}; // set EQ ROCK



// byte Cmd13[5] = {0xAA, 0x13, 0x01, 0x14, 0xD2}; // set volume to level 20


void setup() {
  mySerial.begin(9600); // Initial serial communication with JQ8400Fl
  }


void playAudio() {
  mySerial.write(Cmd1A, 5); // set EQ
  mySerial.write(Cmd13, 5); // set volume
  mySerial.write(Cmd07, 6); // play MP3
  
}
  
void loop() {
  playAudio();
  delay(100000);
}

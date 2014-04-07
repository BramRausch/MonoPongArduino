/* This is monopong on the adafruit neopixel stick.
it uses 2 buttons connected on the pins 4 and 5.
the neoPixel stick must be connected to pin 6 */

//NOTE: this program uses the adafruit neopixel library

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_GRB + NEO_KHZ800);

int pos = 0;
int dir = 0;
int A = HIGH;
int B = HIGH;

void setup(){
  strip.begin();
  strip.show();
  
  strip.setBrightness(64);
  
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}
void loop(){
  A = digitalRead(4);
  B = digitalRead(5);
  
  if(dir == 0){
    if (A == LOW){
      if(pos > 5){
        dir = 1;
      } else{
        for(int i = 0; i < 8; i++){
          strip.setPixelColor(i, 255, 0, 0);
          strip.show();
        }  
        delay(200);
        reset();
      }
    }
    if(pos < 8){
      if(pos == 7){
        for(int i = 0; i < 8; i++){
          strip.setPixelColor(i, 255, 0, 0);
          strip.show();
        }  
        delay(500);
        reset();
      }
      pos++;
      strip.setPixelColor(pos, 255, 0, 255);
      strip.show();
      strip.setPixelColor(pos, 0, 0, 0);
      delay(100);
    }
  } else if (dir == 1){
     if (B == LOW){
      if(pos < 3){
        dir = 0;
      } else{
        for(int i = 0; i < 8; i++){
          strip.setPixelColor(i, 255, 0, 0);
          strip.show();
        }
        delay(200);
        reset();
      }
    }
    if(pos > (-1)){
      if(pos == 0){
        for(int i = 0; i < 8; i++){
          strip.setPixelColor(i, 255, 0, 0);
          strip.show();
        }  
        delay(500);
        reset();
      }
      pos--;
      strip.setPixelColor(pos, 255, 0, 255);
      strip.show();
      strip.setPixelColor(pos, 0, 0, 0);
      delay(100);
    }
  }
}
void reset(){
  int pos = 0;
  int dir = 0;
  int state = HIGH;
  
  for(int i = 0; i < 8; i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
}

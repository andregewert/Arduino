/**
 * Simple test sketch for ArduGame / U8G2
 * 
 * Copyright (c) 2020 André Gewert <agewert@ubergeek.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
#include <ArduGame_U8G2.h>
#include <Controller/AnalogStickController.h>

#define TEST_FRAMES 50

// Example for a SH1106 driven OLED display with 128x96 pixels; controlled via I2C
// For other supported displays see the official documentation: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
//U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 12, /* dc=*/ 4, /* reset=*/ 6);
//U8G2_SSD1309_128X64_NONAME0_F_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 12, /* dc=*/ 4, /* reset=*/ 6);  

ArduGame_U8G2 game;
AnalogStickController controller;
int x, y, i;
int mode = 0;
int passes = 0;

static const unsigned char gfxPlayer[] PROGMEM = {
   0x00, 0x1e, 0x27, 0xee, 0x67, 0x3d, 0x0e, 0x03
};

void setup() {
  game = ArduGame_U8G2();
  game.begin(&u8g2);
  game.setFps(20);
  controller = AnalogStickController();
  controller.begin();
}

void testText() {
  x = random(game.width);
  y = random(game.height);
  game.setCursor(x, y);
  game.drawText("Hallo");
}

void testPixel() {
  for (i = 1; i < 20; i++) {
    x = random(game.width);
    y = random(game.height);
    game.drawPixel(x, y);
  }
}

void testRect() {
  for (i = 1; i < 10; i++) {
    x = random(game.width);
    y = random(game.height);
    game.drawRect(x, y, 20, 10);

    x = random(game.width);
    y = random(game.height);
    game.fillRect(x, y, 20, 10);
  }
}

void testCircle() {
  for (i = 1; i < 10; i++) {
    x = random(game.width);
    y = random(game.height);
    game.drawCircle(x, y, 5);

    x = random(game.width);
    y = random(game.height);
    game.fillCircle(x, y, 5);
  }
}

void testBitmap() {
  x = random(game.width);
  y = random(game.height);
  game.drawBitmap(x, y, gfxPlayer, 8, 8);
}

void loop() {
  if (!game.nextFrame()) return; 
  
  game.clear();
  switch (mode)
  {
    case 0:
      testText(); break;
    case 1:
      testPixel(); break;
    case 2:
      testRect(); break;
    case 3:
      testCircle(); break;
    case 4:
      testBitmap(); break;
  }
  game.updateDisplay();
  passes++;
  
  if (passes == TEST_FRAMES) {
    passes = 0;
    mode++;
    if (mode > 4) mode = 0;
  }
}

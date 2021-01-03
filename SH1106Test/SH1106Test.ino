#include <ArduGame_SH1106.h>
#include <Controller/AnalogStickController.h>

ArduGame_SH1106 game;
AnalogStickController controller;

unsigned char gfxPlayer[] = {
    B00000000,
    B01111000,
    B11100100,
    B01110111,
    B11100110,
    B10111100,
    B01110000,
    B11000000
};

void setup() {
    game = ArduGame_SH1106();
    game.begin();
    game.setFps(20);
    controller = AnalogStickController();
    controller.begin();
}

void loop() {
  int x;
  int y;
  game.clear();

    x = random(game.width);
    y = random(game.height);
    game.drawPixel(x, y);
    //game.fillCircle(x, y, 2);
    //game.fillRect(x, y, 5, 5);
    //game.setCursor(x, y);
    //game.drawText("Hallo");
    //game.drawBitmap(8, 8, gfxPlayer, 8, 8);
  
  game.updateDisplay();
  game.delay(20);
}

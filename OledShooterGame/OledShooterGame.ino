/**
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

#include <OledGame.h>
#include <Controller/AnalogStickController.h>

OledGame game;
AnalogStickController controller;
int x;
int y;

void setup() {
    game = OledGame();
    game.begin();
    game.setFps(20);

    controller = AnalogStickController();
    controller.begin();
    game.tone(500, 10);
}

void loop() {
    if (!game.nextFrame()) return;
    game.clearScreen();
    game.fillRect(x, y, 20, 20, SSD1306_WHITE);
    x++;
    y++;
    game.update();
}

#ifndef Display_h
#define Display_h

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include "src/libs/Timer.h"

class Display {
  public:
    void begin();
    void show(const char *text);
  private:
    Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);
};

#endif
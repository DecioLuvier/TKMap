#include "Display.h"

void Display::begin() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void Display::show(const char *text) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(text);
  display.display();
}

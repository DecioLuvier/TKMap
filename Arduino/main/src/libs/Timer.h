#ifndef Timer_h
#define Timer_h

#include <Arduino.h>

class Timer {
  public:
    Timer(unsigned long interval);
    void tick();
    bool hasElapsed();
    void start();
    void stop();
    void reset();
  private:
    unsigned long interval;
    unsigned long initialTime;
    unsigned long currentTime;
    bool isRunning;
    bool isReady;
};

#endif
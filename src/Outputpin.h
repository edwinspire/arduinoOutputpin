#ifndef Outputpin_h
#define Outputpin_h

#include <Arduino.h>

namespace edwinspire
{

    enum BlinkState
    {
        DISABLE = 0,
        DELAY = 1,
        BLINK = 2
    };

    class OutputPin
    {

    public:
        void setup(int pin);
        void high(void);
        void low(void);
        void blink(unsigned long lowTime, unsigned long highTime, unsigned long delayTime, long blinkTimes);
        void blink(unsigned long lowTime, unsigned long highTime, unsigned long delayTime);
        void blink(unsigned long lowTime, unsigned long highTime);
        int getState(void);

        void loop(void);

    private:
        int _outputPin;
        int _outputState;
        BlinkState _blinkState;

        unsigned long _highTime;
        unsigned long _lowTime;
        unsigned long _startTime;
        unsigned long _blinkTimes;
        unsigned long _lastBlinkTime; // the last time the output pin was blinked
    };

}

#endif
#ifndef __VIEW_H__
#define __VIEW_H__

#pragma once

#include <string>
#include "Led.h"
#include "lightState.h"
#include "LCD.h"

class View
{
private:
    int lightState;
    Led *light1;
    Led *light2;
    Led *light3;
    Led *light4;
    Led *light5;
    LCD *light_lcd;

public:
    View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *light_LCD);
    virtual ~View();
    void setState(int state);
    void lightView();
    void lightOff();
    void lightOn1();
    void lightOn2();
    void lightOn3();
    void lightOn4();
    void lightOn5();
    void lightWarning();

};

#endif /* __VIEW_H__ */
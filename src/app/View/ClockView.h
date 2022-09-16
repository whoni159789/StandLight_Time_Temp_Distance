#ifndef CLOCKVIEW_H
#define CLOCKVIEW_H

#pragma once

#include <time.h>
#include "LCD.h"

class ClockView
{
private:
    LCD *lcd;

public:
    ClockView(LCD *Lcd);
    ~ClockView();
    void updateTime(struct tm *timeData);


};

#endif
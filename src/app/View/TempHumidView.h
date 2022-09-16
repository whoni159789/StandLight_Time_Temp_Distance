#ifndef TEMPHUMIDVIEW_H
#define TEMPHUMIDVIEW_H

#pragma once

#include "LCD.h"

class TempHumidView
{
private:
    LCD *temphumidlcd;

public:
    TempHumidView(LCD *temphumidlcd);
    ~TempHumidView();
    void setTempHumidData(float temp, float humid);

};

#endif
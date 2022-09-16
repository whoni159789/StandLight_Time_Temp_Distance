#include "ClockView.h"
#include <stdio.h>

ClockView::ClockView(LCD *Lcd)
{
    this->lcd = Lcd;    // 내 Class에서 사용하고 있는 변수 : this
}

ClockView::~ClockView()
{}

void ClockView::updateTime(struct tm *timeData)
{
    char buff[30];
    sprintf(buff, "%02d:%02d:%02d", 
    timeData->tm_hour, 
    timeData->tm_min, 
    timeData->tm_sec);
    lcd->WriteStringXY(1, 0, buff);
}
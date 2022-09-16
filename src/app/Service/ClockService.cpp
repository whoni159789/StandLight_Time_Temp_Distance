#include "ClockService.h"

ClockService::ClockService(ClockView *clkview)
{
    curTime = 0;
    clockView = clkview;
}

ClockService::~ClockService()
{}

void ClockService::updateEvent()
{
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);
    clockView->updateTime(timeDate);
}
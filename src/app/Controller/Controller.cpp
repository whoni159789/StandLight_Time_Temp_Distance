#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clkserv, TempHumidService *temphumidservice)
{
    service = serv;
    clockservice = clkserv;
    this->temphumidservice = temphumidservice;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if(strBtn == "modeButton") 
    {
        service->updateState("modeButton");
    }
    
    if(strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }

    if(strBtn == "clockUpdate")
    {
        clockservice->updateEvent();
    }
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    if(dhtData.Temp>=27)
    {
        service->updateState("warningTemp");
    }
    else
    {
        service->updateState("normalTemp");
    }
    temphumidservice->updateEvent(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}
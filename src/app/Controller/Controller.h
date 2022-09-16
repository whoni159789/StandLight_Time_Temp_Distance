#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#pragma once

#include <string>
#include "DHT_Data.h"
#include "Service.h"
#include "ClockService.h"
#include "TempHumidService.h"

class Controller
{
private:
    Service *service;
    ClockService *clockservice;
    TempHumidService *temphumidservice;

public:
    Controller(Service *serv, ClockService *clkserv, TempHumidService *temphumidservice);
    virtual ~Controller();
    void updateEvent(std::string strBtn);
    void updateTempHumid(DHT_Data dhtData);
    void updateDistance(int distance);
};

#endif /* __CONTROLLER_H__ */
#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#pragma once

#include "DHT_Data.h"
#include "TempHumidView.h"

class TempHumidService
{
private:
    TempHumidView *temphumidview;

public:
    TempHumidService(TempHumidView *temphumidview);
    ~TempHumidService();
    void updateEvent(DHT_Data dhtData);


};

#endif
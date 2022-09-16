#include "TempHumidService.h"

TempHumidService::TempHumidService(TempHumidView *temphumidview)
{
    this->temphumidview = temphumidview;
}

TempHumidService::~TempHumidService()
{}

void TempHumidService::updateEvent(DHT_Data dhtData)
{
    float temp, humid;
    temp = (float)dhtData.Temp + (float)dhtData.TempDec/10.0;
    humid = (float)dhtData.RH + (float)dhtData.RHDec/10.0;

    this->temphumidview->setTempHumidData(temp, humid);
}
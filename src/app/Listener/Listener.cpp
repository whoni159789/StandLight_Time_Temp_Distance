#include "Listener.h"
#include "wiringPi.h"

Listener::Listener(Button *modebutton, Button *powerbutton, ClockCheck *clock, 
                    DHT11 *dht11, UltraSonic *ultrasonic, Controller *control)
{
    this->modeButton = modebutton;
    this->powerButton = powerbutton;
    this->clockcheck = clock;
    this->dht11 = dht11;
    this->ultrasonic = ultrasonic;
    this->controller = control;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if(modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }
    if(powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }
    if(clockcheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTempHumidTime = 0;
    if(millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = this->dht11->readData();
        if(!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
        }
    }

    static unsigned int prevUltrasnoicTime = 0;
    if(millis() - prevUltrasnoicTime > 1000)
    {
        prevUltrasnoicTime = millis();
        int distance = ultrasonic->readDistance();
        controller->updateDistance(distance);
    }

}
    
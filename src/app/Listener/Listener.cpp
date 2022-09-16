#include "Listener.h"
#include "wiringPi.h"

Listener::Listener(Button *modebutton, Button *powerbutton, ClockCheck *clock, DHT11 *dht11, Controller *control)
{
    this->modeButton = modebutton;
    this->powerButton = powerbutton;
    this->clockcheck = clock;
    this->dht11 = dht11;
    this->controller = control;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if(this->modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }
    if(this->powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }
    if(this->clockcheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTime = 0;
    if(millis() - prevTime > 2000)
    {
        prevTime = millis();
        DHT_Data dhtData = this->dht11->readData();
        if(!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
        }
    }
}
    
#ifndef __LISTENER_H__
#define __LISTENER_H__

#pragma once

//hw
#include "Button.h"
#include "ClockCheck.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"

//src
#include "Controller.h"

class Listener
{
private :
    Button *modeButton;
    Button *powerButton;
    ClockCheck *clockcheck;
    DHT11 *dht11;
    UltraSonic *ultrasonic;
    Controller *controller;
    

public:
    Listener(Button *modebutton, Button *powerbutton, ClockCheck *clock, DHT11 *dht11, UltraSonic *ultrasonic, Controller *control);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */

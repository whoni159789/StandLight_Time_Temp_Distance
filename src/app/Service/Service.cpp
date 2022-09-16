#include "Service.h"

Service::Service(View *viewer)
{
    lightState = LIGHT_OFF;
    Temp_lightState = LIGHT_OFF;
    view = viewer;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_1;
            }
            if (strState == "warningTemp") 
            {
                lightState = LIGNT_WARNING;
            }
            view->setState(lightState);

        break;

        case LIGHT_1:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") 
            {
                lightState = LIGHT_OFF;
            }
            if (strState == "warningTemp") 
            {
                lightState = LIGNT_WARNING;
            }
            view->setState(lightState);
        break;

        case LIGHT_2:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") 
            {
                lightState = LIGHT_OFF;
            }
            if (strState == "warningTemp") 
            {
                lightState = LIGNT_WARNING;
            }
            view->setState(lightState);
        break;

        case LIGHT_3:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") 
            {
                lightState = LIGHT_OFF;
            }
            if (strState == "warningTemp") 
            {
                lightState = LIGNT_WARNING;
            }
            view->setState(lightState);
        break;

        case LIGHT_4:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") 
            {
                lightState = LIGHT_OFF;
            }
            if (strState == "warningTemp") 
            {
                lightState = LIGNT_WARNING;
            }
            view->setState(lightState);
        break;

        case LIGHT_5:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton") 
            {
                lightState = LIGHT_OFF;
            }
            if (strState == "warningTemp") 
            {
                lightState = LIGNT_WARNING;
            }
            view->setState(lightState);
        break;

        case LIGNT_WARNING:
            if(strState == "normalTemp")
            {
                lightState = LIGHT_OFF;
                view->setState(lightState);
            }
        break;
    }
}

void Service::updateDistance(int distance)
{
    if(distance >= 50)
    {
        Temp_lightState = lightState;
        lightState = LIGHT_OFF;
    }
    else if( (Temp_lightState != LIGHT_OFF) && (distance > 0 && distance < 50) )
    {
        lightState = Temp_lightState;
    }
    view->setState(lightState);
}
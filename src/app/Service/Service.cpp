#include "Service.h"
#include <stdio.h>

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
            if(Temp_lightState == LIGHT_READY)
            {
                if (strState == "modeButton") 
                {
                    lightState = LIGHT_1;
                }
                view->setState(lightState);
            }
            

        break;

        case LIGHT_1:
            if(Temp_lightState == LIGHT_READY)
            {
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
            }
            
        break;

        case LIGHT_2:
            if(Temp_lightState == LIGHT_READY)
            {
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
            }
            
        break;

        case LIGHT_3:
            if(Temp_lightState == LIGHT_READY)
            {
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
            }
            
        break;

        case LIGHT_4:
            if(Temp_lightState == LIGHT_READY)
            {
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
            }
            
        break;

        case LIGHT_5:
            if(Temp_lightState == LIGHT_READY)
            {
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
            }

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
    static unsigned int count = 0;
    
    if(Temp_lightState == LIGHT_READY && distance >= 20)
    {
        count++;
        printf("카운트 : %d\n", count);
        if(count >= 5)
        {
            Temp_lightState = lightState;
            lightState = LIGHT_OFF;
            count = 0;
        }
        
    }
    else if(Temp_lightState != LIGHT_READY && distance > 0 && distance < 20)
    {
        lightState = Temp_lightState;
        Temp_lightState = LIGHT_READY;
    }
    view->setState(lightState);
}
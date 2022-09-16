#ifndef SERVICE_H
#define SERVICE_H

#pragma once

#include <string>
#include "View.h"
#include "lightState.h"

class Service
{
private:
    int lightState;
    int Temp_lightState;
    View *view;

public:
    Service(View *viewer);
    ~Service();
    void updateState(std::string strState);
    void updateDistance(int distance);


};

#endif
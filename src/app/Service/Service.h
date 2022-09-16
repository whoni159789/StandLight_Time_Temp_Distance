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
    View *view;

public:
    Service(View *viewer);
    ~Service();
    void updateState(std::string strState);


};

#endif
 #include <iostream>
 #include <wiringPi.h>
//src
#include "Button.h"
#include "Led.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "LCD.h"
#include "DHT11.h"
#include "DHT_Data.h"

//app
#include "Listener.h"
#include "Controller.h"
#include "Service.h"
#include "ClockService.h"
#include "TempHumidService.h"
#include "View.h"
#include "ClockView.h"
#include "TempHumidView.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Button modeButton(27);
    Button powerButton(28);
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    UltraSonic ultrasonic(5, 4);
    LCD lcd(new I2C("/dev/i2c-1", 0x25));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    ClockView clockview(&lcd);
    TempHumidView temphumidview(&lcd);
    Service service(&view);
    ClockService clockservice(&clockview);
    TempHumidService temphumidservice(&temphumidview);
    Controller control(&service, &clockservice, &temphumidservice);
    ClockCheck clockcheck;
    Listener listener(&modeButton, &powerButton, &clockcheck, &dht, &ultrasonic, &control);

     while (1)
     {
        listener.checkEvent();
        view.lightView();
        delay(50);
     }

    return 0;
}
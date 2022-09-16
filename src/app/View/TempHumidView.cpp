#include "TempHumidView.h"
#include <stdio.h>

TempHumidView::TempHumidView(LCD *temphumidlcd)
{
    this->temphumidlcd = temphumidlcd;
}

TempHumidView::~TempHumidView()
{}

void TempHumidView::setTempHumidData(float temp, float humid)
{

        char buff[30];
        sprintf(buff, "%.1f C", temp);
        temphumidlcd->WriteStringXY(0, 10, buff);
        printf("%s\n",buff);

        sprintf(buff, "%.1f %c",humid, '%');
        temphumidlcd->WriteStringXY(1, 10, buff);
        printf("%s\n",buff);

}
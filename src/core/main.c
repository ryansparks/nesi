#include <nesi.h>
#include "camera.h"
#include "dateTime.h"
#include <string.h>

Boolean getPicture(void);

int main(void)
{
    nesi.init();

    camera.init();
    dateTime.init();

    DateAndTime tempTime;

    tempTime.hour = 18;
    tempTime.minute = 44;
    tempTime.second = 0;

    tempTime.month = MAY;
    tempTime.day = 25;
    tempTime.year = 14;

    dateTime.set(tempTime);

    while(1)
    {
        if(button.getStroke() == KEYSTROKE_SINGLE)
        {
            button.disableStroke();
            ledB.dutycycle(1);
            getPicture();
            ledB.dutycycle(0);
            button.enableStroke();
        }
    }
    return 0;
}

Boolean getPicture()
{
    char filename[32] = {0};
    sprintf(filename, "%s.jpg", dateTime.getStamp());

    char *temp = filename;
    while(*temp)
    {
        if(*temp == ':')
            *temp = '.';
        ++temp;
    }
    return camera.getPix(filename);
}
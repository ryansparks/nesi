#include <nesi.h>
#include "camera.h"
#include "dateTime.h"
#include <string.h>

Boolean getPicture(void);

int numPressed = 0;

int main(void)
{
    nesi.init();
    usb.init();
    usb.attach();

    while(1)
    {
        if(button.getStroke() == KEYSTROKE_SINGLE)
        {
            button.disableStroke();
            numPressed++;
            char toprint[32] = {0};
            sprintf(toprint, "button pressed %c times", numPressed);
            usb.print(toprint);
            button.enableStroke();
        }
    }
    return 0;
}
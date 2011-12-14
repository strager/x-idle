// http://coderrr.wordpress.com/2008/04/20/getting-idle-time-in-unix/
// Public domain

#include <X11/extensions/scrnsaver.h>
#include <stdio.h>

int main() {
    XScreenSaverInfo *info = XScreenSaverAllocInfo();
    Display *display = XOpenDisplay(0);

    XScreenSaverQueryInfo(display, DefaultRootWindow(display), info);
    printf("%lu\n", info->idle);
}

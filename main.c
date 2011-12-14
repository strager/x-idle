// http://coderrr.wordpress.com/2008/04/20/getting-idle-time-in-unix/
// Public domain

#include <X11/extensions/scrnsaver.h>
#include <stdio.h>
#include <ctype.h>

unsigned long int get_idle_time() {
    // TODO Deallocations?
    XScreenSaverInfo *info = XScreenSaverAllocInfo();
    Display *display = XOpenDisplay(0);

    XScreenSaverQueryInfo(display, DefaultRootWindow(display), info);
    return info->idle;
}

void print_help(const char *program_name) {
    printf(
        "Usage: %s [milliseconds]\n"
        "\n"
        "  With no arguments, prints milliseconds idle.\n"
        "\n"
        "  With integer argument, returns 0 if user idle\n"
        "  within (argument) milliseconds; else 1.\n",
        program_name
    );
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (!isdigit(argv[1][0])) {
            print_help(argv[0]);
            if (strcmp(argv[1], "-h") == 0) {
                return 0;
            } else {
                return 2;
            }
        }

        // Return 0/1 indicating user idle status
        long unsigned int idle_limit;
        int scanned = sscanf(argv[1], "%lu", &idle_limit);
        if (scanned != 1) {
            print_help(argv[0]);
            return 2;
        }

        if (get_idle_time() >= idle_limit) {
            // User is idle
            return 0;
        } else {
            // User is active
            return 1;
        }
    } else {
        // No argument; just print the idle time
        printf("%lu\n", get_idle_time());
        return 0;
    }
}

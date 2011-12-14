Installing
==========

Requires libxss, a C compiler, and GNU make

    make

Or simply:

    cc -o x-idle -lXss main.c

Running
=======

> Usage: x-idle [milliseconds]
> 
> With no arguments, prints milliseconds idle.
> 
> With integer argument, returns 0 if user idle within
> (argument) milliseconds; else 1.

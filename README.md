Installing
==========

Requires libxss and a C compiler.

Via make:

    make

Or simply:

    cc -o x-idle -lXss main.c

Or without cloning:

    curl -s https://raw.github.com/strager/x-idle/master/main.c | cc -o x-idle -lXss -x c -

Running
=======

> `x-idle` [milliseconds]

With no arguments, prints milliseconds idle.

With integer argument, returns 0 if user idle within (argument) milliseconds;
else 1.

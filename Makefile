all: x-idle

LDFLAGS += -lXss

x-idle: main.o
	$(CC) $(LDFLAGS) -o $@ $+

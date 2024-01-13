CC = g++
CFLAGS = -Wall
LDFLAGS = $(shell pkg-config --cflags --libs opencv4)

TARGET = app

SRCS = app.cpp

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(TARGET)

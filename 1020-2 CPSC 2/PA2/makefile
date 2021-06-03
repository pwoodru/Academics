CC = g++
DEBUG = -g
CFLAGS = -Wall -std=gnu++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: driver.out

driver.out: driver.cpp pixel.h pixel.cpp image.h image.cpp header.h header.cpp
	$(CC) $(CFLAGS) -o driver driver.cpp pixel.cpp image.cpp header.cpp

run: driver.out
	./driver

clean:
	rm *.out

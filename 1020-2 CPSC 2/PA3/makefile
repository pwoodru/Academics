CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = driver

OBJECTS = driver.cpp circle.cpp color.cpp header.cpp image.cpp pixel.cpp point.cpp quadrilateral.cpp shape.cpp triangle.cpp

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS): circle.h color.h header.h image.h pixel.h point.h quadrilateral.h shape.h triangle.h

run:
	./$(TARGET) shapes.txt output.ppm

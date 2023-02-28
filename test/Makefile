CC = g++
CXXFLAGS = -Wall --std=c++11
OBJECTS = main.o network.o 

all: driver 
	
driver: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o driver
main.o: main.cpp network.hpp
	$(CC) $(CXXFLAGS) -c main.cpp -o main.o
network.o: network.cpp network.hpp 
	$(CC) $(CXXFLAGS) -c network.cpp -o network.o
clean:
	rm driver $(OBJECTS)

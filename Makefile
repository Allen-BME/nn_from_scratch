CC = g++
CXXFLAGS = -Wall --std=c++11
OBJECTS = main.o network.o neuron.o vector_math.o

all: driver 
	
driver: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o driver
main.o: main.cpp network.hpp neuron.hpp
	$(CC) $(CXXFLAGS) -c main.cpp -o main.o
network.o: network.cpp network.hpp neuron.hpp
	$(CC) $(CXXFLAGS) -c network.cpp -o network.o
neuron.o: neuron.cpp neuron.hpp vector_math.hpp
	$(CC) $(CXXFLAGS) -c neuron.cpp -o neuron.o
vector_math.o: vector_math.cpp vector_math.hpp
	$(CC) $(CXXFLAGS) -c vector_math.cpp -o vector_math.o
clean:
	rm driver $(OBJECTS)

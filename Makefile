CC = g++
CXXFLAGS = -Wall --std=c++11
OBJECTS = main.o network.o neuron.o nn_math.o

all: driver 
	
driver: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o driver
main.o: main.cpp network.hpp neuron.hpp
	$(CC) $(CXXFLAGS) -c main.cpp -o main.o
network.o: network.cpp network.hpp neuron.hpp
	$(CC) $(CXXFLAGS) -c network.cpp -o network.o
neuron.o: neuron.cpp neuron.hpp nn_math.hpp
	$(CC) $(CXXFLAGS) -c neuron.cpp -o neuron.o
nn_math.o: nn_math.cpp nn_math.hpp
	$(CC) $(CXXFLAGS) -c nn_math.cpp -o nn_math.o
clean:
	rm driver $(OBJECTS)

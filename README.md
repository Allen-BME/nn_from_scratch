# Neural Network

Making a neural network from scratch in C++ following 
[this tutorial](https://victorzhou.com/blog/intro-to-neural-networks/).

TODO:
- organize files (learn about namespaces?)
- finish feedforward for NeuralNetwork
- figure out how best to store data inside NeuralNetwork class:
    - probably want more customization over neurons (e.g. number of weights)
    - figure out what data structures to use for layers
        - lots of iterating through and changing values
        - relatively little amount of adding new data / resizing

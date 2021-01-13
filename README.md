# Neural-Network

An application that allows you to create a neural network with a selected number of layers and neurons. It was created primarily for learning to recognize numbers in pictures. The application uses backpropagation as a form of learning. The application only supports black and white images.

In the "examples" folder there are networks with a given level (in percent) of training.

In the "data" folder there are examples of handwritten numbers on the pictures, which you can use for training the neural network.

### Neural network learning modes:

Linear - sample images that are material for learning a neural network are loaded in the order in which they are arranged in a given folder. After entering the grayscale values of individual image pixels into the first layer of the neural network, they are properly converted by weights and biases placed on the connections between the neurons of subsequent layers. The process repeats until the last layer. Then, backpropagation is performed, modifying the weights and biases respectively based on the introduced example. For the linear mode, backpropagation is performed with each input sample image.

Random - sample images that are material for learning a neural network are loaded randomly from the given folder. After entering the grayscale values of individual image pixels into the first layer of the neural network, they are properly converted by weights and biases placed on the connections between the neurons of subsequent layers. The process repeats until the last layer. Then, backpropagation is performed, modifying the weights and biases respectively based on the introduced example. For the random mode, also backpropagation is performed with each input sample image.

Advanced - sample images that are material for learning a neural network are loaded randomly from the given folder. After entering the grayscale values of individual image pixels into the first layer of the neural network, they are properly converted by weights and biases placed on the connections between the neurons of subsequent layers. The process repeats until the last layer. In the case of this mode, back propagation is performed only after introducing a packet of thirty sample images. Thanks to this, the learning level of the neural network should maintain a steady, gradual increase without decline more often than in the case of the linear or random mode. The weights and biases on the connections between neurons are modified based on the data from the entered image packages.

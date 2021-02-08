# Neural-Network

An application that allows you to create a neural network with a selected number of layers and neurons. It was created primarily for learning to recognize numbers in pictures. The application uses backpropagation as a form of learning. The application only supports black and white images.

In the "examples" folder there are networks with a given level (in percent) of training.

In the "data" folder there are examples of handwritten numbers on the pictures, which you can use for training the neural network.

### Neural network learning modes:

Linear - sample images that are material for learning a neural network are loaded in the order in which they are arranged in a given folder. After entering the grayscale values of individual image pixels into the first layer of the neural network, they are properly converted by weights and biases placed on the connections between the neurons of subsequent layers. The process repeats until the last layer. Then, backpropagation is performed, modifying the weights and biases respectively based on the introduced example. For the linear mode, backpropagation is performed with each input sample image.

Random - sample images that are material for learning a neural network are loaded randomly from the given folder. After entering the grayscale values of individual image pixels into the first layer of the neural network, they are properly converted by weights and biases placed on the connections between the neurons of subsequent layers. The process repeats until the last layer. Then, backpropagation is performed, modifying the weights and biases respectively based on the introduced example. For the random mode, also backpropagation is performed with each input sample image.

Advanced - sample images that are material for learning a neural network are loaded randomly from the given folder. After entering the grayscale values of individual image pixels into the first layer of the neural network, they are properly converted by weights and biases placed on the connections between the neurons of subsequent layers. The process repeats until the last layer. In the case of this mode, back propagation is performed only after introducing a packet of thirty sample images. Thanks to this, the learning level of the neural network should maintain a steady, gradual increase without decline more often than in the case of the linear or random mode. The weights and biases on the connections between neurons are modified based on the data from the entered image packages.

### Instruction

#### Creating a Neural Network
1. Click CREATE NEW button.
2. Enter a network name.
3. Enter a number of you Neural Network leyers.
4. Enter the number of neurons in each layer, separating them with a space.
5. Click OK.

#### Loading Neural Network
1. Click LOAD.
2. Choose one of the floders in "data" folder. (They contain sample Neural Networks with the effectiveness expressed as a percentage in the name of the folder)
3. Click OK.

#### Teaching your neural network
1. Click LEARN.
2. Choose one of the learning modes.
3. Enter the percentage value of the network effectiveness to which it should be trained. After the selected level is reached, training will end.
4. Click START LEARNINGN button.
5. Select the "examples" folder. After training will start, you will receive information about your Neural Network's learning level with after each backpropagation cycle.
6. You can save your trained network by clicking the SAVE button. You will have to select the folder where you want to save your Neural Network.

#### Testing your Neural Network
1. If you want to test each example separately:
a) Click RECOGNIZE.
b) Click Load the example.
c) Choose one of the sample photos with number in folder "examples". You will receive information which digit has been recognized by your network.

2. If you want to test your network on all available examples:
a) Click LEARN.
b) Click STATISTICS.
c) Choose the "examples" folders and click OK. You will receive a percentage information on how many examples of all available examples have been recognized correctly.

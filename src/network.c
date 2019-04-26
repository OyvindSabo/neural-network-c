struct Node
{
  struct Edge *inE;
  struct Edge *outE;
  double value;
};

struct Edge
{
  struct Node *inV;
  struct Node *outV;
  double currentWeight;
  double newWeight;
};

struct Network
{
  struct Node inputLayer[100];
  struct Node hiddenLayer[100];
  struct Node outputLayer[100];
  struct Edge edges[10100];
};

struct NetworkConfig
{
  int inputLength;
  int hiddenLength;
  int outputLength;
  char inputFileName[100];
};

struct Network createNetwork(struct NetworkConfig networkConfig)
{
  int inputLength = networkConfig.inputLength;
  int hiddenLength = networkConfig.hiddenLength;
  int outputLength = networkConfig.outputLength;
  char inputFileName[100] = networkConfig.inputFileName;

  struct Network network;

  // Create the inputLayer
  for (int i = 0; i < inputLength; i++)
  {
    struct Node node;
    struct Edge outE;
    *node.outE = outE;
    node.value = 0;
    network.inputLayer[i] = node;
  }

  // Create the hidden layer
  for (int i = 0; i < hiddenLength; i++)
  {
    struct Node node;
    struct Edge inE;
    struct Edge outE;
    *node.inE = inE;
    *node.outE = outE;
    node.value = 0;
    network.hiddenLayer[i] = node;
  }

  // Create output layer
  for (int i = 0; i < outputLength; i++) {
    struct Node node;
    struct Edge inE;
    *node.inE = inE;
    node.value = 0;
    network.outputLayer[i] = node;
  }

  // Create edges from inputLayer to hiddenLayer
  int edgeIndex;
  edgeIndex = 0;
  for (int i = 0; i < inputLength; i++) {
    for (int j = 0; j < hiddenLength; j++) {
      struct Edge edge;
      *edge.outV = network.inputLayer[i];
      *edge.inV = network.hiddenLayer[j];
      network.edges[edgeIndex].currentWeight = 0;
      network.edges[edgeIndex].newWeight = 0;
      network.inputLayer[i].outE = &network.edges[edgeIndex];
      network.hiddenLayer[j].inE = &network.edges[edgeIndex];
      edgeIndex++;
    }
  }

  // Create edges from hiddenLayer to outputLayer
  for (int i = 0; i < hiddenLength; i++) {
    for (int j = 0; j < outputLength; j++) {
      struct Edge edge;
      *edge.outV = network.hiddenLayer[i];
      *edge.inV = network.outputLayer[j];
      edge.currentWeight = 0;
      edge.newWeight = 0;
      network.hiddenLayer[i].outE = &network.edges[edgeIndex];
      network.outputLayer[j].inE = &network.edges[edgeIndex];
      edgeIndex++;
    }
  }

  // readWeightsFromTextFile(network, inputFileName);
  return network;
};


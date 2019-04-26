struct Node
{
  struct Edge *inE[100];
  struct Edge *outE[100];
  int inECount;
  int outECount;
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
  int inputLength;
  int hiddenLength;
  int outputLength;
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
  struct Network network;
  int inputLength = network.inputLength = networkConfig.inputLength;
  int hiddenLength = network.hiddenLength = networkConfig.hiddenLength;
  int outputLength = network.outputLength = networkConfig.outputLength;

  // Initialize  inputLayer
  for (int i = 0; i < inputLength; i++) {
    network.inputLayer[i].value = 0;
    network.inputLayer[i].inECount = 0;
    network.inputLayer[i].outECount = 0;
  }

  // Initialize hidden layer
  for (int i = 0; i < hiddenLength; i++) {
    network.hiddenLayer[i].value = 0;
    network.hiddenLayer[i].inECount = 0;
    network.hiddenLayer[i].outECount = 0;
  }

  // Create output layer
  for (int i = 0; i < outputLength; i++) {
    network.outputLayer[i].value = 0;
    network.outputLayer[i].inECount = 0;
    network.outputLayer[i].outECount = 0;
  }
  
  // Create edges from inputLayer to hiddenLayer
  int edgeIndex = 0;
  for (int i = 0; i < network.inputLength; i++)
  {
    for (int j = 0; j < network.hiddenLength; j++)
    {
      *network.edges[edgeIndex].outV = network.inputLayer[i];
      *network.edges[edgeIndex].inV = network.hiddenLayer[j];
      network.edges[edgeIndex].currentWeight = 0;
      network.edges[edgeIndex].newWeight = 0;
      network.inputLayer[i].outE[network.inputLayer[i].outECount] = &network.edges[edgeIndex];
      network.hiddenLayer[j].inE[network.hiddenLayer[j].inECount] = &network.edges[edgeIndex];
      network.inputLayer[i].outECount++;
      network.hiddenLayer[i].inECount++;
      edgeIndex++;
    }
  }

  // Create edges from hiddenLayer to outputLayer
  for (int i = 0; i < network.hiddenLength; i++)
  {
    for (int j = 0; j < network.outputLength; j++)
    {
      *network.edges[edgeIndex].outV = network.hiddenLayer[i];
      *network.edges[edgeIndex].inV = network.outputLayer[j];
      network.edges[edgeIndex].currentWeight = 0;
      network.edges[edgeIndex].newWeight = 0;
      network.hiddenLayer[i].outE[network.hiddenLayer[i].outECount] = &network.edges[edgeIndex];
      network.outputLayer[j].inE[network.outputLayer[i].inECount] = &network.edges[edgeIndex];
      network.hiddenLayer[i].outECount++;
      network.outputLayer[i].inECount++;
      edgeIndex++;
    }
  }

  // readWeightsFromTextFile(network, networkConfig.inputFileName);
  return network;
};

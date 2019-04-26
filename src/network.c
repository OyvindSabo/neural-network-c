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
  network.inputLength = networkConfig.inputLength;
  network.hiddenLength = networkConfig.hiddenLength;
  network.outputLength = networkConfig.outputLength;

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
      network.inputLayer[i].outE = &network.edges[edgeIndex];
      network.hiddenLayer[j].inE = &network.edges[edgeIndex];
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
      network.hiddenLayer[i].outE = &network.edges[edgeIndex];
      network.outputLayer[j].inE = &network.edges[edgeIndex];
      edgeIndex++;
    }
  }

  // readWeightsFromTextFile(network, networkConfig.inputFileName);
  return network;
};

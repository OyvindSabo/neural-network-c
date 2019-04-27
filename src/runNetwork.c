#include "networkUtils.c"

struct Array
{
  double values[100];
  int length;
};

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
  int edgeCount;
  struct Node inputLayer[100];
  struct Node hiddenLayer[100];
  struct Node outputLayer[100];
  struct Edge edges[10100];
};

struct Array runNetwork(struct Network network, struct Array input) {
  feedForward(&network, &input, false);
  struct Array outputArray;
  for (int i = 0; i < network.outputLength; i++) {
    outputArray.values[i] = network.outputLayer[i].value;
  }
  return outputArray;
}

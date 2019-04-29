#ifndef TYPES_H
#define TYPES_H

// Configs
struct NetworkConfig
{
  int inputLength;
  int hiddenLength;
  int outputLength;
  char inputFileName[100];
};

struct TrainingDataConfig
{
  int numberOfFirstValuesToSkip;
  int amountOfDataToUseForTraining;
  int inputLength;
  int outputLength;
  int distanceFromInputToOutput;
};

struct TrainingConfig
{
  double learningRate;
  double maxError;
  char outputFileName[100];
};

// Network
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
  struct Edge edges[100000];
};

// General
struct Array
{
  double values[100];
  int length;
};

struct LargeArray
{
  double values[100000];
  int length;
};

// Training data
struct TrainingDatum
{
  struct Array input;
  struct Array output;
};

struct TrainingData
{
  struct TrainingDatum values[100000];
  int length;
};

#endif

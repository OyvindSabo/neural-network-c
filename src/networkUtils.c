#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "network.c"

struct Array
{
  double values[100];
  int length;
};

double sigmoid(double x)
{
  return 1 / (1 + exp(-x));
}

void feedForward(struct Network *network, struct Array inputValues, bool useNewWeights)
{

  if (inputValues.length != (*network).inputLength)
  {
    printf("ERROR: Length of input data is not equal to length of input layer\n");
  }

  // Set input layer values
  for (int i = 0; i < (*network).inputLength; i++)
  {
    (*network).inputLayer[i].value = inputValues.values[i];
  }

  // Calculate hidden layer values
  for (int i = 0; i < (*network).hiddenLength; i++)
  {
    (*network).hiddenLayer[i].value = 0;
    for (int j = 0; j < (*network).hiddenLayer[i].inECount; j++)
    {
      float currentWeight = (*(*network).hiddenLayer[i].inE[j]).currentWeight;
      float newWeight = (*(*network).hiddenLayer[i].inE[j]).newWeight;
      float value = (*(*(*network).hiddenLayer[i].inE[j]).outV).value;
      (*network).hiddenLayer[i].value += (useNewWeights ? newWeight : currentWeight) * value;
    }
    (*network).hiddenLayer[i].value = sigmoid((*network).hiddenLayer[i].value);
  }

  // Calculate output layer values
  for (int i = 0; i < (*network).outputLength; i++)
  {
    (*network).outputLayer[i].value = 0;
    for (int j = 0; j < (*network).outputLayer[i].inECount; j++)
    {
      float currentWeight = (*(*network).outputLayer[i].inE[j]).currentWeight;
      float newWeight = (*(*network).outputLayer[i].inE[j]).newWeight;
      float value = (*(*(*network).outputLayer[i].inE[j]).outV).value;
      (*network).outputLayer[i].value += (useNewWeights ? newWeight : currentWeight) * value;
    }
    (*network).outputLayer[i].value = sigmoid((*network).outputLayer[i].value);
  }
};

// Generate a random double between from 0 to 1
double random()
{
  return (rand() / RAND_MAX);
}

double randomMutation(double weight, double mutationFactor)
{
  return weight + (random() - random()) * mutationFactor;
}

struct TrainingDatum
{
  struct Array input;
  struct Array output;
};

struct TrainingData
{
  struct TrainingDatum values[10000];
  int length;
};

double getError(struct Network *network, struct TrainingData trainingData, bool useNewWeights)
{
  double errorForThisIteration = 0;
  for (int i = 0; i < trainingData.length; i++)
  {
    feedForward(&network, trainingData.values[i].input, useNewWeights);
    double errorForThisTrainingData = 0;
    for (int j = 0; j < (*network).outputLength; j++)
    {
      double actualOutput = (*network).outputLayer[j].value;
      double targetOutput = trainingData.values[i].output.values[j];
      double difference = actualOutput - targetOutput;
      errorForThisTrainingData += pow(difference, 2);
    }
    errorForThisIteration += errorForThisTrainingData;
  }
  return errorForThisIteration;
};

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "network.c"
#include "dataUtils.c"

struct Array
{
  double values[100];
  int length;
};

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

double sigmoid(double x)
{
  return 1 / (1 + exp(-x));
}

void feedForward(struct Network *network, struct Array *inputValues, bool useNewWeights)
{

  if ((*inputValues).length != (*network).inputLength)
  {
    printf("ERROR: Length of input data is not equal to length of input layer\n");
  }

  // Set input layer values
  for (int i = 0; i < (*network).inputLength; i++)
  {
    (*network).inputLayer[i].value = (*inputValues).values[i];
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

double getError(struct Network *network, struct TrainingData *trainingData, bool useNewWeights)
{
  double errorForThisIteration = 0;
  for (int i = 0; i < (*trainingData).length; i++)
  {
    feedForward(&network, &(*trainingData).values[i].input, useNewWeights);
    double errorForThisTrainingData = 0;
    for (int j = 0; j < (*network).outputLength; j++)
    {
      double actualOutput = (*network).outputLayer[j].value;
      double targetOutput = (*trainingData).values[i].output.values[j];
      double difference = actualOutput - targetOutput;
      errorForThisTrainingData += pow(difference, 2);
    }
    errorForThisIteration += errorForThisTrainingData;
  }
  return errorForThisIteration;
};

/* Not really a critical function
const visualizeError = error => {
  let errorVisualization = "\n";
  errorVisualization +=
    "10 000    1 000      100        10        1        0.1       0.01     0.001\n";
  errorVisualization +=
    "┌─┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─┐\n";
  errorVisualization += "│";
  const xIndex = 41 - 10 * Math.log10(error);
  for (let i = 0; i < xIndex; i++) {
    errorVisualization += " ";
  }
  for (let i = 0; i < 72 - xIndex; i++) {
    errorVisualization += "█";
  }
  errorVisualization += "│\n";
  errorVisualization +=
    "└─────────────────────────────────────────────────────────────────────────┘";
  console.log(errorVisualization);
};
*/

void readWeightsFromTextFile(struct Network *network, char fileName[100]) {
  struct Array *dataArray = readArrayFromTextFile(fileName);
  for (int i = 0; i < (*network).edgeCount; i++) {
    (*network).edges[i].currentWeight = (*dataArray).values[i];
  }
};

void writeWeightsToFile(struct Network *network, char fileName[100]) {
  struct Array dataArray;
  for (int i = 0; i < (*network).edgeCount; i++) {
    dataArray.values[i] = (*network).edges[i].currentWeight;
  }
  dataArray.length = (*network).edgeCount;
  writeArrayToTextFile(&dataArray, fileName);
};

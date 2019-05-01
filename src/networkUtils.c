#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "dataUtils.h"

double sigmoid(double x)
{
  return 1 / (1 + exp(-x));
}

void feedForward(struct Network *network, struct Array *inputValues, _Bool useNewWeights)
{
  //printf("feedForward\n");
  if ((*inputValues).length != (*network).inputLength)
  {
    printf("ERROR: Length of input data is not equal to length of input layer\n");
    printf("inputValues.length: %d\n", (*inputValues).length);
    printf("inputLayer.length: %d\n", (*network).inputLength);
  }

  // Set input layer values
  //printf("feedForward: set input layer values\n");
  for (int i = 0; i < (*network).inputLength; i++)
  {
    (*network).inputLayer[i].value = (*inputValues).values[i];
    //printf("feedForward: value in input layer: %f\n", (*network).inputLayer[i].value);
    //printf("Set input layer value to %f\n", (*network).inputLayer[i].value);
  }

  // Calculate hidden layer values
  //printf("feedForward: Calculate hidden layer values\n");
  for (int i = 0; i < (*network).hiddenLength; i++)
  {
    //printf("feedForward: (*network).hiddenLength: %d\n", (*network).hiddenLength);
    //printf("feedForward: set (*network).hiddenLayer[i].value = 0\n");
    (*network).hiddenLayer[i].value = 0;
    for (int j = 0; j < (*network).hiddenLayer[i].inECount; j++)
    {
      //printf("feedForward: (*network).hiddenLayer[i].inECount: %d\n", (*network).hiddenLayer[i].inECount);
      float currentWeight = (*(*network).hiddenLayer[i].inE[j]).currentWeight;
      //printf("feedForward: calculated currentWeight to %f\n", currentWeight);
      float newWeight = (*(*network).hiddenLayer[i].inE[j]).newWeight;
      //printf("feedForward: newWeight: %f\n", newWeight);
      float value = (*(*(*network).hiddenLayer[i].inE[j]).outV).value;
      //printf("feedForward: value in hidden layer: %f\n", value);
      (*network).hiddenLayer[i].value += (useNewWeights ? newWeight : currentWeight) * value;
      //printf("feedForward: Set (*network).hiddenLayer[i].value to %f\n", (*network).hiddenLayer[i].value);
      
    }
    (*network).hiddenLayer[i].value = sigmoid((*network).hiddenLayer[i].value);
  }

  // Calculate output layer values
  //printf("feedForward: Calculate output layer values\n");
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
    //(*network).outputLayer[i].value = sigmoid((*network).outputLayer[i].value);
  }
};

// Generate a random double between from 0 to 1
double randomBetweenZeroAndOne()
{
  return ((double) rand() / RAND_MAX);
}

double randomMutation(double weight, double mutationFactor)
{
  return weight + (randomBetweenZeroAndOne() - randomBetweenZeroAndOne()) * mutationFactor;
}

double getError(struct Network *network, struct TrainingData *trainingData, _Bool useNewWeights)
{
  double errorForThisIteration = 0;
  for (int i = 0; i < (*trainingData).length; i++)
  {
    feedForward(network, &(*trainingData).values[i].input, useNewWeights);
    double errorForThisTrainingData = 0;
    for (int j = 0; j < (*network).outputLength; j++)
    {
      double actualOutput = (*network).outputLayer[j].value;
      double targetOutput = (*trainingData).values[i].output.values[j];
      double difference = actualOutput - targetOutput;
      errorForThisTrainingData += pow(difference, 4);
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

void readWeightsFromTextFile(struct Network *network, char fileName[100])
{
  struct LargeArray *dataArray = readArrayFromTextFile(fileName);
  for (int i = 0; i < (*network).edgeCount; i++)
  {
    (*network).edges[i].currentWeight = (*dataArray).values[i];
  }
};

void writeWeightsToFile(struct Network *network, char fileName[100])
{
  struct LargeArray dataArray;
  for (int i = 0; i < (*network).edgeCount; i++)
  {
    dataArray.values[i] = (*network).edges[i].currentWeight;
  }
  dataArray.length = (*network).edgeCount;
  writeArrayToTextFile(&dataArray, fileName);
};

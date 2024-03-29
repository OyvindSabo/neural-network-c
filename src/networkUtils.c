#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "dataUtils.h"

// Activation function which returns a number between 0 and 1 for any input number
double sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}

void feedForward(
    struct Network *network,
    struct Array *inputValues,
    _Bool useNewWeights)
{
    if (inputValues->length != network->inputLength)
    {
        printf("ERROR: Length of input data must match length of input layer\n");
        printf("inputValues.length: %d\n", inputValues->length);
        printf("inputLayer.length: %d\n", network->inputLength);
    }

    // Assign training data input values to input layer of network
    for (int i = 0; i < network->inputLength; i++)
    {
        network->inputLayer[i].value = inputValues->values[i];
    }

    // Calculate hidden layer values
    for (int i = 0; i < network->hiddenLength; i++)
    {
        // For a given node in the hidden layer, sum contribution from all
        // incoming edges from the input layer
        network->hiddenLayer[i].value = 0;
        for (int j = 0; j < network->hiddenLayer[i].inECount; j++)
        {
            double currentWeight = network->hiddenLayer[i].inE[j]->currentWeight;
            double newWeight = network->hiddenLayer[i].inE[j]->newWeight;
            double value = network->hiddenLayer[i].inE[j]->outV->value;
            network->hiddenLayer[i].value += (useNewWeights ? newWeight : currentWeight) * value;
        }
        network->hiddenLayer[i].value = sigmoid(network->hiddenLayer[i].value);
    }

    // Calculate output layer values
    // Since this network will be used for regression rather than classification
    // the output layer does not utilize the sigmoid function
    for (int i = 0; i < network->outputLength; i++)
    {
        network->outputLayer[i].value = 0;
        for (int j = 0; j < network->outputLayer[i].inECount; j++)
        {
            double currentWeight = network->outputLayer[i].inE[j]->currentWeight;
            double newWeight = network->outputLayer[i].inE[j]->newWeight;
            double value = network->outputLayer[i].inE[j]->outV->value;
            network->outputLayer[i].value += (useNewWeights ? newWeight : currentWeight) * value;
        }
    }
};

// Generate a random double between from 0 to 1
double randomBetweenZeroAndOne()
{
    return ((double)rand() / RAND_MAX);
}

// Return a weight which diverges randomly from the input weight within the
// range [-mutationFactor, mutationFactor]
double randomMutation(double weight, double mutationFactor)
{
    return weight + (randomBetweenZeroAndOne() - randomBetweenZeroAndOne()) * mutationFactor;
}

// Return the accumulated difference between the predicted value and actual
// value for all input/output tuples in training data
double getError(struct Network *network,
                struct TrainingData *trainingData,
                _Bool useNewWeights)
{
    double errorForThisIteration = 0;
    for (int i = 0; i < trainingData->length; i++)
    {
        feedForward(network, &trainingData->values[i].input, useNewWeights);
        double errorForThisTrainingData = 0;
        for (int j = 0; j < network->outputLength; j++)
        {
            double actualOutput = network->outputLayer[j].value;
            double targetOutput = trainingData->values[i].output.values[j];
            double difference = actualOutput - targetOutput;
            errorForThisTrainingData += pow(difference, 4);
        }
        errorForThisIteration += errorForThisTrainingData;
    }
    return errorForThisIteration;
};

// Set the weights of a network from a text file of newline separated numbers
void assignWeightsFromTextFile(struct Network *network, char fileName[100])
{
    struct LargeArray *dataArray = readArrayFromTextFile(fileName);
    for (int i = 0; i < network->edgeCount; i++)
    {
        network->edges[i].currentWeight = dataArray->values[i];
    }
};

// Store the weights of a network in a text file
void writeWeightsToFile(struct Network *network, char fileName[100])
{
    struct LargeArray dataArray;
    for (int i = 0; i < network->edgeCount; i++)
    {
        dataArray.values[i] = network->edges[i].currentWeight;
    }
    dataArray.length = network->edgeCount;
    writeArrayToTextFile(&dataArray, fileName);
};

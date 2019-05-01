#include <stdio.h>
#include <string.h>
#include "types.h"
#include "networkUtils.h"

void trainNetwork(struct Network *network, struct TrainingData *trainingData, struct TrainingConfig *trainingConfig)
{
    double maxError = trainingConfig->maxError;
    double learningRate = trainingConfig->learningRate;
    char outputFileName[100];
    strcpy(outputFileName, trainingConfig->outputFileName);

    // Find the error given by the current weights
    double currentError = getError(network, trainingData, false);
    double newError;

    // While the error is still above maxError, mutate all weights and update current weights if the new weights result in a lower error
    do
    {
        // Mutate all edges slightly
        double mutationFactor = learningRate * currentError;
        for (int i = 0; i < network->edgeCount; i++)
        {
            network->edges[i].newWeight = randomMutation(network->edges[i].currentWeight, mutationFactor);
        }
        newError = getError(network, trainingData, true);
        if (newError < currentError)
        {
            // visualizeError(newError); // Not implemented yet
            printf("\nnewError: %f\n", newError);
            for (int i = 0; i < network->edgeCount; i++)
            {
                network->edges[i].currentWeight = network->edges[i].newWeight;
                currentError = newError;
            }
            writeWeightsToFile(network, outputFileName);
        }
    } while (currentError > maxError);
}

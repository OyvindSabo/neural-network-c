#include <stdio.h>
#include <string.h>
#include "types.h"
#include "networkUtils.h"
#include "consoleUtils.h"

void trainNetwork(struct Network *network,
                  struct TrainingData *trainingData,
                  struct TrainingConfig *trainingConfig)
{
    double maxError = trainingConfig->maxError;
    double learningRate = trainingConfig->learningRate;
    char outputFileName[100];
    strcpy(outputFileName, trainingConfig->outputFileName);

    // Find the error given by the current weights
    double currentError = getError(network, trainingData, false);
    double newError;

    // While the prediction error is still above a given maximum accepted error
    // mutate all weights and update current weights if the new weights result
    // in a lower error
    do
    {
        // Mutate all weights proportionally to error
        double mutationFactor = learningRate * currentError;
        for (int i = 0; i < network->edgeCount; i++)
        {
            network->edges[i].newWeight = randomMutation(network->edges[i].currentWeight, mutationFactor);
        }
        newError = getError(network, trainingData, true);
        if (newError < currentError)
        {
            // Update edges with improved weights
            printError(newError);
            for (int i = 0; i < network->edgeCount; i++)
            {
                network->edges[i].currentWeight = network->edges[i].newWeight;
                currentError = newError;
            }
            writeWeightsToFile(network, outputFileName);
        }
        // The training algorithm runs either until it is stopped manually, or until
        // the prediction error is less than a given maximum accepted error
    } while (currentError > maxError);
}

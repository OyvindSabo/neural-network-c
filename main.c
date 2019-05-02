#include <stdio.h>
#include <string.h>
#include "src/types.h"
#include "src/dataUtils.h"
#include "src/network.h"
#include "src/consoleUtils.h"
#include "src/trainNetwork.h"

int main()
{
    printLogo();
    
    printLoading("Initializing network");
    struct NetworkConfig networkConfig;
    networkConfig.inputLength = 100;
    networkConfig.hiddenLength = 50;
    networkConfig.outputLength = 1;
    strcpy(networkConfig.inputFileName, "./data/weights.txt");
    struct Network *network = createNetwork(&networkConfig);

    printLoading("Generating training data");
    struct TrainingDataConfig trainingDataConfig;
    trainingDataConfig.numberOfFirstValuesToSkip = 100;
    trainingDataConfig.amountOfDataToUseForTraining = 10000;
    trainingDataConfig.inputLength = 100;
    trainingDataConfig.outputLength = 1;
    trainingDataConfig.distanceFromInputToOutput = 10;
    struct TrainingData *trainingData = generateTrainingData("./data/waveHeights.txt", &trainingDataConfig);

    printLoading("Initiating training");
    struct TrainingConfig trainingConfig;
    trainingConfig.learningRate = 0.00000001;
    trainingConfig.maxError = 400;
    strcpy(trainingConfig.outputFileName, "./data/weights.txt");
    trainNetwork(network, trainingData, &trainingConfig);

    return 0;
};

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/types.h"
#include "src/network.h"
#include "src/dataUtils.h"
#include "src/runNetwork.h"
#include "src/networkUtils.h"
#include "src/trainNetwork.h"

int main()
{
  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("┃ Testing dataUtils.c                                                         ┃\n");
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
  
  // Testing slice
  struct LargeArray arrayToSlice;
  arrayToSlice.length = 0;
  for (int i = 0; i < 10; i++) {
    arrayToSlice.values[i] = i;
    arrayToSlice.length++;
  }
  struct Array slicedArray;
  slice(&arrayToSlice, &slicedArray, 4, 7);
  char lengthOfSlicedArrayIsCorrect[80];
  if (slicedArray.length == 3) {
    strcpy(lengthOfSlicedArrayIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(lengthOfSlicedArrayIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }
  char startIndexOfSlicedArrayIsCorrect[80];
  if (slicedArray.values[0] == 4) {
    strcpy(startIndexOfSlicedArrayIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(startIndexOfSlicedArrayIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  // Testing readArrayFromTextFile
  struct LargeArray *arrayFromTextFile = readArrayFromTextFile("./data/test/readArrayFromTextFileTest.txt");
  
  char lengthOfArrayFromTextFileIsCorrect[80];
  if (arrayFromTextFile->length == 10) {
    strcpy(lengthOfArrayFromTextFileIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(lengthOfArrayFromTextFileIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  char arrayDataCorrespondsToFileData[80];
  if (arrayFromTextFile->values[0] == 29.659899 && arrayFromTextFile->values[1] == 178.775128 && arrayFromTextFile->values[2] == 81.224999 && arrayFromTextFile->values[3] == 36.479861 && arrayFromTextFile->values[4] == 12.673026 && arrayFromTextFile->values[5] == 102.360445 && arrayFromTextFile->values[6] == -114.267789&& arrayFromTextFile->values[7] == 24.814897 && arrayFromTextFile->values[8] == 119.903800 && arrayFromTextFile->values[9] == -40.714473) {
    strcpy(arrayDataCorrespondsToFileData, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(arrayDataCorrespondsToFileData, "\33[1;31m✗ Test failed\33[m");
  }

  // Testing writeArrayToTextFile
  struct LargeArray arrayToWriteToTextFile;
  arrayToWriteToTextFile.values[0] = rand();
  arrayToWriteToTextFile.values[1] = rand();
  arrayToWriteToTextFile.values[2] = rand();
  arrayToWriteToTextFile.values[3] = rand();
  arrayToWriteToTextFile.values[4] = rand();
  arrayToWriteToTextFile.length = 5;
  writeArrayToTextFile(&arrayToWriteToTextFile, "./data/writeArrayToTextFileTest.txt");
  struct LargeArray *arrayFromTextFileFromArray = readArrayFromTextFile("./data/test/writeArrayToTextFileTest.txt");
  
  char lengthOfArrayFromTextFileFromArrayIsCorrect[80];
  if (arrayFromTextFileFromArray->length == arrayToWriteToTextFile.length) {
    strcpy(lengthOfArrayFromTextFileFromArrayIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(lengthOfArrayFromTextFileFromArrayIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  char fileDataCorrespondsToArrayData[80];
  if (arrayFromTextFileFromArray->values[0] == arrayToWriteToTextFile.values[0] && arrayFromTextFileFromArray->values[1] == arrayToWriteToTextFile.values[1] && arrayFromTextFileFromArray->values[2] == arrayToWriteToTextFile.values[2] && arrayFromTextFileFromArray->values[3] == arrayToWriteToTextFile.values[3] && arrayFromTextFileFromArray->values[4] == arrayToWriteToTextFile.values[4]) {
    strcpy(fileDataCorrespondsToArrayData, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(fileDataCorrespondsToArrayData, "\33[1;31m✗ Test failed\33[m");
  }

  // testing generateTrainingData
  struct TrainingDataConfig trainingDataConfig;
  trainingDataConfig.numberOfFirstValuesToSkip = 10;
  trainingDataConfig.amountOfDataToUseForTraining = 40;
  trainingDataConfig.inputLength = 5;
  trainingDataConfig.outputLength = 1;
  trainingDataConfig.distanceFromInputToOutput = 10;
  struct TrainingData *trainingData = generateTrainingData("./data/test/generateTrainingDataTest.txt", &trainingDataConfig);

  char trainingDataInputLengthIsCorrect[80];
  if (trainingData->values[0].input.length == 5) {
    strcpy(trainingDataInputLengthIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(trainingDataInputLengthIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  char trainingDataSizeIsCorrect[80];
  if (trainingData->length == 16) {
    strcpy(trainingDataSizeIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(trainingDataSizeIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  char firstTrainingDataStartIndexIsCorrect[80];
  if (trainingData->values[0].input.values[0] == 10.000000) {
    strcpy(firstTrainingDataStartIndexIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(firstTrainingDataStartIndexIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  char lastTrainingDataStartIndexIsCorrect[80];
  if (trainingData->values[14].input.values[0] == 24.000000) {
    strcpy(lastTrainingDataStartIndexIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(lastTrainingDataStartIndexIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  char firstTrainingDataEndIndexIsCorrect[80];
  if (trainingData->values[15].input.values[4] == 29.000000) {
    strcpy(firstTrainingDataEndIndexIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(firstTrainingDataEndIndexIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }
  
  char lastTrainingDataEndIndexIsCorrect[80];
  if (trainingData->values[15].input.values[4] == 29.000000) {
    strcpy(lastTrainingDataEndIndexIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(lastTrainingDataEndIndexIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  
  printf("\n\33[1;36m  Testing slice:\33[m\n");
  printf("  Checking that length of output array is correct:              %s\n", lengthOfSlicedArrayIsCorrect);
  printf("  Checking that that start index is correct:                    %s\n", startIndexOfSlicedArrayIsCorrect);

  printf("\n\33[1;36m  Testing readArrayFromTextFile:\33[m\n");
  printf("  Checking that length of output array is correct:              %s\n", lengthOfArrayFromTextFileIsCorrect);
  printf("  Checking that data in array corresponds to data in text file: %s\n", arrayDataCorrespondsToFileData);

  printf("\n\33[1;36m  Testing writeArrayToTextFile:\33[m\n");
  printf("  Checking that length of textFile is correct:                  %s\n", lengthOfArrayFromTextFileFromArrayIsCorrect);
  printf("  Checking that data in text file corresponds to data in array: %s\n", fileDataCorrespondsToArrayData);

  printf("\n\33[1;36m  Testing generateTrainingData:\33[m\n");
  printf("  Checking that that input length is correct:                   %s\n", trainingDataInputLengthIsCorrect);
  printf("  Checking that that data size is correct:                      %s\n", trainingDataSizeIsCorrect);
  printf("  Checking that that first start index is correct:              %s\n", firstTrainingDataStartIndexIsCorrect);
  printf("  Checking that that last start index is correct:               %s\n", lastTrainingDataStartIndexIsCorrect);
  printf("  Checking that that first end index is correct:                %s\n", firstTrainingDataEndIndexIsCorrect);
  printf("  Checking that that last end index is correct:                 %s\n\n", lastTrainingDataEndIndexIsCorrect);

  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("┃ Testing networkUtils.c                                                      ┃\n");
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
  
  // Testing sigmoid
  char sigmoidOfMinusFiftyIsCorrect[80];
  if (sigmoid(-50) < 0.000000000000000000001) {
    strcpy(sigmoidOfMinusFiftyIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(sigmoidOfMinusFiftyIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  char sigmoidOfZeroIsCorrect[80];
  if (sigmoid(0) == 0.5) {
    strcpy(sigmoidOfZeroIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(sigmoidOfZeroIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  char sigmoidOfFiftyIsCorrect[80];
  if (sigmoid(50) == 1) {
    strcpy(sigmoidOfFiftyIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(sigmoidOfFiftyIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }

  printf("\n\33[1;36m  Testing sigmoid:\33[m\n");
  printf("  Checking that sigmoid of -50 is correct:                      %s\n", sigmoidOfMinusFiftyIsCorrect);
  printf("  Checking that sigmoid of zero is correct:                     %s\n", sigmoidOfZeroIsCorrect);
  printf("  Checking that sigmoid of 50 is correct:                       %s\n", sigmoidOfFiftyIsCorrect);

  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
  printf("┃ Testing runNetwork.c                                                        ┃\n");
  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

  struct NetworkConfig networkConfig;
  networkConfig.inputLength = 4;
  networkConfig.hiddenLength = 2;
  networkConfig.outputLength = 1;
  strcpy(networkConfig.inputFileName, "./data/test/weightsForRunNetworkTest.txt");
  struct Network *feedForwardTestNetwork = createNetwork(&networkConfig);
  
  struct Array runNetworkInput;
  runNetworkInput.values[0] = 0.4;
  runNetworkInput.values[1] = 0.3;
  runNetworkInput.values[2] = 0.2;
  runNetworkInput.values[3] = 0.1;
  runNetworkInput.length = 4;

  struct Array *runNetworkOutputArray;
  runNetworkOutputArray = runNetwork(feedForwardTestNetwork, &runNetworkInput);
  
  char runNetworkOutputValueIsCorrect[80];
  if (feedForwardTestNetwork->outputLayer[0].value > 15.61 && feedForwardTestNetwork->outputLayer[0].value < 15.62) {
    strcpy(runNetworkOutputValueIsCorrect, "\33[1;32m✓ Test passed\33[m");
  } else {
    strcpy(runNetworkOutputValueIsCorrect, "\33[1;31m✗ Test failed\33[m");
  }
  
  printf("\n\33[1;36m  Testing runNetwork:\33[m\n");
  printf("  Checking that input values result in correct output values    %s\n", runNetworkOutputValueIsCorrect);


  // Testing 
  /*printf("Initializing network\n");
  struct NetworkConfig networkConfig;
  networkConfig.inputLength = 100;
  networkConfig.hiddenLength = 50;
  networkConfig.outputLength = 1;
  strcpy(networkConfig.inputFileName, "./data/weights.txt");
  struct Network *network = createNetwork(&networkConfig);

  printf("Generating training data\n");
  struct TrainingDataConfig trainingDataConfig;
  trainingDataConfig.numberOfFirstValuesToSkip = 100;
  trainingDataConfig.amountOfDataToUseForTraining = 10000;
  trainingDataConfig.inputLength = 100;
  trainingDataConfig.outputLength = 1;
  trainingDataConfig.distanceFromInputToOutput = 10;
  struct TrainingData *trainingData = generateTrainingData("./data/waveHeights.txt", &trainingDataConfig);

  printf("Training network\n");
  struct TrainingConfig trainingConfig;
  trainingConfig.learningRate = 0.000001;
  trainingConfig.maxError = 400;
  strcpy(trainingConfig.outputFileName, "./data/weights.txt");
  trainNetwork(network, trainingData, &trainingConfig);*/

  return 0;
};
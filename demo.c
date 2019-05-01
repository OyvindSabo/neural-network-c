#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/types.h"
#include "src/dataUtils.h"
#include "src/network.h"
#include "src/runNetwork.h"

int main()
{
  printf("Initializing network\n");
  struct NetworkConfig networkConfig;
  networkConfig.inputLength = 100;
  networkConfig.hiddenLength = 50;
  networkConfig.outputLength = 1;
  strcpy(networkConfig.inputFileName, "./data/weights.txt");
  struct Network *network = createNetwork(&networkConfig);

  struct LargeArray *waveHeightArray = readArrayFromTextFile("./data/waveHeights.txt");
  printf("┌───────────────────┬───────────────────┬───────────────────┬───────────────────┐\n");
  printf("│                   │ Predicted value   │ Actual value      │ Error             │\n");
  printf("├───────────────────┼───────────────────┼───────────────────┼───────────────────┤\n");

  int futureValueIndex;
  int startIndex;
  int endIndex;
  struct Array inputData;
  struct Array *predictedValue;
  double actualValue;
  double error;
  double totalError = 0;

  // Generate demo data for t = 999
  futureValueIndex = 999;
  startIndex = futureValueIndex - 110;
  endIndex = futureValueIndex - 10;
  slice(waveHeightArray, &inputData, startIndex, endIndex);
  predictedValue = runNetwork(network, &inputData);
  actualValue = waveHeightArray->values[futureValueIndex];
  error = fabs(predictedValue->values[0] - actualValue);
  totalError += error;
  printf("│ At t = %d        │ %f          │ %f          │ %f          │\n", futureValueIndex, predictedValue->values[0], actualValue, error);

  // Generate demo data for t = 1000
  futureValueIndex = 1000;
  startIndex = futureValueIndex - 110;
  endIndex = futureValueIndex - 10;
  slice(waveHeightArray, &inputData, startIndex, endIndex);
  predictedValue = runNetwork(network, &inputData);
  actualValue = waveHeightArray->values[futureValueIndex];
  error = fabs(predictedValue->values[0] - actualValue);
  totalError += error;
  printf("│ At t = %d       │ %f          │ %f          │ %f          │\n", futureValueIndex, predictedValue->values[0], actualValue, error);

  return 0;
};

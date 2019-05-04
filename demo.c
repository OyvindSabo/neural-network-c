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
    // Initialize network
    struct NetworkConfig networkConfig;
    networkConfig.inputLength = 100;
    networkConfig.hiddenLength = 50;
    networkConfig.outputLength = 1;
    strcpy(networkConfig.inputFileName, "./data/weights.txt");
    struct Network *network = createNetwork(&networkConfig);

    // Load dataset
    struct LargeArray *waveHeightArray = readArrayFromTextFile("./data/waveHeights.txt");
    printf("\n\33[1;33mRESULTS FROM DATA USED FOR TRAINING:\33[m\n");
    printf("┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃ Time              ┃ Predicted value   ┃ Actual value      ┃ Error             ┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━┫\n");

    int futureValueIndex;
    int startIndex;
    int endIndex;
    struct Array inputData;
    struct Array *predictedValue;
    double actualValue;
    double error;
    double totalError = 0;

    // Generate demo data for t = 1000
    futureValueIndex = 1000;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1001
    futureValueIndex = 1001;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1002
    futureValueIndex = 1002;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1003
    futureValueIndex = 1003;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1004
    futureValueIndex = 1004;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1005
    futureValueIndex = 1005;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1006
    futureValueIndex = 1006;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1007
    futureValueIndex = 1007;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1008
    futureValueIndex = 1008;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1009
    futureValueIndex = 1009;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1010
    futureValueIndex = 1010;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1011
    futureValueIndex = 1011;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1012
    futureValueIndex = 1012;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1013
    futureValueIndex = 1013;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1014
    futureValueIndex = 1014;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1015
    futureValueIndex = 1015;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1016
    futureValueIndex = 1016;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1017
    futureValueIndex = 1017;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1018
    futureValueIndex = 1018;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1019
    futureValueIndex = 1019;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1020
    futureValueIndex = 1020;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1021
    futureValueIndex = 1021;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1022
    futureValueIndex = 1022;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1023
    futureValueIndex = 1023;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1024
    futureValueIndex = 1024;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1025
    futureValueIndex = 1025;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1026
    futureValueIndex = 1026;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1027
    futureValueIndex = 1027;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1028
    futureValueIndex = 1028;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1029
    futureValueIndex = 1029;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1030
    futureValueIndex = 1030;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1031
    futureValueIndex = 1031;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1032
    futureValueIndex = 1032;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1033
    futureValueIndex = 1033;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1034
    futureValueIndex = 1034;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1035
    futureValueIndex = 1035;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1036
    futureValueIndex = 1036;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1037
    futureValueIndex = 1037;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1038
    futureValueIndex = 1038;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1039
    futureValueIndex = 1039;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1040
    futureValueIndex = 1040;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1041
    futureValueIndex = 1041;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1042
    futureValueIndex = 1042;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1043
    futureValueIndex = 1043;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1044
    futureValueIndex = 1044;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1045
    futureValueIndex = 1045;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1046
    futureValueIndex = 1046;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1047
    futureValueIndex = 1047;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1048
    futureValueIndex = 1048;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1049
    futureValueIndex = 1049;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 1050
    futureValueIndex = 1050;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d       ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    printf("┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n");

    printf("\n\33[1;34mRESULTS FROM DATA NOT USED FOR TRAINING:\33[m\n");
    printf("┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃ Time              ┃ Predicted value   ┃ Actual value      ┃ Error             ┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━┫\n");

    // Generate demo data for t = 10000
    futureValueIndex = 10000;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10001
    futureValueIndex = 10001;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10002
    futureValueIndex = 10002;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10003
    futureValueIndex = 10003;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10004
    futureValueIndex = 10004;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10005
    futureValueIndex = 10005;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10006
    futureValueIndex = 10006;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10007
    futureValueIndex = 10007;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10008
    futureValueIndex = 10008;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10009
    futureValueIndex = 10009;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10010
    futureValueIndex = 10010;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10011
    futureValueIndex = 10011;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10012
    futureValueIndex = 10012;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10013
    futureValueIndex = 10013;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10014
    futureValueIndex = 10014;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10015
    futureValueIndex = 10015;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10016
    futureValueIndex = 10016;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10017
    futureValueIndex = 10017;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10018
    futureValueIndex = 10018;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10019
    futureValueIndex = 10019;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10020
    futureValueIndex = 10020;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10021
    futureValueIndex = 10021;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10022
    futureValueIndex = 10022;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10023
    futureValueIndex = 10023;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10024
    futureValueIndex = 10024;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10025
    futureValueIndex = 10025;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10026
    futureValueIndex = 10026;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10027
    futureValueIndex = 10027;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10028
    futureValueIndex = 10028;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10029
    futureValueIndex = 10029;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10030
    futureValueIndex = 10030;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10031
    futureValueIndex = 10031;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10032
    futureValueIndex = 10032;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10033
    futureValueIndex = 10033;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10034
    futureValueIndex = 10034;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10035
    futureValueIndex = 10035;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10036
    futureValueIndex = 10036;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10037
    futureValueIndex = 10037;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10038
    futureValueIndex = 10038;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10039
    futureValueIndex = 10039;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10040
    futureValueIndex = 10040;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10041
    futureValueIndex = 10041;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10042
    futureValueIndex = 10042;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10043
    futureValueIndex = 10043;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10044
    futureValueIndex = 10044;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10045
    futureValueIndex = 10045;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10046
    futureValueIndex = 10046;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10047
    futureValueIndex = 10047;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10048
    futureValueIndex = 10048;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10049
    futureValueIndex = 10049;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 10050
    futureValueIndex = 10050;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    printf("┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━┫\n");

    // Generate demo data for t = 15000
    futureValueIndex = 15000;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15001
    futureValueIndex = 15001;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15002
    futureValueIndex = 15002;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15003
    futureValueIndex = 15003;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15004
    futureValueIndex = 15004;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15005
    futureValueIndex = 15005;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15006
    futureValueIndex = 15006;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15007
    futureValueIndex = 15007;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15008
    futureValueIndex = 15008;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15009
    futureValueIndex = 15009;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15010
    futureValueIndex = 15010;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15011
    futureValueIndex = 15011;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15012
    futureValueIndex = 15012;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15013
    futureValueIndex = 15013;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15014
    futureValueIndex = 15014;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15015
    futureValueIndex = 15015;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15016
    futureValueIndex = 15016;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15017
    futureValueIndex = 15017;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15018
    futureValueIndex = 15018;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15019
    futureValueIndex = 15019;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15020
    futureValueIndex = 15020;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15021
    futureValueIndex = 15021;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15022
    futureValueIndex = 15022;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15023
    futureValueIndex = 15023;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15024
    futureValueIndex = 15024;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15025
    futureValueIndex = 15025;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15026
    futureValueIndex = 15026;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15027
    futureValueIndex = 15027;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15028
    futureValueIndex = 15028;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15029
    futureValueIndex = 15029;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15030
    futureValueIndex = 15030;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15031
    futureValueIndex = 15031;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15032
    futureValueIndex = 15032;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15033
    futureValueIndex = 15033;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15034
    futureValueIndex = 15034;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15035
    futureValueIndex = 15035;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15036
    futureValueIndex = 15036;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15037
    futureValueIndex = 15037;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15038
    futureValueIndex = 15038;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15039
    futureValueIndex = 15039;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15040
    futureValueIndex = 15040;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15041
    futureValueIndex = 15041;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15042
    futureValueIndex = 15042;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15043
    futureValueIndex = 15043;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15044
    futureValueIndex = 15044;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15045
    futureValueIndex = 15045;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15046
    futureValueIndex = 15046;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15047
    futureValueIndex = 15047;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15048
    futureValueIndex = 15048;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15049
    futureValueIndex = 15049;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 15050
    futureValueIndex = 15050;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);
    
    printf("┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━┫\n");

    // Generate demo data for t = 20000
    futureValueIndex = 20000;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20001
    futureValueIndex = 20001;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20002
    futureValueIndex = 20002;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20003
    futureValueIndex = 20003;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20004
    futureValueIndex = 20004;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20005
    futureValueIndex = 20005;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20006
    futureValueIndex = 20006;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20007
    futureValueIndex = 20007;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20008
    futureValueIndex = 20008;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20009
    futureValueIndex = 20009;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20010
    futureValueIndex = 20010;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20011
    futureValueIndex = 20011;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20012
    futureValueIndex = 20012;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20013
    futureValueIndex = 20013;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20014
    futureValueIndex = 20014;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20015
    futureValueIndex = 20015;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20016
    futureValueIndex = 20016;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20017
    futureValueIndex = 20017;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20018
    futureValueIndex = 20018;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20019
    futureValueIndex = 20019;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20020
    futureValueIndex = 20020;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20021
    futureValueIndex = 20021;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20022
    futureValueIndex = 20022;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20023
    futureValueIndex = 20023;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20024
    futureValueIndex = 20024;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20025
    futureValueIndex = 20025;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20026
    futureValueIndex = 20026;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20027
    futureValueIndex = 20027;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20028
    futureValueIndex = 20028;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20029
    futureValueIndex = 20029;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20030
    futureValueIndex = 20030;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f         ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20031
    futureValueIndex = 20031;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20032
    futureValueIndex = 20032;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f         ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20033
    futureValueIndex = 20033;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20034
    futureValueIndex = 20034;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20035
    futureValueIndex = 20035;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20036
    futureValueIndex = 20036;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20037
    futureValueIndex = 20037;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20038
    futureValueIndex = 20038;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20039
    futureValueIndex = 20039;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20040
    futureValueIndex = 20040;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20041
    futureValueIndex = 20041;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20042
    futureValueIndex = 20042;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20043
    futureValueIndex = 20043;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20044
    futureValueIndex = 20044;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20045
    futureValueIndex = 20045;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20046
    futureValueIndex = 20046;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20047
    futureValueIndex = 20047;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20048
    futureValueIndex = 20048;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20049
    futureValueIndex = 20049;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);

    // Generate demo data for t = 20050
    futureValueIndex = 20050;
    startIndex = futureValueIndex - 110;
    endIndex = futureValueIndex - 10;
    slice(waveHeightArray, &inputData, startIndex, endIndex);
    predictedValue = runNetwork(network, &inputData);
    actualValue = waveHeightArray->values[futureValueIndex];
    error = fabs(predictedValue->values[0] - actualValue);
    totalError += error;
    printf("┃ At t = %d      ┃ %f          ┃ %f          ┃ %f          ┃\n", futureValueIndex, predictedValue->values[0], actualValue, error);
    
    printf("┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\nTotal error: \33[1;36m%f\33[m\n", totalError);

    return 0;
};

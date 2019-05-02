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
    
    printf("┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\nTotal error: \33[1;31m%f\33[m\n", totalError);

    return 0;
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

void slice(struct LargeArray *inputArray, struct Array *outputArray, int startIndex, int endIndex)
{
    outputArray->length = 0;
    for (int i = 0; i < endIndex - startIndex; i++)
    {
        outputArray->values[i] = inputArray->values[i + startIndex];
        outputArray->length++;
    }
}

struct LargeArray *readArrayFromTextFile(char fileName[100])
{
    struct LargeArray *dataArray;
    dataArray = malloc(sizeof(struct LargeArray));
    FILE *file = fopen(fileName, "r");
    char currentLine[100]; // A double has 15 decimal digits of precision

    dataArray->length = 0;
    while (fgets(currentLine, sizeof(currentLine), file) != NULL)
    {
        dataArray->values[dataArray->length] = atof(currentLine);
        dataArray->length += 1;
    }
    fclose(file);
    return dataArray;
};

void writeArrayToTextFile(struct LargeArray *dataArray, char fileName[100])
{
    FILE *file = fopen(fileName, "w");
    for (int i = 0; i < dataArray->length; i++)
    {
        fprintf(file, "%f\n", dataArray->values[i]);
    }
    fclose(file);
};

struct TrainingData *generateTrainingData(char fileName[100], struct TrainingDataConfig *trainingDataConfig)
{
    // Extract values from trainingDataConfig
    int numberOfFirstValuesToSkip = trainingDataConfig->numberOfFirstValuesToSkip;
    int amountOfDataToUseForTraining = trainingDataConfig->amountOfDataToUseForTraining;
    int inputLength = trainingDataConfig->inputLength;
    int outputLength = trainingDataConfig->outputLength;
    int distanceFromInputToOutput = trainingDataConfig->distanceFromInputToOutput;

    struct LargeArray *dataArray = readArrayFromTextFile(fileName);
    struct TrainingData *trainingData;

    trainingData = malloc(sizeof(struct TrainingData));

    trainingData->length =
        amountOfDataToUseForTraining + 2 -
        numberOfFirstValuesToSkip -
        inputLength -
        distanceFromInputToOutput -
        outputLength;
    for (int i = 0; i < trainingData->length; i++)
    {
        int inputStartIndex = numberOfFirstValuesToSkip + i;
        int inputEndIndex = inputStartIndex + inputLength;
        int outputStartIndex = inputEndIndex + distanceFromInputToOutput;
        int outputEndIndex = outputStartIndex + outputLength;
        slice(dataArray, &trainingData->values[i].input, inputStartIndex, inputEndIndex);
        slice(dataArray, &trainingData->values[i].output, outputStartIndex, outputEndIndex);
    }
    return trainingData;
};

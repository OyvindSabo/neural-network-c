#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

struct LargeArray *readArrayFromTextFile(char fileName[100])
{
  printf("dataUtils.c: readArrayFromTextFIle\n");
  struct LargeArray *dataArray;
  dataArray = malloc(sizeof(struct LargeArray));
  FILE *file = fopen(fileName, "r");
  char currentLine[100]; // A double has 15 decimal digits of precision

  (*dataArray).length = 0;
  while (fgets(currentLine, sizeof(currentLine), file) != NULL)
  {
    (*dataArray).values[(*dataArray).length] = atof(currentLine);
    (*dataArray).length += 1;
  }
  fclose(file);
  return dataArray;
};

void writeArrayToTextFile(struct LargeArray *dataArray, char fileName[100])
{
  FILE *file = fopen(fileName, "w");
  for (int i = 0; i < (*dataArray).length; i++)
  {
    fprintf(file, "%f\n", (*dataArray).values[i]);
  }
  fclose(file);
};

struct TrainingData *generateTrainingData(char fileName[100], struct TrainingDataConfig *trainingDataConfig)
{
  int numberOfFirstValuesToSkip = (*trainingDataConfig).numberOfFirstValuesToSkip;
  int amountOfDataToUseForTraining = (*trainingDataConfig).amountOfDataToUseForTraining;
  int inputLength = (*trainingDataConfig).inputLength;
  int outputLength = (*trainingDataConfig).outputLength;
  int distanceFromInputToOutput = (*trainingDataConfig).distanceFromInputToOutput;

  struct LargeArray *dataArray = readArrayFromTextFile(fileName);
  struct TrainingData *trainingData;
  
  trainingData = malloc(sizeof(struct TrainingData));

  (*trainingData).length =
      amountOfDataToUseForTraining -
      numberOfFirstValuesToSkip -
      inputLength -
      distanceFromInputToOutput -
      outputLength;
  for (int i = 0; i < (*trainingData).length; i++)
  {
    int inputStartIndex = numberOfFirstValuesToSkip + i;
    int inputEndIndex = inputStartIndex + inputLength;
    int outputStartIndex = inputEndIndex + distanceFromInputToOutput;
    int outputEndIndex = outputStartIndex + outputLength;
    (*trainingData).values[i].input.length = 0;
    for (int j = 0; j < inputEndIndex - inputStartIndex; j++)
    {
      (*trainingData).values[i].input.values[j] = (*dataArray).values[j];
      (*trainingData).values[i].input.length++;
      //printf("dataUtils: Increased input length to %d\n", (*trainingData).values[i].input.length);
    }
    (*trainingData).values[i].output.length = 0;
    for (int j = 0; j < outputEndIndex - outputStartIndex; j++)
    {
      (*trainingData).values[i].output.values[j] = (*dataArray).values[j];
      (*trainingData).values[i].output.length++;
    }
  }
  return trainingData;
};

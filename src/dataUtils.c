#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array
{
  double values[100];
  int length;
};

struct TrainingDataConfig
{
  int numberOfFirstValuesToSkip;
  int amountOfDataToUseForTraining;
  int inputLength;
  int outputLength;
  int distanceFromInputToOutput;
};

struct TrainingDatum
{
  struct Array input;
  struct Array output;
};

struct TrainingData
{
  struct TrainingDatum values[10000];
  int length;
};

struct Array *readArrayFromTextFile(char fileName[100])
{
  struct Array dataArray;
  FILE *file = fopen(fileName, 'r');
  char currentLine[10];

  assert(file != NULL);

  dataArray.length = 0;
  while (fgets(currentLine, sizeof(currentLine), file) != NULL)
  {
    dataArray.values[dataArray.length] = atof(currentLine);
    dataArray.length += 1;
  }
  fclose(file);
  return &dataArray;
};

void writeArrayToTextFile(struct Array dataArray, char fileName[100])
{
  FILE *file = fopen(fileName, 'w');
  for (int i = 0; i < dataArray.length; i++)
  {
    fprintf(file, "%f\n", dataArray.values[i]);
  }
  fclose(file);
};

struct TrainingData generateTrainingData(char fileName[100], struct TrainingDataConfig trainingDataConfig)
{
  int numberOfFirstValuesToSkip = trainingDataConfig.numberOfFirstValuesToSkip;
  int amountOfDataToUseForTraining = trainingDataConfig.amountOfDataToUseForTraining;
  int inputLength = trainingDataConfig.inputLength;
  int outputLength = trainingDataConfig.outputLength;
  int distanceFromInputToOutput = trainingDataConfig.distanceFromInputToOutput;
  struct Array *dataArray = readArrayFromTextFile(fileName);
  struct TrainingData trainingData;
  int trainingDataLength =
      amountOfDataToUseForTraining -
      numberOfFirstValuesToSkip -
      inputLength -
      distanceFromInputToOutput -
      outputLength;
  for (int i = 0; i < trainingDataLength; i++)
  {
    int inputStartIndex = numberOfFirstValuesToSkip + i;
    int inputEndIndex = inputStartIndex + inputLength;
    int outputStartIndex = inputEndIndex + distanceFromInputToOutput;
    int outputEndIndex = outputStartIndex + outputLength;
    for (int j = inputStartIndex; j < inputEndIndex; j++)
    {
      trainingData.values[i].input.values[j] = (*dataArray).values[j];
    }
    for (int j = outputStartIndex; j < outputEndIndex; j++)
    {
      trainingData.values[i].output.values[j] = (*dataArray).values[j];
    }
  }
  return trainingData;
};

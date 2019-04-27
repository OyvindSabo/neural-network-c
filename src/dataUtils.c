#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array
{
  double values[100];
  int length;
};

struct Array readArrayFromTextFile(char fileName[100]) {
  struct Array dataArray;
  FILE *file = fopen(fileName, 'r');
  char currentLine[10];

  assert(file != NULL);

  while (fgets(currentLine, sizeof(currentLine), file) != NULL) {
    dataArray.values[dataArray.length] = atof(currentLine);
  }
  fclose(file);
  return dataArray;
};

void writeArrayToTextFile(struct Array dataArray, char fileName[100]) {
  FILE *file = fopen(fileName, 'w');
  for (int i = 0; i < dataArray.length; i++) {
    fprintf(file, "%f\n", dataArray.values[i]);
  }
  fclose(file);
};

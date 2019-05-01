#ifndef DATA_UTILS_H
#define DATA_UTILS_H

void slice(struct LargeArray *inputArray, struct Array *outputArray, int startIndex, int endIndex);

struct LargeArray *readArrayFromTextFile(char fileName[100]);

void writeArrayToTextFile(struct LargeArray *dataArray, char fileName[100]);

struct TrainingData *generateTrainingData(char fileName[100], struct TrainingDataConfig *trainingDataConfig);

#endif

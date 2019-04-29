#ifndef DATA_UTILS_H
#define DATA_UTILS_H

struct LargeArray *readArrayFromTextFile(char fileName[100]);

void writeArrayToTextFile(struct LargeArray *dataArray, char fileName[100]);

struct TrainingData *generateTrainingData(char fileName[100], struct TrainingDataConfig *trainingDataConfig);

#endif

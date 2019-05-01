#include <stdbool.h>

#ifndef NETWORK_UTILS_H
#define NETWORK_UTILS_H

double sigmoid(double x);

void feedForward(struct Network *network, struct Array *inputValues, _Bool useNewWeights);

double randomBetweenZeroAndOne();

double randomMutation(double weight, double mutationFactor);

double getError(struct Network *network, struct TrainingData *trainingData, _Bool useNewWeights);

void assignWeightsFromTextFile(struct Network *network, char fileName[100]);

void writeWeightsToFile(struct Network *network, char fileName[100]);

#endif

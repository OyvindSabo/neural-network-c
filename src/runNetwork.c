#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "networkUtils.h"

struct Array *runNetwork(struct Network *network, struct Array *input)
{
    struct Array *outputArray;
    outputArray = malloc(sizeof(struct Array));

    feedForward(network, input, false);
    for (int i = 0; i < network->outputLength; i++)
    {
        outputArray->values[i] = network->outputLayer[i].value;
    }
    return outputArray;
}

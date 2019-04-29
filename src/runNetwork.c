#include "types.h"
#include "networkUtils.h"

struct Array runNetwork(struct Network network, struct Array input)
{
  feedForward(&network, &input, false);
  struct Array outputArray;
  for (int i = 0; i < network.outputLength; i++)
  {
    outputArray.values[i] = network.outputLayer[i].value;
  }
  return outputArray;
}

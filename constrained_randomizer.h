This function takes a budget, a number of items, and an array of costs, and generates an unbiased random selection from among the valid arrangements of items (with validity defined as in the unbounded knapsack problem; in particular, any item can occur multiple times).  The results are output to the fourth argument, and the fifth argument optionally allows for usage of a different random number generator.

#ifndef CONSTRAINED_RANDOMIZER_H
#define CONSTRAINED_RANDOMIZER_H

void constrained_randomizer (long long budget, int n, unsigned int* costs, unsigned int* output, int (*RNG)() = rand());

#endif

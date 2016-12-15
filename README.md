# Constrained-Randomizer
The Constrained_randomizer function (once built) will take a budget and an array of costs for various items, and randomly selects a number of each item such that the total remains under budget.  (The constraint is thus the same as in the unbounded knapsack problem, but rather than optimizing the task is to randomly select a within-constraint solution such that every such solution has equal probability.)  The random selection is unbiased: Each valid possibility has equal likelihood (within the limitations of the randomizer used).

Also to be included in the repository are:

* A sample.cpp file that contains a main() function allowing the repository contents (.h and .cpp files) to be compiled into a usable program
  
* A performance.md file estimating the algorithm's performance under various input conditions

This function is based on work I originally did for my unofficial patch to the game Sid Meier's Alpha Centauri; more information about said patch can be found at http://alphacentauri2.info/wiki/Yitzi's_patch (external link).

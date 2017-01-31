# Constrained-Randomizer
This project is based on work I originally did for my unofficial patch to the game Sid Meier's Alpha Centauri.  (More information about said patch can be found at http://alphacentauri2.info/wiki/Yitzi's_patch (external link).)

The Constrained_randomizer function takes a budget and an array of costs for various items, and randomly selects a number of each item such that the total remains under budget.  (This therefore bears a superficial resemblance to the unbounded knapsack problem, but differs in that the task being performed is not one of optimization, but rather randomization.)  The random selection is unbiased: Each valid possibility has equal likelihood (within the limitations of the underlying random number generator).

Also to be included in the repository are:

* A sample.cpp file that contains a main() function allowing the repository contents (.h and .cpp files) to be compiled into a usable program
  
* A performance.md file estimating the algorithm's performance under various input conditions

It is also worth noting that, while the function yields a random solution, a maximal solution (i.e. one such that adding any item would exceed the constraint) can be achieved by calling the function on all but the lowest-cost item, and then using the remaining budget to determine the quantity of this last item.

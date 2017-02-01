/*This function takes a budget, an array of strictly positive costs, and a random number generator, and generates an unbiased 
  random selection from among the valid arrangements of items (with validity defined as in the unbounded knapsack problem; in 
  particular, any item can occur multiple times).  The results are output to the output argument, which should have the same  
  size as the costs argument.*/

#ifndef CONSTRAINED_RANDOMIZER_H
#define CONSTRAINED_RANDOMIZER_H

#include <vector>
#include <set>
#include <exception>
#include <algorithm>
#include <numeric>
#include <functional>
#include <random>

/*T should be an integral type or a class that represents an integer (in particular, it should behave normally under arithmetic 
  operations, and there should be no valid values between x and x+1).  less<T> and divides<T> should be defined, with the usual 
  meanings.
  
  If half_open_dist is false, the distribution parameter should have an interface similar to the uniform_int_distribution class: 
  It should be constructed with closed lower and upper bounds as arguments, and called with no arguments.  If half_open_RNG is 
  true, the lower bound should be closed, and the upper bound open.  In either case, distribution should be callable with
  an argument of type URNG, yielding a result of type T (or a type implicitly convertible to it).*/

template <class URNG, typename T, class distribution = std::uniform_int_distribution<T>, bool half_open_dist = false>
void constrained_randomizer (T budget, const std::vector<T>& costs, std::vector<T>& output, URNG g);

//*************************************Implementation portion begins here***************************************



/*Mathematical note: If a collection of n distinct uniformly random integer values in [1,m+n] are sorted, the differences 
  between adjacent values will constitute an unbiased ordered selection of positive integers adding up to at most 
  m+n; subtracting 1 from each difference therefore results in non-negative integers adding up to at most m.
  
  m is set higher than the given budget due to truncation when dividing each value by the cost; a trial-and-error
  approach is then used to eliminate solutions that exceed the actual budget.  Each potential output derives from a set of
  Prod differences between adjacent values, where Prod is the product of all the costs.*/

template <class URNG, typename T, class distribution = std::uniform_int_distribution<T>, bool half_open_dist = false>
void constrained_randomizer (T budget, const std::vector<T>& costs, std::vector<T>& output, URNG g) {
    int n = costs.size();
    if (output.size() != n) throw std::invalid_argument("Input and output vectors must be the same size.");
    if (budget <= 0) throw std::invalid_argument("All input values must be strictly positive.");
    T budget_used; // will be initialized in a do…while loop later.
    T expanded_budget = budget;
    for (int i = 0; i < n; ++i) {
        T cost = costs[i];
        if (cost <= 0) throw std::invalid_argument("All input values must be strictly positive.");
        expanded_budget += cost;
    }
    distribution dist(1, expanded_budget + half_open_dist);
    do {
        std::set<T> distinct_randoms;
        while (distinct_randoms.size() < n) {
            distinct_randoms.insert(dist(g));
        }
        std::vector<T> differences(n);
        std::adjacent_difference (distinct_randoms.begin(), distinct_randoms.end(), differences.begin());
        std::transform(differences.begin(), differences.end(), differences.begin(), 
            [](T x) -> T { return --x;});
        std::transform(differences.begin(), differences.end(), costs.begin(), output.begin(), std::divides<T>());
        budget_used = std::inner_product(costs.begin(), costs.end(), output.begin(), 0);
    }
    while (budget_used > budget);
}
#endif

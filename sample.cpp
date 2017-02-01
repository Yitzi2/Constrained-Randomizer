#include <constrained_randomizer>
#include <vector> //Not really necessary because it’s included through constrained_randomizer, but good practice anyway.
#include <random>
#include <iostream>
#include <ctime>
using namespace std;

mt19937 randomizer(time(0)); //This method of seed generation will suffice for a sample.

int main()
{
int budget;
int n;
cout << "Insert a budget value, followed by the number of items, followed by the costs of each item.";
cin >> budget >> n;
vector<int> costs(n);
vector<int> output(n);
for (int i = 0; i < n; ++i) cin >> costs[i];
constrained_randomizer (budget, costs, output, randomizer);
cout << "The randomized quantities of each item are:" << "\n";
for (int i = 0; i < n-1; ++i) cout << output[i] << ", ";
cout << "and " << output[n-1];
return (0);
}

#include <iostream>
#include <algorithm>
using namespace std;
// Structure to represent an item with value and weight
struct Item {
    int value, weight;
    double ratio;
    Item(int v = 0, int w = 0) : value(v), weight(w), ratio((double)v / w) {}
};
// Comparator function to sort items based on value/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}
// Function to solve the Fractional Knapsack Problem
double fractionalKnapsack(int W, int n, Item items[]) {
    // Sort items based on value/weight ratio
    sort(items, items + n, compare);

    double maxValue = 0.0;
    for (int i = 0; i < n; ++i) {
        if (W >= items[i].weight) {
            W -= items[i].weight;
            maxValue += items[i].value;
        } else {
            maxValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return maxValue;
}
int main() {
    int testCases;
    cout << "Enter the number of test cases: ";
    cin >> testCases;
    for (int t = 0; t < testCases; ++t) {
        int n, capacity;
        cout << "Test Case " << t + 1 << endl;
        cout << "Enter the number of items: ";
        cin >> n;
        Item items[n];
        cout << "Enter the items (value weight):" << endl;
        for (int i = 0; i < n; ++i) {
            int value, weight;
            cin >> value >> weight;
            items[i] = Item(value, weight);
        }
        cout << "Enter the knapsack capacity: ";
        cin >> capacity;
        cout << "Maximum value = " << fractionalKnapsack(capacity, n, items) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;



struct Item {
    int weight;
    int profits;
    double u_profit; // unit profit (ratio of profits to weight)
};


//Function to return the max unit profit between two structure variable
bool compare(Item a, Item b) {

    return a.u_profit > b.u_profit;
}

double fractionalKnapsack(int w, Item items[], int n) {
    //loop to calculate unit profits for each item
    for (int i = 0; i < n; i++) {
        items[i].u_profit = double(items[i].profits) / items[i].weight;
    }

    // Sort items based on unit profit in descending order
    sort(items, items + n, compare);

    double totalValue = 0.0;
    
    //loop to iterate and fill the knapsack
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= w) {
            // Take the whole item
            totalValue += items[i].profits;
            w -= items[i].weight;
        } else {
            // Take fraction of the item to fill the knapsack
            totalValue += items[i].profits * (double(w/items[i].weight));
             // Knapsack is full
            break;
        }
    }

    return totalValue;
}

int main() {
    

    int n = 7;
    int w = 15;

    int p[] = {10,5,15,7,6,18,3}; 
    int W[] = {2,3,5,7,1,4,1};

    Item items[n];

    //loop for initializing values to structure members

    for(int i=0;i<n;i++){
        items[i].profits = p[i];
        items[i].weight = W[i];
    }


    double maxValue = fractionalKnapsack(w, items, n);

    cout << "Maximum profits in the knapsack = " << maxValue << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

vector<Item> item;

int knapsack(int i, int cap){

    if (i >= item.size() || cap <= 0) {
        return 0;
    }

    int skip = knapsack(i + 1, cap);

    int take = 0;
    if (item[i].weight <= cap) {
        take = item[i].value + knapsack(i + 1, cap - item[i].weight);
    }

    return max(take, skip);
}

int main(){
    int n, capacity;
    cin >> n >> capacity;

    item.resize(n);

    for(int i = 0; i < n; i++){
        cin >> item[i].weight >> item[i].value;
    }

    cout << knapsack(0, capacity) << endl;

    return 0;
}
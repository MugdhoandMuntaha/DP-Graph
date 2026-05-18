#include<bits/stdc++.h>
using namespace std;

vector<int> price;
int n;

int RC(int i, int len){

    if (i > n || len == 0) {
        return 0;
    }

    int skip = RC(i + 1, len);

    int take = 0;
    if (i <= len) {
        take = price[i] + RC(i, len - i);
    }

    return max(take, skip);
}

int main(){
    int len;
    cin >> n >> len;

    price.resize(n + 1);

    for(int i = 0; i <= n; i++){
        cin >> price[i];
    }

    cout << RC(1, len) << endl;

    return 0;
}
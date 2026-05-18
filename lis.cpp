#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr){
    int n = arr.size();

    vector<int> dp(n, 1);

    int ans = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){

            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << LIS(arr) << endl;

    return 0;
}
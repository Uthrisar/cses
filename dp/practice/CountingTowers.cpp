#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int main(){
    int t;
    cin >> t;
    vector<vector<int>> dp(1000000,vector<int>(2));
    while(t--){
        int n;
        cin >> n;
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i = 1; i < n; i++){
            dp[i][0] = (4LL*dp[i-1][0]+dp[i-1][1])%M;
            dp[i][1] = (2LL*dp[i-1][1]+dp[i-1][0])%M;
        }
        cout << ((dp[n-1][0]+dp[n-1][1])%M) << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    vector<vector<int>> dp(n,vector<int>(n));
    if(grid[0][0] == '.'){
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            } else {
                if(i >= 1){
                    dp[i][j] = dp[i-1][j];
                }
                if(j >= 1){
                    dp[i][j] = (dp[i][j]+dp[i][j-1])%M;
                }
            }
        }
    }
    cout << dp[n-1][n-1];
}
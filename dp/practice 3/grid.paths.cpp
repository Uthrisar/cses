#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<string> board(n);
    for(int i=0; i<n; i++){
        cin>>board[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == '.'){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i != 0){
                    dp[i][j] = dp[i-1][j];
                }
                if(j != 0){
                    dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
                }
            }
        }
    }
    cout << dp[n-1][n-1];
}
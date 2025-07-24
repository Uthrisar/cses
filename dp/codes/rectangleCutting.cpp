#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9+9;

int main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,inf));
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int v = 1; v < j; v++){
                dp[i][j] = min(dp[i][j],1+dp[i][j-v]+dp[i][v]);
            }
            for(int h = 1; h < i; h++){
                dp[i][j] = min(dp[i][j],1+dp[i-h][j]+dp[h][j]);
            }
        }
    }
    cout << dp[a][b];
}
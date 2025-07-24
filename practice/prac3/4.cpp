#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n, x;
    cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    int dp[n][x+1];
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = 0;
            if(i>=1){
                dp[i][j] = dp[i-1][j];
            }
            if(j>=c[i]){
                dp[i][j] = (dp[i][j]+dp[i][j-c[i]])%M;
            }
        }
    }
    cout << dp[n-1][x];
}
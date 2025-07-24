#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

const int inf = 1e9+10;

int main(){
    int a, b;
    cin >> a >> b;
    vector<vi> dp(a+1,vi(b+1,inf));
    for(int i = 1; i <= min(a,b); i++){
       dp[i][i] = 0;
    }
    for(int l = 1; l <= a; l++){
        for(int w = 1; w <= b; w++){
            if(l == w){
                continue;
            }
            for(int i = 1; i < l; i++){
                dp[l][w] = min(dp[l][w],1+dp[i][w]+dp[l-i][w]);
            }
            for(int j = 1; j < w; j++){
                dp[l][w] = min(dp[l][w],1+dp[l][j]+dp[l][w-j]);
            }
        }
    }
    cout << dp[a][b];
}
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

const ll mod_inv = 5e8+4;

int main(){
    int n;
    cin >> n;
    if((n*(n+1))%4 != 0){
        cout << 0 << "\n";
        return 0;
    }
    int mxSum = (n*(n + 1))/4;
    vector<vector<ll>> dp(n+1, vector<ll>(mxSum+1,0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        int val = i;
        for(int j = 0; j <= mxSum; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= val){
                dp[i][j] = (dp[i][j] + dp[i-1][j-val])%MOD;
            }
        }
    }
    cout << (dp[n][mxSum]*mod_inv)%MOD << "\n";
}
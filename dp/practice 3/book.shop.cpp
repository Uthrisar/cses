#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> h(n+1), s(n+1);
    for(int i=1; i<=n; i++){
        cin >> h[i];
    }
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int money=1; money<=x; money++){
        dp[0][money] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int money=1; money<=x; money++){
            dp[i][money] = dp[i-1][money];
            if(money >= h[i]){
                dp[i][money] = max(dp[i][money], dp[i-1][money-h[i]]+s[i]);
            }
        }
    }
    cout << dp[n][x];
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> coin(n+1);
    for(int i = 1; i <= n; i++){
        cin >> coin[i];
    }
    int mxSum = 1e5;
    vector<vector<int>> dp(n+1,vector<int>(mxSum+1,false));
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= mxSum; c++){
            dp[i][c] = dp[i-1][c];
            if(c >= coin[i]){
                dp[i][c] = (dp[i][c] || dp[i-1][c-coin[i]]);
            }
        }
    }
    int cnt = 0;
    for(int c = 1; c <= mxSum; c++){
        if(dp[n][c]){
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int c = 1; c <= mxSum; c++){
        if(dp[n][c]){
            cout << c << " ";
        }
    }

}
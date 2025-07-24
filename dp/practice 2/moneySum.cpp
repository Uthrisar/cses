#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> c(n+1);
    for(int i=1; i<=n; i++){
        cin>>c[i];
    }
    bool dp[n+1][100001];
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int sum = 1; sum<=100000; sum++){
            dp[i][sum] = dp[i-1][sum];
            if(sum >= c[i]){
                dp[i][sum] = (dp[i][sum] || dp[i-1][sum-c[i]]);
            }
        }
    }
    int cnt = 0;
    for(int i=1; i<=100000; i++){
        if(dp[n][i]) cnt++;
    }
    cout << cnt << endl;
    for(int i=1; i<=100000; i++){
        if(dp[n][i]) cout << i <<" ";
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int wt[n];
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    pair<int,int> dp[1<<n];
    dp[0] = {1,0};
    for(int mask=1; mask<(1<<n); mask++){
        dp[mask].first = n;
        dp[mask].second = 0;
        for(int bit=0; bit<n; bit++){
            if(mask&(1<<bit)){
                int prev_mask = mask^(1<<bit);
                auto option = dp[prev_mask];
                if(option.second+wt[bit] <= x){
                    option.second += wt[bit];
                } else {
                    option.first += 1;
                    option.second = wt[bit];
                }
                dp[mask] = min(dp[mask], option);
            }
        }
    }
    cout<<dp[(1<<n)-1].first;
}
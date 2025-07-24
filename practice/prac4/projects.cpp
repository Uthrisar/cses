#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define vi vector<ll>
#define pi pair<ll,ll>
using namespace std;

bool cmp(pair<ll,pi> p1, pair<ll,pi> p2){
    return p1.ss.ff < p2.ss.ff;
}

int main(){
    int n;
    cin >> n;
    vector<pair<ll,pi>> proj(n+1);
    for(int i = 1; i <= n; i++){
        cin >> proj[i].ff >> proj[i].ss.ff >> proj[i].ss.ss;
    }
    vi dp(n+1,0);
    dp[0] = 0;
    sort(proj.begin()+1,proj.end(),cmp);
    vector<ll> endPts(n+1,0);
    for(int i = 1; i <= n; i++){
        endPts[i] = proj[i].ss.ff;
    }
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        auto it = lower_bound(endPts.begin()+1,endPts.end(),proj[i].ff);
        it--;
        int j = it-endPts.begin();
        dp[i] = max(dp[i],dp[j]+proj[i].ss.ss);
    }
    cout << dp[n];
}
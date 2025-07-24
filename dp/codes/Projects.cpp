#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ppi pair<int,pair<int,int>>
using namespace std;

bool cmp(ppi a, ppi b){
    return a.se.fi < b.se.fi;
}

int findIdx(vector<int>& endPts, int val){
    auto it = lower_bound(endPts.begin()+1,endPts.end(),val);
    if(it == endPts.begin()+1){
        return 0;
    }
    it--;
    return distance(endPts.begin(),it);
}

int main(){
    int n;
    cin >> n;
    vector<ppi> v(n+1);
    for(int i = 1; i <= n; i ++){
        cin >> v[i].fi >> v[i].se.fi >> v[i].se.se;
    }
    sort(v.begin()+1,v.end(),cmp);
    vector<int> endPoints(n+1);
    for(int i = 1; i <= n; i++){
        endPoints[i] = v[i].se.fi;
    }
    ll dp[n+1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        int j = findIdx(endPoints,v[i].fi);
        dp[i] = max(dp[i],dp[j]+v[i].se.se);
    }
    cout << dp[n];
}
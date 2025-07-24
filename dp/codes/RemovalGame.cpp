#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MIN = -5e13;

vector<vector<ll>> dp(5001,vector<ll>(5001,MIN));

ll func(int i, int j, vector<ll>& x, vector<ll>& pref){
    if(i == j) return x[i];
    if(dp[i][j] != MIN) return dp[i][j];
    ll ans1 = x[i]+pref[j]-pref[i]-func(i+1,j,x,pref);
    ll ans2;
    if(i == 0){
        ans2 = x[j]+pref[j-1] - func(i,j-1,x,pref);
    } else {
        ans2 = x[j]+pref[j-1]-pref[i-1]-func(i,j-1,x,pref);
    }
    return dp[i][j] = max(ans1,ans2);
}

int main(){
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> pref(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    pref[0] = x[0];
    for(int i = 1; i < n; i++){
        pref[i] = (pref[i-1]+x[i]);
    }
    cout << func(0,n-1,x,pref);
}
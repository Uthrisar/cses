#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n; cin >> n;
    vector<ll> coins(n);
    for(auto &x: coins){
        cin >> x;
    }
    sort(coins.begin(),coins.end());
    map<ll,bool> m;
    m[0] = 1;
    ll ans = 1;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        m[coins[i]] = 1;
        sum += coins[i];
        m[sum] = 1;
    }

    for(int mn = 1; mn; mn++){

    }

    cout << ans;
}
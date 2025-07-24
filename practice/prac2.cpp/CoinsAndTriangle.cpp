#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPossible(ll h, ll n){
    return (h*(h+1)/2) <= n;
}

int main(){
    ll tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;
        ll lo = 0, hi = n;
        while(hi-lo > 1){
            ll mid = (hi+lo)/2;
            if(isPossible(mid,n)){
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        if(isPossible(hi,n)){
            cout << hi << endl;
        } else {
            cout << lo << endl;
        }
    }
    return 0;
}
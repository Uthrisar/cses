#include <bits/stdc++.h>
#define ll long long
using namespace std;


bool check(ll sum, int k, vector<int>& a){
    int n = a.size();
    k = k-1;
    ll curr = 0;
    for(int i=0; i<n; i++){
        if(sum >= curr+a[i]){
            curr += a[i];
        } else {
            if(a[i] > sum) return false;
            k--;
            curr = a[i];
        }
    }
    return k>=0;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    ll lo = 1, hi = 1e15, ans;
    while(lo <= hi){
        ll mid = lo+(hi-lo)/2;
        if(check(mid, k, a)){
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout<<ans;
}
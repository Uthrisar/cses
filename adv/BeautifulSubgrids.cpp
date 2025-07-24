#pragma GCC target("popcnt")
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bitset<3000>> v1(n);
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    ll ans = 0;
    int cnt;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cnt = (v1[i]&v1[j]).count();
            ans += cnt*1LL*(cnt-1)/2;
        }
    }
    cout<<ans;
}
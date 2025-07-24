#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<int> v1(n);
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    sort(v1.begin(),v1.end());
    ll ans = 0;
    if(n&1){
        for(int i = 0; i < n; i++){
            ans += abs(v1[i]-v1[(n-1)/2]);
        }
    } else {
        ll ans1 = 0,ans2 = 0;
        for(int i = 0; i < n; i++){
            ans1 += abs(v1[i]-v1[n/2]);
            ans2 += abs(v1[i]-v1[(n-2)/2]);
        }
        ans = max(ans1,ans2);
    }
    cout << ans;
}
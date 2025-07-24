#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    int sz = int(1<<n);
    ll ans = 1e12;
    for(int mask = 1; mask < sz; mask++){
        ll sum1 = 0, sum2 = 0;
        for(int bit = 0; bit < n; bit++){
            if(mask&(1<<bit)){
                sum1 += p[bit];
            } else {
                sum2 += p[bit];
            }
        }
        ans = min(ans,abs(sum1-sum2));
    }
    cout << ans;
}
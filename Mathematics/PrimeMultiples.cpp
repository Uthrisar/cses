#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; int k;
    cin>>n>>k;
    vector<long long> a(k);
    for(int i=0; i<k; i++){
        cin>>a[i];
    }
    long long ans = 0;
    for(int mask=1; mask<(1<<k); mask++){
        long long prod = 1;
        int setbit_count = 0;
        bool overflow = false;
        for(int bit=0; bit<k; bit++){
            if(mask&(1<<bit)){
                setbit_count++;
                if(prod > n/a[bit]){
                    overflow = true;
                    break;
                }
                prod *= a[bit];
            }
        }
        if(!overflow && prod <= n){
            if(setbit_count%2 == 1){
                ans += n/prod;
            } else {
                ans -= n/prod;
            }
        }
    }
    cout<<ans;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e6+1;

int main(){
    int n;
    cin>>n;
    vector<int> freq(MAXN,0);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        freq[x]++;
    }
    vector<ll> gcd_cnt(MAXN,0);
    for(int i=1; i<MAXN; i++){
        for(int j=i; j<MAXN; j += i){
            gcd_cnt[i] += freq[j];
        }
        gcd_cnt[i] = (gcd_cnt[i]*(gcd_cnt[i]-1))/2;
    }
    for(int i=MAXN-1; i>=1; i--){
        for(int j=2*i; j<MAXN; j += i){
            gcd_cnt[i] -= gcd_cnt[j];
        }
    }
    cout<<gcd_cnt[1];
}
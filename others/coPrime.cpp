#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e6+1;

int main(){
    int n;
    cin>>n;
    vector<int> freq(MAXN, 0);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        freq[x]++;
    }
    vector<ll> cnt(MAXN, 0);
    for(int i=1; i<MAXN; i++){
        for(int j=i; j<MAXN; j += i){
            cnt[i] += freq[j];
        }
        cnt[i] = (cnt[i]*(cnt[i]-1))/2;
    }

    for(int i=MAXN-1; i>=1; i--){
        for(int j=2*i; j<MAXN; j += i){
            cnt[i] -= cnt[j];
        }
    }
    cout<<cnt[1];
}
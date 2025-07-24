#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int maxN = 1e6+1;
    vector<int> freq(maxN,0);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        freq[x]++;
    }
    int ans = 0;
    vector<int> multiples(maxN,0);
    for(int i = 1; i < maxN; i++){
        for(int j = 2*i; j < maxN; j += i){
            if(freq[i] && freq[j]){
                multiples[i]++;
            }
        }
    }
    for(int i = 1; i < maxN; i++){
        if(multiples[i]) ans = i;
    }
    cout << ans <<"\n";
}
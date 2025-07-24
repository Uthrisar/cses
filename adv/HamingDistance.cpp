#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<bitset<30>> v1(n);
    for(int i=0; i<n; i++) cin>>v1[i];
    int ans = 32;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int cnt = (v1[i]^v1[j]).count();
            ans = min(ans,cnt);
        }
    }
    cout<<ans;
}
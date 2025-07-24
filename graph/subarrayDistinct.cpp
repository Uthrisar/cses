#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int l=0, r=0; long long ans=0;
    unordered_map<int,int> ump;
    while(r<n){
        ump[a[r]]++;
        while(int(ump.size())>k){
            ump[a[l]]--;
            if(ump[a[l]] == 0){
                ump.erase(a[l]);
            }
            l++;
        }
        ans += (r-l+1);
        r++;
    }
    cout<<ans;
}
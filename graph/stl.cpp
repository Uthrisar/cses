#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    vector<int> pf(n+1);
    pf[0] = 0;
    for(int i=1; i<=n; i++){
        pf[i] = pf[i-1]+arr[i];
    }
    int ans = -1e9;
    for(int i=1; i<=k; i++){
       ans = max(ans,pf[i]+pf[n]-pf[n-(k-i)]);
    }
    cout << ans;
}
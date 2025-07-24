#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    vector<int> pf(n+1),sf(n+1);
    pf[0] = 0;
    sf[n] = arr[n];
    for(int i=1; i<=n; i++){
        pf[i] = pf[i-1]+arr[i];
    }
    for(int i=n-1; i>=1; i++){
        sf[i] = sf[i+1]+arr[i];
    }
    cout << n <<" "<<k<<" "<<arr[n]<<endl;
    int ans = -1e9;
    for(int i=1; i<=k; i++){
       ans = max(ans,pf[i]+sf[n-(k-i)+1]);
    }
    cout << ans;
}
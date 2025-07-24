#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(),arr.end());
    vector<int> ans(3,-1);
    bool flag = false;
    for(int i=0; i<n; i++){
        int lo = i+1;
        int hi = n-1;
        while(lo < hi){
            int sum = arr[i].first+arr[lo].first+arr[hi].first;
            if(sum == x){
                ans[0] = arr[i].second;
                ans[1] = arr[lo].second;
                ans[2] = arr[hi].second;
                flag = true;
                break;
            } else if(sum > x){
                hi--;
            } else {
                lo++;
            }
        }
        if(flag) break;
    }
    if(ans[0] == -1){
        cout << "IMPOSSIBLE";
    } else {
        sort(ans.begin(),ans.end());
        cout << ans[0] <<" "<< ans[1] <<" "<< ans[2];
    }
}
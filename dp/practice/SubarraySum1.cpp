#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    ll sum = 0;
    int cnt = 0;
    unordered_map<ll,int> m;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(sum == k){
            cnt++;
        }
        if(m.find(sum-k) != m.end()){
            cnt += m[sum-k];
        }
        m[sum]++;
    }
    cout << cnt ;
}
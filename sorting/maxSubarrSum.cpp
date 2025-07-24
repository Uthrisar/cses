#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<ll> v1(n);
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    ll sum = 0, mx = -1;
    int neg_cnt = 0, mx_neg = -1e9;
    for(int i = 0; i < n; i++){
        if(v1[i] < 0){
            neg_cnt += 1;
            if(mx_neg < v1[i]){
                mx_neg = v1[i];
            }
        }
        sum += v1[i];
        if(sum < 0){
            sum = 0;
        }
        if(sum > mx){
            mx = sum;
        }
    }
    (neg_cnt == n)? cout << mx_neg << endl : cout << mx << endl;
}
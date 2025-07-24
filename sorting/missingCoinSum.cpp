#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    ll sum = 1;
    for(int i=0; i<n; i++){
        if(coins[i] > sum){
            break;
        }
        sum += coins[i];
    }
    cout<<sum;
}
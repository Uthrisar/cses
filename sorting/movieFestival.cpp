#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int>

bool cmp(pi a, pi b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pi> v1(n);
    for(int i = 0; i < n; i++){
        cin >> v1[i].first >> v1[i].second;
    }
    sort(v1.begin(),v1.end(),cmp);
    int prev_ending = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v1[i].first >= prev_ending){
            ans += 1;
            prev_ending = v1[i].second;
        }
    }
    cout << ans;
}
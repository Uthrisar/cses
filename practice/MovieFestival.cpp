#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int>

bool cmp(pi a, pi b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    vector<pi> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    int ans = 1;
    int prev_end = v[0].second;
    for(int i = 1; i < n; i++){
        if(v[i].first >= prev_end){
            ans += 1;
            prev_end = v[i].second;
        }
    }
    cout << ans;
}
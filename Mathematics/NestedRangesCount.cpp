#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int>& p, const pair<int,int>& q){
    return (p.first == q.first) ? (p.second < q.second) : (p.first < q.first);
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> ranges(n);
    for(int i=0; i<n; i++){
        cin >> ranges[i].first >> ranges[i].second;
    }
    sort(ranges.begin(),ranges.end(),cmp);
    for(int i=0; i<n; i++){
        auto it = lower_bound(ranges.begin(),ranges.end(),{-1,ranges[i].second});
    }
}
#include<bits/stdc++.h>
using namespace std;

int n,m;

int h[200001];

int seg[4*200001];

int build(int idx, int low, int high){
    if(low == high) return h[low];
    int mid = (low+high)/2;
    int left = build(2*idx,low,mid);
    int right = build(2*idx+1,mid+1,high);
    return seg[idx] = min(left,right);
}

void update(int a, int idx, int low, int high){
    int mid = (low+high)/2;
    update(a,2*idx,low,mid);
    update(a,2*idx+1,mid+1,high);
}

int query(int a, int idx, int low, int high){
    if(low == high) {
        if(a == low) return seg[idx];
        else return 1e9;
    }
    int mid = (low+high)/2;
    int left = query(a,2*idx,low,mid);
    int right = query(a,2*idx+1,mid+1,high);
    return min(left,right);
}


int main(){
    cin >> n >> m;
    vector<int> r(m);
    for(int i = 1; i <= n; i++){
        int x;
    }

}
#include<bits/stdc++.h>
using namespace std;

int a[200001];

int seg[4*200001];

int n;

int build(int idx, int low, int high){
    if(low == high) return seg[idx] = a[low];
    int mid = (low+high)/2;
    int left = build(2*idx,low,mid);
    int right = build(2*idx+1,mid+1,high);
    return seg[idx] = left^right;
}

void update(int a, int b, int u, int idx, int low, int high){
    if(low >= a && high <= b){

    }
    int mid = (low+high)/2;
    update(a,b,u,2*idx,low,mid);
    update(a,b,u,2*idx+1,mid+1,high);
}

int query(int k, int idx, int low, int high){
    if(low == high && low == k) return seg[idx];
    int mid = (low+high)/2;
    int left = query(k,2*idx,low,mid);
    int right = query(k,2*idx+1,mid+1,high);
    return left^right;
}

int main(){
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << query(a,b,1,1,n) << endl;
    }
}
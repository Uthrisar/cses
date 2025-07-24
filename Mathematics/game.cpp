#include <bits/stdc++.h>
#define ll long long
using namespace std;

int seg[4010];

ll dp[1001][1001];

void build(int idx, int lo, int hi, vector<int>& a){
  if(lo == hi){
    seg[idx] = a[lo];
    return;
  }
  int mid = (lo+hi)/2;
  build(2*idx,lo,mid,a);
  build(2*idx+1,mid+1,hi,a);
  seg[idx] = max(seg[2*idx],seg[2*idx+1]);
}

int query(int idx, int lo, int hi, int l, int r){
  if(l <= lo && hi <= r) return seg[idx];
  if(hi < l || r < lo) return INT_MIN;
  int mid = (lo+hi)/2;
  int left = query(2*idx,lo,mid,l,r);
  int right = query(2*idx+1,mid+1,hi,l,r);
  return max(left,right);
}

ll rec(int i, int j, int& n, vector<int>& a){
  if(i > j) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  int turn = n-(j-i);
  int sv = query(1,0,n-1,i,j);
  ll ans = rec(i+1,j,n,a)+sv+a[i]*1LL*turn;
  ans = max(ans,rec(i,j-1,n,a)+sv+a[j]*1LL*turn);
  return dp[i][j] = ans;
}

void solve(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin>>a[i];
  build(1,0,n-1,a);
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,n-1,n,a);
}

int main() {
  int t;
  cin>>t;
  while(t--){
    solve();
    if(t != 0) cout<<endl;
  }
}
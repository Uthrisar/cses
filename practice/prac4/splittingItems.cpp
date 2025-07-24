#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<numeric>
#include<cstring>
#include<algorithm>

#define endl '\n'
#define ff first
#define ss second
#define ll long long
#define pb emplace_back
#define pi pair<int,int>
#define vi vector<int>
#define mi map<int,int>
#define vv vector<vector<int>>
#define all(v) v.begin(),v.end()
#define maxHeap priority_queue<int>
#define minHeap priority_queue<int,vector<int>,greater<int>>

using namespace std;

const int mxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

void solve(){
	int n; ll k;
	cin >> n >> k;
	vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a));
    reverse(all(a));
    for(int i = 1; i < n; i += 2){
        ll diff = a[i-1]-a[i];
        if(k >= diff){
            a[i] += diff;
            k -= diff;
        } else {
            a[i] += k;
            break;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i&1) ans -= a[i];
        else ans += a[i];
    }
    cout << ans;
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
		if(i != t){
			cout << endl;
		}
	}
}
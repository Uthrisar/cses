#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> bit(200001);

int n;

ll sum(int ind){
    ll s = 0;
    while(ind){
        s += bit[ind];
        ind -= (ind&-ind);
    }
    return s;
}

void update(int ind, ll val){
    while(ind <= n){
        bit[ind] += val;
        ind += (ind&-ind);
    }
}

int main(){
    int q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        bit[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        update(i,a[i]);
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int k; ll u;
            cin >> k >> u;
            update(k,u-a[k]);
            a[k] = u;
        } else {
            int a,b;
            cin >> a >> b;
            ll ans = sum(b)-sum(a-1);
            cout << ans << endl;
        }
    }
}
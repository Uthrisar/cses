#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll r, c;
        cin >> r >> c;
        ll ans;
        if(r%2 == 0){
            if(c <= r){
                ans = r*r-(c-1);
            } else {
                if(c%2 == 0){
                    ans = (c-1)*(c-1)+1+(r-1);
                } else {
                    ans = c*c-(r-1);
                }
            }
        } else {
            ll sq = (r-1)*(r-1)+1;
            if(c <= r){
                ans = sq+(c-1);
            } else {
                if(c%2 == 0){
                    ans = (c-1)*(c-1)+1+(r-1);
                } else {
                    ans = c*c-(r-1);
                }
            }
        }
        cout << ans << endl;
    }
}
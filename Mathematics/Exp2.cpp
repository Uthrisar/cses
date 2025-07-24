#include <bits/stdc++.h>
using namespace std;

const int m = 1e9+7;

int binexp(int a, long long b, int m){
    int ans = 1;
    while(b > 0){
        if(b&1){
            ans = (ans*1LL*a)%m;
        }
        a = (a*1LL*a)%m;
        b /= 2;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<binexp(a, binexp(b, c, m-1), m)<<endl;
    }
}
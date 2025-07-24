#include <bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        long long n;
        vector<long long> v;
        cin>>n;
        long long st = 0;
        for(int i=0; i<n; i++){
            long long x;
            cin>>x;
            if(i == 0){
                st = x;
            }
        }
        sort(v.begin(), v.end());
        if(st == v[0]){
            cout<<st+(v[1]-st)/2<<endl;
        } else if(st == v[n-1]){
            cout<<1000000-st+1+(st-v[n-2])/2<<endl;
        } else {
            long long a = 0, b= 0;
            for(int i=0; i<n; i++){
                if(v[i] == st){
                    a = st-(st-v[i-1])/2;
                    b = st+(v[i+1]-st)/2;
                    break;
                }
            }
            cout<<b-a+1<<endl;
        }
    }
}
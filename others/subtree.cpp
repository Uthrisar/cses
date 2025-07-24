#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int mx_num = 1e6+1;
    vector<int> freq(mx_num,0);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        freq[x]++;
    }
    int mx_gcd1 = 1;
    for(int i = 2; i < mx_num; i++){
        if(freq[i]>1){
            mx_gcd1 = i;
        }
    }
    int mx_gcd = 1;
    int mx_gcd2 = 1;
    for(int i = 1; i < mx_num; i++){
        int ct = 0;
        for(int j = 2*i; j < mx_num; j += i){
            if(freq[i] && freq[j]){
                mx_gcd = i;
            }
            if(freq[j]){
                ct++;
            }
        }
        if(ct > 1){
            mx_gcd2 = i;
        }
    }
    mx_gcd = max(mx_gcd,max(mx_gcd1,mx_gcd2));
    cout<<mx_gcd<<"\n";
}
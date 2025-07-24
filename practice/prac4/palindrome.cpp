#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
int main(){
    string s;
    cin >> s;
    map<char,int> m;
    for(int i = 0; i < int(s.size()); i++){
        m[s[i]]++;
    }
    int oddCnt = 0;
    for(auto &pr: m){
        if(pr.ss&1){
            oddCnt++;
        }
    }
    if(oddCnt < 2){
        int n = int(s.size());
        int i = 0;
        for(auto & pr: m){
            int freq = pr.ss;
            for(; freq > 1; i++){
                s[i] = s[n-1-i] = pr.ff;
                freq -= 2;
            }
            if(freq&1){
                s[n/2] = pr.ff;
            }
        }
        cout << s;
    } else {
        cout << "NO SOLUTION";
    }
}
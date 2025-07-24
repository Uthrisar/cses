#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void wordC(int idx, string s, vector<string> &arr, int n, string curr){
    if(idx == n && curr.empty()) return;
    if(curr.size() > s.size()) return;
    if(curr.size() == s.size()){
       if(curr == s){
            ans++;
       }
    }
    wordC(1+(idx%n),s,arr,n,curr);
    curr += arr[idx];
    wordC(1+(idx%n),s,arr,n,curr);
}
int main(){
    string s; cin >> s;
    int n; cin >> n;
    vector<string> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    string curr;
    wordC(1,s,arr,n,curr);
    cout << ans <<"\n";
}
